#include <iostream>
#include <vector>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009]; // G[i] は頂点iに隣接する頂点のリスト

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]); // 頂点 A[i] に隣接する頂点として B[i] を追加
        G[B[i]].push_back(A[i]); // 頂点 B[i] に隣接する頂点として A[i] を追加
    }

    // 自分自身より頂点番号が小さい隣接頂点がちょうど1つ存在する頂点の数を出力する
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        // G[i].size()は頂点 i に隣接する頂点のリストの大きさ
        for (int j = 0; j < G[i].size(); j++) {
            // G[i][j] は頂点 i に隣接している頂点のうち j 番目
            if (G[i][j] < i) cnt++;
        }
        if (cnt == 1) ans++;
    }

    cout << ans << endl;
    return 0;
}