#include <iostream>
#include <cmath>
using namespace std;

int N;
double x[2009], y[2009];
double ans = 1000000000.0; // 非常に大きい値に初期化

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];

    // 全探索
    // iはNまででも良いらしい
    // N + 1番目には何も入っていないと大丈夫？
    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            ans = min(ans, sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i])));
        }
    }

    printf("%.12lf\n", ans);
    return 0;
}