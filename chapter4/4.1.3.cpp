#include <iostream>
#include <cmath>
using namespace std;

// intだと間違い
// y1 はベッセル関数（？）で使われているらしい
double X1, Y1, R1, X2, Y2, R2;

int main() {
    cin >> X1 >> Y1 >> R1;
    cin >> X2 >> Y2 >> R2;

    double distance = sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));

    // 出力は "1" でも良い
    if (distance - abs(R1 - R2) < 0) cout << 1 << endl;
    else if (distance - abs(R1 - R2) == 0) cout << 2 << endl;
    else if (distance - abs(R1 + R2) < 0)  cout << 3 << endl;
    else if (distance - abs(R1 + R2) == 0) cout << 4 << endl;
    else if (distance - abs(R1 + R2) > 0)  cout << 5 << endl;   // else のみでも可
    return 0;
}