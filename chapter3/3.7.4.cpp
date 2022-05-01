// 動的計画法を用いてO(NW)で解く

#include <iostream>
#include <algorithm> // なぜいるのかはわからない（なくても正解だった）
using namespace std;

int N, S, A[10009];
bool dp[69][10009];

int main() {
    cin >> N >> S;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // 配列の初期化
    dp[0][0] = true;
    for (int j = 1; j <= S; j++) dp[0][j] = false;

    // 動的計画法
    // dp[i][j] : i番目までのカード（A[1] ~ A[i]）から、合計がjとなるように選べるか
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            // j < A[i] の時、カードiは選べない
            // これがないと下でdp[i - 1][j - A[i]]を調べられない
            if (j < A[i]) dp[i][j] = dp[i - 1][j];
            // j >= A[i] の時、選ぶ・選ばない 両方の選択肢がある
            // dp[i - 1][j] == true → i-1までで合計値jとなるように選ぶことができ、A[i]を選ばない
            // dp[i - 1][j - A[i]] == true → i-1までで合計値がちょうどA[i]分だけ足りず、A[i]を選べば良い
            if (j >= A[i]) {
                if (dp[i - 1][j] == true || dp[i - 1][j - A[i]] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    }

    if (dp[N][S] == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}