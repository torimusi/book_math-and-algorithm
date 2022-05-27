#include <iostream>
#include <vector>
using namespace std;

int N, M, A[200009], B[200009];
vector<int> G[200009];
int C[200009]; // 各頂点の色のリスト

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    // 各頂点の色のリストの初期化
    // 白色：1、黒色：-1、未確定：0
    for(int i = 1; i <= N; i++) C[i] = 0;

    // 順に色を塗っていく
    // 隣接するマスに現在マスと違う色を塗る
    // 隣接するマスがすでに現在マスと同じ色が塗られている場合、二部グラフでない
    bool isBipartite = true;
    int judge = 1; // 色の判定
    for (int i = 1; i <= N; i++) {
        C[i] = judge; // このタイミングで色の判定必要？
        for (int j = 0; j < G[i].size; j++) {
            if (C[G[i][j]] == judge) {
                isBipartite = false;
                break;
            }
            C[G[i][j]] = -1 * judge; // 現在マスと同色でなければ、すでに塗られていても無色でももう一方の色で塗れば良い
        }
        judge = -1 * judge;
    }

    if (isBipartite == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}