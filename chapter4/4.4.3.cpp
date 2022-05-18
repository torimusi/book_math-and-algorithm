#include <iostream>
using namespace std;

/*

// 素直に計算すると時間超過
// 素数だけあらかじめ分ける？ → 間違いは無くなったが変わらず時間超過
// ２倍は約数が一つ増えることを利用？

// 素数か否かを判定
bool prime[10000009];

// 正整数の約数の個数を求める
long long divisors(long long K) {
    long long sum = 0;
    for (long long i = 1; i * i <= K; i++) {
        if (K % i == 0) {
            sum ++;
            if (i * i != K) sum++;
        }
    }
    return sum;
}

*/

long long N;
long long F[10000009];
long long ans = 0;

int main() {

    /*
    // N以下の素数を全て出力する
    prime[1] = false;
    for (int i = 2; i <= N; i++) prime[i] = true;
    for (int i = 2; i * i <= N; i ++) {
        if (prime[i] == true) {
            for (int j = 2 * i; j <= N; j += i) prime[j] = false;
        }
    }

    // 与関数の計算
    long long ans = 0;
    for (long long i = 1; i <= N; i++) {
        // i が素数なら約数は2個
        if (prime[i == true]) ans += i * 2;
        else ans += i * divisors(i);
    }

    */

    // 入力、配列の初期化
    cin >> N;
    for (int i = 1; i <= N; i++) F[i] = 0;

    // 約数の個数を計算する
    // 約数 → 〇〇で割れる → 倍数が存在するごとに1加算
    for (int i = 1; i <= N; i++) {
        // F[i], F[2i], F[3i], ... に 1 を加算
        for (int j = i; j <= N; j += i) F[j] += 1;
    }

    // 答えを求める
    // 1LLはlong long型の1、なくても正解だったが、オーバーフローを防ぐため？
    for (int i = 1; i <= N; i++) {
        ans += 1LL * i * F[i];
    }

    cout << ans << endl;
    return 0;
}