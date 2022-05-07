#include <iostream>
#include <cmath>
using namespace std;

// pi はある程度の長さで置く
const double pi = 3.14159265358979;

int main() {
    double A, B, H, M;
    cin >> A >> B >> H >> M;

    // 中心角を求める
    // H は M分 分回っている
    // double の計算では .0 忘れない
    double arg = abs(360.0 / 12.0 * H + 30.0 / 60.0 * M - 360.0 / 60.0 * M);
    if (arg > 180.0) arg = 360.0 - arg;
    arg = 2.0 * pi / 360.0 * arg;   // c++のcosの引数はラジアン

    // 余弦定理で2本の針の先端の距離を求める
    double ans = sqrt(A * A + B * B - 2 * A * B * cos(arg));

    printf("%.12lf\n", ans);
    return 0;
}