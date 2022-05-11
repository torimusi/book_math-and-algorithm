#include <iostream>
using namespace std;

long long N, M, A[200009], B[200009];   // 計算にlong longが登場するならintもキャストされる

int main() {
    cin >> N;
    for (long long i = 1; i <= N - 1; i++) cin >> A[i];
    cin >> M;
    for (long long i = 1; i <= M; i++) cin >> B[i];

    // i番目の駅までの距離の累積和の配列
    long long C[200009];
    C[1] = 0;
    for (long long i = 2; i <= N; i++) {
        C[i] = C[i - 1] + A[i - 1];
    }

    // 移動距離の和を求める
    long long ans = 0;
    long long distance;
    for (long long i = 2; i <= M; i++) {
        distance = C[B[i]] - C[B[i - 1]];
        if (distance < 0) distance = distance * (-1);
        ans = ans + distance;
    }
    
    cout << ans << endl;
    return 0;
}