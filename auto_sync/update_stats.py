import datetime as dt
import json
import os
import urllib.parse
import urllib.request

HANDLE = "FXY_AC"
REPO_PATH = r"D:\MY_CODE\ACM"
README_PATH = os.path.join(REPO_PATH, "README.md")
ASSETS_DIR = os.path.join(REPO_PATH, "assets")
RATING_IMG = os.path.join(ASSETS_DIR, "cf_rating.svg")
SOLVED_IMG = os.path.join(ASSETS_DIR, "solve_count.svg")
BREAKDOWN_IMG = os.path.join(ASSETS_DIR, "solve_breakdown.svg")


def fetch_json(url):
    req = urllib.request.Request(url, headers={"User-Agent": "ACM-Stats-Updater"})
    with urllib.request.urlopen(req, timeout=20) as resp:
        return json.loads(resp.read().decode("utf-8", errors="ignore"))


def fetch_text(url):
    req = urllib.request.Request(url, headers={"User-Agent": "ACM-Stats-Updater"})
    with urllib.request.urlopen(req, timeout=20) as resp:
        return resp.read().decode("utf-8", errors="ignore")


def get_cf_rating_history(handle):
    try:
        data = fetch_json(
            f"https://codeforces.com/api/user.rating?handle={urllib.parse.quote(handle)}"
        )
        if data.get("status") != "OK":
            return []
        out = []
        for item in data.get("result", []):
            ts = item.get("ratingUpdateTimeSeconds", item.get("ratingUpdateTime", 0))
            date_str = dt.datetime.fromtimestamp(ts).strftime("%Y-%m-%d")
            out.append((date_str, int(item.get("newRating", 0))))
        return out
    except Exception:
        return []


def get_cf_solved_count(handle):
    try:
        data = fetch_json(
            f"https://codeforces.com/api/user.status?handle={urllib.parse.quote(handle)}"
        )
        if data.get("status") != "OK":
            return 0
        solved = set()
        for sub in data.get("result", []):
            if sub.get("verdict") != "OK":
                continue
            p = sub.get("problem", {})
            cid = p.get("contestId")
            idx = p.get("index")
            if cid is not None and idx is not None:
                solved.add((cid, idx))
        return len(solved)
    except Exception:
        return 0


def get_atcoder_solved_count(handle):
    try:
        data = fetch_json(
            f"https://kenkoooo.com/atcoder/atcoder-api/v3/user/ac_rank?user={urllib.parse.quote(handle)}"
        )
        if isinstance(data, dict):
            return int(data.get("count", 0))
        return 0
    except Exception:
        return 0


def get_nowcoder_solved_count(_handle):
    return 0


def get_luogu_solved_count(_handle):
    return 0


def get_platform_counts():
    counts = {}

    cf = get_cf_solved_count(HANDLE)
    if cf > 0:
        counts["Codeforces"] = cf

    ac = get_atcoder_solved_count(HANDLE)
    if ac > 0:
        counts["AtCoder"] = ac

    nc = get_nowcoder_solved_count(HANDLE)
    if nc > 0:
        counts["NowCoder"] = nc

    lg = get_luogu_solved_count(HANDLE)
    if lg > 0:
        counts["LuoGu"] = lg

    return counts


def build_total_series(total):
    today = dt.date.today()
    start = today - dt.timedelta(days=29)
    points = []
    for i in range(30):
        d = start + dt.timedelta(days=i)
        points.append((d.strftime("%Y-%m-%d"), total))
    return points


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

    platform_counts = get_platform_counts()
    total_solved = sum(platform_counts.values())
    solve_points = build_total_series(total_solved)
    breakdown = sorted(platform_counts.items(), key=lambda x: x[1], reverse=True)

    rating_points = get_cf_rating_history(HANDLE)

    render_line_svg(
        SOLVED_IMG,
        f"Solved Count (Platform API) - Total {total_solved}",
        "Solved",
        solve_points,
    )
    render_bar_svg(BREAKDOWN_IMG, "Solved Breakdown (Platform API)", breakdown)
    render_line_svg(RATING_IMG, "Codeforces Rating History", "Rating", rating_points)
    update_readme()

    print("Updated README and chart images from platform APIs.")


if __name__ == "__main__":
    main()
