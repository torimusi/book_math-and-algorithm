#include <iostream>
#include <algorithm>
using namespace std;

int X, Y;
const long long mod = 1000000007;

int main() {
    cin X >> Y;

    // ナイトは(0, 0)からスタート
    // 移動は(i + 1, j + 1) or (i + 2, j + 1)のみ
    // 場合の数をまず求める
    // 計算途中で1000000007で割ってオーバーフローを防ぐ

    long long ans;

    // ナイトが移動できるか
    if (X + Y >= 5 && (X + Y) % 3 == 2 && min(X, Y) >= (X + Y) / 3 + 1) {
        // 移動できる場合、場合の数を求める
        
    } else ans = 0;

    cout << ans << endl;
    return 0;
}