#include <iostream>
#include <algorithm>
using namespace std;

long long N;
long long A[100009];

/* 2数の最小公倍数を求める */
long long LCM(long long a, long long b) {
    long long A = a;
    long long B = b;
    
    //2数の最大公約数を求める
    while (a >= 1 && b >= 1) {
        if (b > a) b = b % a;
        else a = a % b;
    }
    long long GCD;
    if (a >= 1) GCD = a;
    else GCD = b;

    //2数の積を最大公約数で割る
    //return A * B / GCD; こちらだと不正解
    return (A / GCD) * B;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    long long temp = LCM(A[1], A[2]);
    for (int j = 3; j <= N; j++) {
        temp = LCM(temp, A[j]);
    }

    cout << temp << endl;
    return 0;
}