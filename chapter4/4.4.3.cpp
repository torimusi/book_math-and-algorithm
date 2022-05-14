#include <iostream>
using namespace std;

// 正整数の約数の個数を求める
int divisors(int K) {
    int sum = 0;
    for (int i = 1; i * i <= K; i++) {
        if (K % i == 0) {
            sum ++;
            if (i * i != K) sum++;
        }
    }
    return sum;
}

// 計算時間超過
// エラトステネスのふるいの利用？
int isDivisors(int K) {
    bool divisors[K];
    for (int i = 1; i <= K; i++) divisors[i - 1] = false;
    for (int i = 1; i <= K; i ++) {
        
    }
}

// 素因酢分解すれば個数は簡単に求まる？

int main() {
    int N;
    cin >> N;

    // 与関数の計算
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += i * divisors(i);
    }

    cout << ans << endl;
    return 0;
}