#include <iostream>
#include <algorithm>
using namespace std;

long long N;
long long A[100009];

/* 2数の最大公約数を求める */
long long GCD (long a, long b){
    while (a >= 1 && b >= 1) {
        if (a < b) b = b % a;
        else a = a % b;
    }
    if (a >= 1) return a;
    else return b;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    
    long long temp = GCD(A[1], A[2]);
    for (int j = 3; j <= N; j++) {
        temp = GCD(A[j], temp);
    }

    cout << temp << endl;
    return 0;
}