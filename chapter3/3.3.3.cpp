#include <iostream>
using namespace std;

int main() {
    int n;
    int r;

    cin >> n;
    cin >> r;

    // int だと一部不正解
    long pron = 1;
    long pror = 1;
    long diff = 1;

    for (int i = 1; i <= n; i++) pron = pron * i;
    for (int i = 1; i <= r; i++) pror = pror * i;
    for (int i = 1; i <= n - r; i++) diff = diff * i;

    if (diff == 0) cout << 1 << endl;
    else cout << pron / pror / diff << endl;
    return 0;
}