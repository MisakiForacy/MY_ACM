import datetime as dt
import json
import os
import re
import urllib.parse
import urllib.request
import http.cookiejar

REPO_PATH = r"D:\MY_CODE\ACM"
README_PATH = os.path.join(REPO_PATH, "README.md")
ASSETS_DIR = os.path.join(REPO_PATH, "assets")
CONFIG_PATH = os.path.join(REPO_PATH, "auto_sync", "platform_handles.json")

SOLVED_IMG = os.path.join(ASSETS_DIR, "solve_count.svg")
BREAKDOWN_IMG = os.path.join(ASSETS_DIR, "solve_breakdown.svg")
RATING_IMG = os.path.join(ASSETS_DIR, "cf_rating.svg")


def opener_with_cookie():
    jar = http.cookiejar.CookieJar()
    return urllib.request.build_opener(urllib.request.HTTPCookieProcessor(jar))


def fetch_json(url, headers=None, op=None):
    h = {"User-Agent": "Mozilla/5.0"}
    if headers:
        h.update(headers)
    req = urllib.request.Request(url, headers=h)
    open_func = op.open if op is not None else urllib.request.urlopen
    with open_func(req, timeout=30) as resp:
        return json.loads(resp.read().decode("utf-8", errors="ignore"))


def fetch_text(url, headers=None, op=None):
    h = {"User-Agent": "Mozilla/5.0"}
    if headers:
        h.update(headers)
    req = urllib.request.Request(url, headers=h)
    open_func = op.open if op is not None else urllib.request.urlopen
    with open_func(req, timeout=30) as resp:
        return resp.read().decode("utf-8", errors="ignore")


def load_handles():
    default_cfg = {
        "codeforces": "FXY_AC",
        "atcoder": "Foracy",
        "nowcoder": "",
        "luogu": "",
    }
    if not os.path.exists(CONFIG_PATH):
        with open(CONFIG_PATH, "w", encoding="utf-8") as f:
            json.dump(default_cfg, f, ensure_ascii=False, indent=2)
        return default_cfg
    try:
        with open(CONFIG_PATH, "r", encoding="utf-8") as f:
            cfg = json.load(f)
        for k, v in default_cfg.items():
            cfg.setdefault(k, v)
        return cfg
    except Exception:
        return default_cfg


def cf_solve_events(handle):
    if not handle:
        return []
    try:
        data = fetch_json(
            f"https://codeforces.com/api/user.status?handle={urllib.parse.quote(handle)}"
        )
        if data.get("status") != "OK":
            return []
        first_ac = {}
        for sub in data.get("result", []):
            if sub.get("verdict") != "OK":
                continue
            p = sub.get("problem", {})
            pid = f"{p.get('contestId', 'x')}-{p.get('index', 'x')}"
            ts = int(sub.get("creationTimeSeconds", 0))
            if ts <= 0:
                continue
            old = first_ac.get(pid)
            if old is None or ts < old:
                first_ac[pid] = ts
        return [
            (dt.datetime.fromtimestamp(ts).date().isoformat(), "Codeforces")
            for ts in first_ac.values()
        ]
    except Exception:
        return []


def atcoder_solve_events(handle):
    if not handle:
        return []
    api_candidates = [
        "https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions",
        "https://atcoder-problems.herokuapp.com/atcoder-api/v3/user/submissions",
    ]
    for base in api_candidates:
        try:
            data = fetch_json(
                f"{base}?user={urllib.parse.quote(handle)}&from_second=0",
                headers={
                    "Referer": "https://atcoder.jp/",
                    "Origin": "https://atcoder.jp",
                },
            )
            if not isinstance(data, list):
                continue
            first_ac = {}
            for sub in data:
                if sub.get("result") != "AC":
                    continue
                pid = sub.get("problem_id")
                ts = int(sub.get("epoch_second", 0))
                if not pid or ts <= 0:
                    continue
                old = first_ac.get(pid)
                if old is None or ts < old:
                    first_ac[pid] = ts
            if first_ac:
                return [
                    (dt.datetime.fromtimestamp(ts).date().isoformat(), "AtCoder")
                    for ts in first_ac.values()
                ]
        except Exception:
            continue

    # Page scraping fallback mode
    try:
        profile = fetch_text(
            f"https://atcoder.jp/users/{urllib.parse.quote(handle)}?lang=en"
        )
        # Parse rating_history points as timeline anchors (contest dates)
        m_hist = re.search(
            r"var\s+rating_history\s*=\s*(\[.*?\]);", profile, flags=re.S
        )
        anchors = []
        if m_hist:
            arr = json.loads(m_hist.group(1))
            for it in arr:
                ts = int(it.get("EndTime", 0))
                if ts > 0:
                    anchors.append(dt.datetime.fromtimestamp(ts).date().isoformat())
        if not anchors:
            return []

        # Approximate AC total by visible contest history count is not reliable.
        # For stable timeline contribution in page mode, use one event per contest anchor.
        return [(d, "AtCoder") for d in anchors]
    except Exception:
        return []


