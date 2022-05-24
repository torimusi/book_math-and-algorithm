#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int R, C;
int sy, sx;
int gy, gx;
string c[59][59];
int restmove[59][59]; // 最短手数
int py, px; // 現在地

int main() {
    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) cin >> c[i][j];
    }

    // マスの最短手数に大きい数を入れて初期化
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) restmove[i][j] = 3000;
    }

    // マスの最短手数を確定する
    restmove[sy][sx] = 0;
    py = sy, px = sx;
    while (py != gy || px != px) {
        if (c[py + 1][px + 1] == ".") restmove[sy + 1][sx + 1] = min(restmove[sy + 1][sx + 1], restmove[sy][sx] + 1);
        if (c[py + 1][px - 1] == ".") restmove[sy + 1][sx + 1] = min(restmove[sy + 1][sx + 1], restmove[sy][sx] + 1);
        if (c[py - 1][px + 1] == ".") restmove[sy + 1][sx + 1] = min(restmove[sy + 1][sx + 1], restmove[sy][sx] + 1);
        if (c[py - 1][px - 1] == ".") restmove[sy + 1][sx + 1] = min(restmove[sy + 1][sx + 1], restmove[sy][sx] + 1);
        // 現在地の更新
    }

    return 0;
}