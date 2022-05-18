#include <iostream>
#include <vector>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009] // G[i] は頂点iに隣接する頂点のリスト

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]); // 頂点 A[i] に隣接する頂点として B[i] を追加
        G[B[i]].push_back(A[i]); // 頂点 B[i] に隣接する頂点として A[i] を追加
    }

    return 0;
}