def nowcoder_solve_events(profile_url):
    if not profile_url:
        return [], 0
    try:
        m = re.search(r"/profile/(\d+)", profile_url)
        if not m:
            return [], 0
        uid = m.group(1)
        url = f"https://ac.nowcoder.com/acm/contest/profile/{uid}/practice-coding"
        html = fetch_text(url)

        def parse_ac_rows(page_html):
            rows = re.findall(r"<tr>(.*?)</tr>", page_html, flags=re.S)
            out = []
            for row in rows:
                if "答案正确" not in row:
                    continue
                pid_m = re.search(r"/acm/problem/(\d+)", row)
                tm = re.search(r"(20\d\d-\d\d-\d\d)\s+\d\d:\d\d:\d\d", row)
                if pid_m and tm:
                    out.append((pid_m.group(1), tm.group(1)))
            return out

        all_rows = parse_ac_rows(html)

        total_pages = 1
        p_m = re.search(r'<ul[^>]*data-total="(\d+)"', html)
        if p_m:
            total_pages = max(1, int(p_m.group(1)))
        total_pages = min(total_pages, 300)

        for p in range(2, total_pages + 1):
            page_url = (
                f"{url}?&pageSize=50&search=&statusTypeFilter=-1&"
                f"languageCategoryFilter=-1&orderType=DESC&page={p}"
            )
            page_html = fetch_text(page_url)
            rows = parse_ac_rows(page_html)
            if not rows:
                continue
            all_rows.extend(rows)

        first_ac = {}
        for pid, d in all_rows:
            old = first_ac.get(pid)
            if old is None or d < old:
                first_ac[pid] = d

        events = [(d, "NowCoder") for d in first_ac.values()]

        # Dedup by date+problem in visible page is unavailable; keep by date only for timeline contribution.
        # For total solved count we trust page summary below.
        cnt = 0
        m_cnt = re.search(
            r"<span>题已通过</span>\s*</div>\s*</div>\s*<div class=\"my-state-item\"[^>]*>\s*<div class=\"state-num\">(\d+)</div>",
            html,
        )
        if m_cnt:
            cnt = int(m_cnt.group(1))
        else:
            m_cnt2 = re.search(
                r"<div class=\"state-num\">(\d+)</div>\s*<span>题已通过</span>", html
            )
            if m_cnt2:
                cnt = int(m_cnt2.group(1))

        return events, cnt
    except Exception:
        return [], 0


def luogu_solve_events(user_url):
    if not user_url:
        return [], 0
    try:
        m = re.search(r"/user/(\d+)", user_url)
        if not m:
            return [], 0
        uid = m.group(1)
        op = opener_with_cookie()
        html = fetch_text(
            f"https://www.luogu.com.cn/user/{uid}",
            headers={"Referer": "https://www.luogu.com.cn/"},
            op=op,
        )

        ctx_m = re.search(
            r'<script id="lentille-context" type="application/json">(.*?)</script>',
            html,
            flags=re.S,
        )
        if not ctx_m:
            return [], 0
        ctx = json.loads(ctx_m.group(1))
        data = ctx.get("data", {})
        user = data.get("user", {})

        passed = int(user.get("passedProblemCount", 0))

        events = []
        daily = data.get("dailyCounts", {})
        if isinstance(daily, dict):
            for d, arr in daily.items():
                if isinstance(arr, list) and arr:
                    ac = int(arr[0])
                    for _ in range(max(0, ac)):
                        events.append((d, "LuoGu"))
        return events, passed
    except Exception:
        return [], 0


def cf_rating_history(handle):
    if not handle:
        return []
    try:
        data = fetch_json(
            f"https://codeforces.com/api/user.rating?handle={urllib.parse.quote(handle)}"
        )
        if data.get("status") != "OK":
            return []
        out = []
        for item in data.get("result", []):
            ts = int(
                item.get("ratingUpdateTimeSeconds", item.get("ratingUpdateTime", 0))
            )
            if ts <= 0:
                continue
            out.append(
                (
                    dt.datetime.fromtimestamp(ts).date().isoformat(),
                    int(item.get("newRating", 0)),
                )
            )
        return out
    except Exception:
        return []


