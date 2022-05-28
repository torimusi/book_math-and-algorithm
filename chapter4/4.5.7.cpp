#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, A[200009], B[200009];
vector<int> G[200009];
int color[200009]; // 各頂点の色のリスト

// 深さ優先探索
// 隣接するマスのうち最小番号を現在マスと異なる色で塗る
// すでに塗られていれば何もしない
void dfs(int pos) {
    for (int i : G[pos]) { // AtCoderでは問題なく実行可能なのでエラー表示消去
        if (color[i] == 0) {
            // color[pos]=1の時 2, color[pos]=2の時 1
            color[i] = 3 - color[pos];
            dfs(i);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    // 深さ優先探索
    // 全てのマスに色を塗る
    for (int i = 1; i <= N; i++) color[i] = 0; // 初期化
    for (int i = 1; i <= N; i++) {
        if (color[i] == 0) {
            // 頂点 i がまだ塗られていなければ、そのマスを 1 として深さ優先探索
            // 深さ優先探索により、頂点iから連結している頂点は全て塗ることができる
            // 頂点iと連結していない部分はその部分内の初めてのiから塗っていく
            color[i] = 1;
            dfs(i);
        }
    }

    // 全て塗り終えてから判定
    // 「直接辺で結ばれている」頂点を塗り分けられれば良い → 各辺について判定すれば良い
    // 独立した頂点は無関係（二部グラフは二つに分けられたグループ内で辺がなければOK、連結性は条件ではない）
    bool isBipartite = true;
    for (int i = 1; i <= M; i++) {
        if (color[A[i]] == color[B[i]]) isBipartite = false; // 各辺について、結ぶ頂点が同色なら二部グラフでない
    }
    if (isBipartite == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}