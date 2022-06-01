#include <iostream>
using namespace std;

const long long mod = 1000000007;
long long N;

// a^b を mで割った余りを求める
long long modpow(long long a, long long b, long long m) {
    long long p = a, Answer = 1;
    for (int = 1; i <= 30; i++) {
        if(b & (1 << 18) != 0) {
            Answer *= p;
            Answer %= m; 
        }
        p *= p;
        m %= m;
    }
}

int main() {
    cin >> N;

    // 足し算する前に毎回割るとN回余りの計算必要
    // 

    return 0;
}