def build_total_series(events):
    if not events:
        return []
    daily = {}
    for d, _ in events:
        daily[d] = daily.get(d, 0) + 1
    start = dt.date.fromisoformat(min(daily.keys()))
    end = dt.date.today()
    out = []
    cur = 0
    day = start
    while day <= end:
        key = day.isoformat()
        cur += daily.get(key, 0)
        out.append((key, cur))
        day += dt.timedelta(days=1)
    return out


def platform_breakdown_from_totals(totals):
    items = [(k, v) for k, v in totals.items() if v > 0]
    return sorted(items, key=lambda x: x[1], reverse=True)


def align_events_with_total(events, total, platform):
    if total <= 0:
        return []
    if len(events) >= total:
        return events
    if events:
        first_day = min(d for d, _ in events)
    else:
        first_day = dt.date.today().isoformat()
    missing = total - len(events)
    padded = list(events)
    for _ in range(missing):
        padded.append((first_day, platform))
    return padded


def render_line_svg(path, title, y_label, points, line_color="#e24a33"):
    width, height = 1200, 520
    left, right, top, bottom = 90, 40, 80, 70
    cw = width - left - right
    ch = height - top - bottom

    if not points:
        content = (
            f"<svg xmlns='http://www.w3.org/2000/svg' width='{width}' height='{height}'>"
            "<rect width='100%' height='100%' fill='#ececec'/>"
            f"<text x='50%' y='50%' text-anchor='middle' fill='#333' font-size='24'>{title}: no data</text>"
            "</svg>"
        )
        with open(path, "w", encoding="utf-8") as f:
            f.write(content)
        return

    ys = [v for _, v in points]
    ymin, ymax = min(ys), max(ys)
    if ymin == ymax:
        ymin -= 1
        ymax += 1

    def x_map(i):
        return left + (i / max(1, len(points) - 1)) * cw

    def y_map(v):
        return top + (1 - (v - ymin) / (ymax - ymin)) * ch

    poly = " ".join(f"{x_map(i):.2f},{y_map(v):.2f}" for i, v in enumerate(ys))

    ticks = 5
    y_ticks = []
    for i in range(ticks + 1):
        v = ymin + (ymax - ymin) * i / ticks
        y = y_map(v)
        y_ticks.append((v, y))

    x_labels = []
    count = min(6, len(points))
    for i in range(count):
        idx = round(i * (len(points) - 1) / max(1, count - 1))
        x_labels.append((idx, points[idx][0]))

    parts = [
        f"<svg xmlns='http://www.w3.org/2000/svg' width='{width}' height='{height}'>",
        "<rect width='100%' height='100%' fill='#ececec'/>",
        f"<text x='50%' y='44' text-anchor='middle' fill='#222' font-size='34' font-family='Comic Sans MS, Segoe UI'>{title}</text>",
        f"<line x1='{left}' y1='{top + ch}' x2='{left + cw}' y2='{top + ch}' stroke='#111' stroke-width='4'/>",
        f"<line x1='{left}' y1='{top}' x2='{left}' y2='{top + ch}' stroke='#111' stroke-width='4'/>",
    ]

    for v, y in y_ticks:
        parts.append(
            f"<line x1='{left}' y1='{y:.2f}' x2='{left + cw}' y2='{y:.2f}' stroke='#d7d7d7' stroke-width='1'/>"
        )
        parts.append(
            f"<text x='{left - 10}' y='{y + 5:.2f}' text-anchor='end' fill='#333' font-size='14'>{int(round(v))}</text>"
        )

    for idx, label in x_labels:
        x = x_map(idx)
        parts.append(
            f"<line x1='{x:.2f}' y1='{top + ch}' x2='{x:.2f}' y2='{top + ch + 6}' stroke='#111' stroke-width='2'/>"
        )
        parts.append(
            f"<text x='{x:.2f}' y='{top + ch + 28}' text-anchor='middle' fill='#333' font-size='14'>{label}</text>"
        )

    parts.extend(
        [
            f"<polyline fill='none' stroke='{line_color}' stroke-width='4' points='{poly}'/>",
            f"<text x='50%' y='{height - 18}' text-anchor='middle' fill='#333' font-size='18'>Date</text>",
            f"<text x='26' y='{top + ch / 2:.2f}' transform='rotate(-90 26 {top + ch / 2:.2f})' text-anchor='middle' fill='#333' font-size='18'>{y_label}</text>",
            "</svg>",
        ]
    )

    with open(path, "w", encoding="utf-8") as f:
        f.write("\n".join(parts))


