#include <iostream>
using namespace std;

int X, Y;
const long long mod = 1000000007;

// 繰り返し二乗法
// a^b を mで割った余りを求める
long long modpow(long long a, long long b, long long m) {
    long long p = a, Answer = 1;
    for (int i = 0; i < 30; i++) { // b の値は制約から2^30未満
        if ((b & (1 << i)) != 0) { // b を2進数表記した時、2^iの位が1となる場合
            Answer *= p; // a^i をかける
            Answer %= m; // mod で割っておく
        }
        p *= p; // p は a^1, a^2, a^4, a^8, ... といった値を取る
        p %= m; // modで割っておく
    }
    return Answer;
}

// a÷b mod m を返す関数
// modは素数より、モジュラ逆数はb^(mod-2)をmodで割った余り
// a÷b(mod 1000000007) は a * b^1000000005(mod 1000000007)に等しい
long long Division(long long a, long long b, long long m) {
    return (a * modpow(b, m - 2, m)) % m;
}

int main() {
    cin >> X >> Y;

    // 場合分け
    // a, bが負になってしまう場合（移動可能な扇状の外側）
    if (2 * Y - X < 0 || 2 * X - Y < 0) {
        cout << "0" << endl;
        return 0;
    }
    // a, bが整数にならない場合（移動可能な扇状の間の移動不可能なマス）
    if ((2 * Y - X) % 3 != 0 || (2 * X - Y) % 3 != 0) {
        cout << "0" << endl;
        return 0;
    }

    // 二項係数の分子と分母を求める
    // 圧縮して考えると、ナイトの移動も右または下に一マス移動するのと等価
    // 移動単位をa, bに圧縮してX, Yまでの移動回数を考える（Combination(a+b, b)）
    long long bunshi = 1, bunbo = 1;
    long long a = (2 * Y - X) / 3, b = (2 * X - Y) / 3; 
    for (int i = 1; i <= a + b; i++) { bunshi *= i; bunshi %= mod; }
    for (int i = 1; i <= a; i++) { bunbo *= i; bunbo %= mod; }
    for (int i = 1; i <= b; i++) { bunbo *= i; bunbo %= mod; }

    cout << Division(bunshi, bunbo, mod) << endl;
    return 0;
}