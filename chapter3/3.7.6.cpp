#include <iostream>
#include <algorithm>
using namespace std;

long long N, A[500009];
long long S[500009]; // i日目までの実力の最大値

int main() {
    cin >> N;
    for (long long i = 1; i <= N; i++) cin >> A[i];

    for (long long i = 1; i <= N; i++) {
        if (i == 1) S[i] = A[i];
        if (i == 2) S[i] = max(A[i - 1], A[i]);
        if (i >= 3) S[i] = max(S[i - 2] + A[i], S[i - 1]);
    }

    cout << S[N] << endl;
    return 0;
}