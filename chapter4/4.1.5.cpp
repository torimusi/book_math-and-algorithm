#include <iostream>
using namespace std;

double X1, Y1, X2, Y2, X3, Y3, X4, Y4;
double s, t;

int main() {
    cin >> X1 >> Y1; // A
    cin >> X2 >> Y2; // B
    cin >> X3 >> Y3; // C
    cin >> X4 >> Y4; // D

    // 交差判定
    // vec(CD) = s * vec(CA) + t * vec(CB)
    // s >= 0 && t >= 0 && s + t >= 1
    double CDx = (X4 - X3), CDy = (Y4 - Y3);
    double CAx = (X1 - X3), CAy = (Y1 - Y3);
    double CBx = (X2 - X3), CBy = (Y2 - Y3);

    // 連立方程式から s, t 求める
    // 分母 0 の場合は交点を持つ？ → 一直線上だが交点持たないパターンあり → コーナーケースは別で考える必要あり
    bool flag = false;
    if ((CAx * CBy - CAy * CBx) == 0 || (CBx * CAy - CBy * CAx) == 0) {
        flag = true;
    } else {
        double s = (CDx * CBy - CDy * CBx) / (CAx * CBy - CAy * CBx);
        double t = (CDx * CAy - CDy * CAx) / (CBx * CAy - CBy * CAx);
    }

    if (flag == true) cout << "Yes" << endl;
    else if (s >= 0 && t >= 0 && s + t >= 1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}