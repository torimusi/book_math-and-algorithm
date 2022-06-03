#include <iostream>
using namespace std;

const long long mod = 1000000007;
long long N;

// a^b を m で割った余りを求める
long long modpow(long long a, long long b, long long m) {
    long long p = a, Answer = 1;
    for (int i = 0; i < 60; i++) { // 2 ^ 30 では不十分
        if((b & (1LL << i)) != 0) { // 1 を long long型で定義しないと不正解
            Answer *= p;
            Answer %= m; 
        }
        p *= p;
        p %= m;
    }
    return Answer;
}

// a÷b を m で割った余りを求める
long long Division(long long a, long long b, long long m) {
    return (a * modpow(b, m - 2, m)) % m;
}

int main() {
    cin >> N;

    /*
    // 足し算する前に毎回割るとN回余りの計算必要
    // modpow を N回回してみる → 時間超過
    long long sum = 0;
    for (long long i = 0; i <= N; i++) {
        sum += modpow(4, i, mod);
        sum %= mod; 
    }
    */

   // 初項 1, 公比 4, 項数 N + 1 の等比数列の和は (4 ^ (N + 1) - 1) / 3 で求められる
   long long V = modpow(4, N + 1, mod) - 1;
   long long Answer = Division(V, 3, mod);

    cout << Answer << endl;
    return 0;
}