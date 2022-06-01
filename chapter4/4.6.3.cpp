#include <iostream>
using namespace std;

const long long mod = 1000000007;
long long N;

// a^b を mで割った余りを求める
long long modpow(long long a, long long b, long long m) {
    long long p = a, Answer = 1;
    for (int i = 0; i < 30; i++) {
        if((b & (1 << i)) != 0) {
            Answer *= p;
            Answer %= m; 
        }
        p *= p;
        p %= m;
    }
    return Answer;
}

int main() {
    cin >> N;

    // 足し算する前に毎回割るとN回余りの計算必要
    // modpow を N回回してみる → 時間超過
    long long sum = 0;
    for (long long i = 0; i <= N; i++) {
        sum += modpow(4, i, mod);
        sum %= mod; 
    }

    cout << sum << endl;
    return 0;
}