def render_bar_svg(path, title, items):
    width, height = 1200, 620
    left, right, top, bottom = 220, 40, 80, 40
    cw = width - left - right
    ch = height - top - bottom

    if not items:
        content = (
            f"<svg xmlns='http://www.w3.org/2000/svg' width='{width}' height='{height}'>"
            "<rect width='100%' height='100%' fill='#ececec'/>"
            f"<text x='50%' y='50%' text-anchor='middle' fill='#333' font-size='24'>{title}: no data</text>"
            "</svg>"
        )
        with open(path, "w", encoding="utf-8") as f:
            f.write(content)
        return

    max_v = max(v for _, v in items)
    bar_h = ch / len(items) * 0.7
    gap = ch / len(items)

    parts = [
        f"<svg xmlns='http://www.w3.org/2000/svg' width='{width}' height='{height}'>",
        "<rect width='100%' height='100%' fill='#ececec'/>",
        f"<text x='50%' y='44' text-anchor='middle' fill='#222' font-size='34' font-family='Comic Sans MS, Segoe UI'>{title}</text>",
    ]

    for i, (name, val) in enumerate(items):
        y = top + i * gap
        w = 0 if max_v == 0 else (val / max_v) * cw
        parts.append(
            f"<text x='{left - 12}' y='{y + bar_h * 0.8:.2f}' text-anchor='end' fill='#333' font-size='16'>{name}</text>"
        )
        parts.append(
            f"<rect x='{left}' y='{y:.2f}' width='{w:.2f}' height='{bar_h:.2f}' fill='#e24a33' opacity='0.85'/>"
        )
        parts.append(
            f"<text x='{left + w + 8:.2f}' y='{y + bar_h * 0.8:.2f}' fill='#222' font-size='15'>{val}</text>"
        )

    parts.append("</svg>")
    with open(path, "w", encoding="utf-8") as f:
        f.write("\n".join(parts))


def update_readme():
    content = """# MY_ACM
![Solved Count Trend](assets/solve_count.svg)
![Solved Platform Breakdown](assets/solve_breakdown.svg)
![Codeforces Rating Curve](assets/cf_rating.svg)
"""
    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(content)


def main():
    os.makedirs(ASSETS_DIR, exist_ok=True)
    handles = load_handles()

    events = []
    totals = {"Codeforces": 0, "AtCoder": 0, "NowCoder": 0, "LuoGu": 0}

    cf_ev = cf_solve_events(handles.get("codeforces", ""))
    cf_ev = align_events_with_total(cf_ev, len(cf_ev), "Codeforces")
    events.extend(cf_ev)
    totals["Codeforces"] = len(cf_ev)

    ac_ev = atcoder_solve_events(handles.get("atcoder", ""))
    ac_ev = align_events_with_total(ac_ev, len(ac_ev), "AtCoder")
    events.extend(ac_ev)
    totals["AtCoder"] = len(ac_ev)

    nc_ev, nc_total = nowcoder_solve_events(handles.get("nowcoder", ""))
    nc_ev = align_events_with_total(nc_ev, nc_total, "NowCoder")
    events.extend(nc_ev)
    totals["NowCoder"] = nc_total

    lg_ev, lg_total = luogu_solve_events(handles.get("luogu", ""))
    lg_ev = align_events_with_total(lg_ev, lg_total, "LuoGu")
    events.extend(lg_ev)
    totals["LuoGu"] = lg_total

    total_series = build_total_series(events)
    breakdown = platform_breakdown_from_totals(totals)

    cf_rating = cf_rating_history(handles.get("codeforces", ""))

    total_num = sum(v for _, v in breakdown)
    render_line_svg(
        SOLVED_IMG,
        f"Total Solved Over Time (All Platforms) - {total_num}",
        "Solved",
        total_series,
    )
    render_bar_svg(BREAKDOWN_IMG, "Solved Breakdown by Platform", breakdown)
    render_line_svg(RATING_IMG, "Codeforces Rating History", "Rating", cf_rating)
    update_readme()

    print("Updated README and chart images (all-platform timeline).")


if __name__ == "__main__":
    main()
