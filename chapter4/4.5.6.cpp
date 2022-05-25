#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 入力
int H, W; // グラフの縦・横
int sy, sx, start;
int gy, gx, goal;
char c[59][59];

// グラフ・最短経路
int dist[2509]; // 各マスからゴール地点までの最短経路
vector<int> G[2509]; // G[i] は頂点iに隣接する頂点のリスト

int main() {
    cin >> H >> W;
    cin >> sx >> sy; start = sx * W + sy; // スタート地点をマス番号で表現
    cin >> gx >> gy; goal = gx * W + gy; // ゴール地点をマス番号で表現
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) cin >> c[i][j];
    }

    // 横方向の辺 [(i, j) - (i, j+1)] をグラフに追加
    // 最短手数なら迷路が90度回転しても同じ（？）
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W - 1; j++) { // 一つ右の辺をグラフに追加するため、横軸はW-1まで
            int idx1 = i * W + j; // 頂点 (i, j) の頂点番号
            int idx2 = i * W + (j + 1); // 頂点 (i, j+1) の頂点番号
            if (c[i][j] == '.' && c[i][j+1] == '.') { // 頂点がどちらも空きマスならそれらを結ぶ辺を追加
                G[idx1].push_back(idx2);
                G[idx2].push_back(idx1);
            }
        }
    }

    // 縦方向の辺 [(i, j) - (i+1, j)] をグラフに追加
    for (int i = 1; i <= H - 1; i++) { // 一つ下の辺をグラフに追加するため、縦軸はH-1まで
        for (int j = 1; j <= W; j++) {
            int idx1 = i * W + j; // 頂点 (i, j) の頂点番号
            int idx2 = (i + 1) * W + j; // 頂点 (i+1, j) の頂点番号
            if (c[i][j] == '.' && c[i+1][j] == '.') {
                G[idx1].push_back(idx2);
                G[idx2].push_back(idx1);
            }
        }
    }

    // 幅優先探索の初期化（dist[i]=-1の時、未到達の白色頂点）
    for (int i = 1; i <= H * W; i++) dist[i] = -1;
    queue<int> Q; // キュー Q を定義
    Q.push(start); dist[start] = 0; // Q に 1 を追加

    // 幅優先探索
    while (!Q.empty()) { // Qにpushされなければ（次のマスの最短経路が白色でなければ）終了
        int pos = Q.front(); // Q の先頭を調べる
        Q.pop(); // Q の先頭を取り出す
        for (int i = 0; i < (int)G[pos].size(); i++) { // Qの先頭のマスに隣接するマス全ての最短経路を+1する
            int nex = G[pos][i];
            if (dist[nex] == -1) {
                dist[nex] = dist[pos] + 1;
                Q.push(nex); // Q に nex を追加、隣接するマス全てpushする
            }
        }
    }

    cout << dist[goal] << endl;
    return 0;
}