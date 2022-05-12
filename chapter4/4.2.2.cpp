#include <iostream>
using namespace std;

long long T, N, L[500009], R[500009];
long long A[500009]; // 従業員数の階差、グローバルに定義するとゼロクリア
long long B[500009];

int main() {
    cin >> T;
    cin >> N;
    for (long long i = 1; i <= T; i++) cin >> L[i] >> R[i];

    // 従業員数の階差を求める
    for (long long i = 1; i <= N; i++) {
        A[L[i]] += 1;
        A[R[i]] -= 1;
    }

    // 従業員数の累積和を求める
    B[0] = 0; // ゼロクリアされているはずだが一応＆わかりやすく
    for (long long i = 1; i <= T - 1; i++) {
        B[i] = B[i - 1] + A[i];
    }

    for (long long i = 1; i <= T - 1; i++) cout << B[i] << endl;
    return 0;
}