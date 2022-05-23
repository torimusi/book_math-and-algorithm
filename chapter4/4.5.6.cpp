#include <iostream>
#include <vector>
using namespace std;

int R, C;
int sy, sx;
int gy, gx;
string c[59][59];
int restmove[59][59];

int main() {
    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) cin >> c[i][j];
    }

    // マスの最短手数を確定する
    restmove[sy][sx] = 0;

    // 空きマスかの判定
    if (一つ前のマス+-1 == ".") restmove[][] = 一つ前 + 1;

    return 0;
}