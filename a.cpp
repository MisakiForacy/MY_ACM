if (a[i - 1][j - 1] == -1) tot ++;
if (a[i - 1][j] == -1) tot ++;
if (a[i - 1][j + 1] == -1) tot ++;
if (a[i][j - 1] == -1) tot ++;
if (a[i][j + 1] == -1) tot ++;
if (a[i + 1][j - 1] == -1) tot ++;
if (a[i + 1][j] == -1) tot ++;
if (a[i + 1][j + 1] == -1) tot ++;

for (int dx = -1;dx <= 1;dx ++) {
    for (int dy = -1;dy <= 1;dy ++) {
        if (dx == 0 && dy == 0) continue;
        if (a[i + dx][j + dy] == -1) {
            tot ++;
        }  
    }
}

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
for (int k = 0;k < 8;k ++) {
    int nx = i + dx[k];
    int ny = j + dy[k];
    if (a[nx][ny] == -1) tot ++;
}