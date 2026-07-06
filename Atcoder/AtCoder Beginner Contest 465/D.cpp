#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

void solve() {

    cout << !0 + 1 << '\n';

    LL x, y, k;
    cin >> x >> y >> k;
    LL cnt = 0;
    LL X = x, Y = y;
    LL cnt1 = 0, cnt2 = 0;
    while (X) {
        X /= k;
        cnt1 ++;
    }
    while (Y) {
        Y /= k;
        cnt2 ++;
    }
    if (cnt1 > cnt2) swap(cnt1, cnt2), swap(x, y);
    while (cnt1 < cnt2) {
        y /= k;
        cnt2 --;
        cnt ++;
    }
    while (x != y) {
        x /= k;
        y /= k;
        cnt += 2;
    }
    cout << cnt << '\n';
}

int main() {
    cout << (~0 + 1) << '\n';
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}


cat > ~/camera_server.py << 'EOF'
import json, base64, http.server, socketserver, subprocess, os, sys

HOME = os.path.expanduser("~")
PHOTO = f"{HOME}/capture.jpg"
PORT = 8765

class H(http.server.BaseHTTPRequestHandler):
    def log_message(self, *a): pass
    def do_GET(self):
        if self.path == "/photo":
            if os.path.exists(PHOTO): os.remove(PHOTO)
            r = subprocess.run(["termux-camera-photo", "-c", "0", PHOTO],
                            capture_output=True, text=True, timeout=10)
            if not os.path.exists(PHOTO) or os.path.getsize(PHOTO) < 100:
                self.send_error(500, "Camera failed")
                return
            with open(PHOTO, "rb") as f:
                img = f.read()
            b64 = base64.b64encode(img).decode()
            resp = json.dumps({"image": b64, "size": len(img)}).encode()
            self.send_response(200)
            self.send_header("Content-Type", "application/json")
            self.send_header("Content-Length", str(len(resp)))
            self.end_headers()
            self.wfile.write(resp)
        elif self.path == "/ping":
            self.send_response(200); self.end_headers()
            self.wfile.write(b"ok")

sys.stdout.reconfigure(encoding='utf-8')
socketserver.ThreadingTCPServer.allow_reuse_address = True
srv = socketserver.ThreadingTCPServer(("0.0.0.0", PORT), H)
print(f"Camera server: http://10.236.19.233:{PORT}")
print("Endpoints: /ping  /photo")
try:
    srv.serve_forever()
except KeyboardInterrupt:
    srv.shutdown()
EOF