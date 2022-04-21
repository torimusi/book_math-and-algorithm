#include <iostream>
using namespace std;

int main() {
    long long N;
    int A[500000];
    cin >> N;
    for (long long i = 1; i <= N; i++) cin >> A[i];

    long long acnt = 0;
    long long bcnt = 0;
    long long ccnt = 0;
    for (long long i = 1; i <= N; i++) {
        if (A[i] == 1) acnt++;
        if (A[i] == 2) bcnt++;
        if (A[i] == 3) ccnt++;
    }

    // long long は整数型のため先に2で割ってはならない
    // 2で割っても桁数はさほど変わらないので順番は気にする必要なし
    cout << acnt * (acnt - 1) / 2 + bcnt * (bcnt - 1) / 2 + ccnt * (ccnt - 1) / 2 << endl;
    return 0;
}