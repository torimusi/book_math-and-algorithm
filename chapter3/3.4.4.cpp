#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    double ans = 0;

    for (int i = 1; i <= N; i++) {
        ans += 1.0 * N / i; // 1.0かけるとキャストされるらしい
    }

    // cout << ans << endl; だとエラー
    //浮動小数点数の出力方法
    printf("%.12lf\n", ans);
    return 0;
}