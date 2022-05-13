#include <iostream>
using namespace std;

long long T, N, L[500009], R[500009];
// グローバルに定義するとゼロクリア、答えでは for (int i = 0; i <= T; i++) A[i] = 0; していた
long long A[500009]; // 従業員数の階差
long long B[500009]; // 従業員数の累積和

int main() {
    cin >> T;
    cin >> N;
    for (long long i = 1; i <= N; i++) cin >> L[i] >> R[i];

    // 従業員数の階差を求める
    for (long long i = 1; i <= N; i++) {
        A[L[i]] += 1;
        A[R[i]] -= 1;
    }

    // 従業員数の累積和を求める
    for (long long i = 0; i <= T - 1; i++) {
        if (i == 0) B[i] = A[i];
        else B[i] = B[i - 1] + A[i];
        cout << B[i] << endl;
    }

    return 0;
}