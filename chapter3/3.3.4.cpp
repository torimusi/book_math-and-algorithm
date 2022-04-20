#include <iostream>
using namespace std;

int main() {
    long long N;
    long long A[200000];

    cin >> N;
    for (long long i = 1; i <= N; i++) cin >> A[i];

    // nC2は計算量膨大
    // 100 + 400, 200 + 300をそれぞれ出して足す

    // 100 + 400の時
    long long acnt = 0;
    long long dcnt = 0;
    for (long long i = 1; i <= N; i++) {
        if (A[i] == 100) acnt++;
        if (A[i] == 400) dcnt++;
    }

    // 200 + 300の時
    long long bcnt = 0;
    long long ccnt = 0;
    for (long long i = 1; i <= N; i++) {
        if (A[i] == 200) bcnt++;
        if (A[i] == 300) ccnt++;
    }

    cout << acnt * dcnt + bcnt * ccnt << endl;
    return 0;
}