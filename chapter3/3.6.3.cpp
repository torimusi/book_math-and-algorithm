#include <iostream>
using namespace std;

int N, A[200009], C[200009];

// A[l], A[l+1], ..., A[r-1] を小さい順に整列する関数
void MergeSort(int l, int r) {
    // r-l=1 の場合、すでにソートされているので何もしない
    if (r - l == 1) return;

    // 2つに分割した後、小さい配列をソート
    int m = (l + r) / 2;
    MergeSort(l, m);
    MergeSort(m, r);

    // この時点で以下2つの配列がソート済み
    // 列A'に相当するもの [A[l], A[l+1], ..., A[m-1]]
    // 列B'に相当するもの [A[m], A[m+1], ..., A[r-1]]

    // Merge操作
    int c1 = l, c2 = m, cnt = 0;
    while (c1 != m || c2 != r) {
        if (c1 == m) {
            // 列A'が空の場合
            C[cnt] = A[c2]; c2++;
        } else if (c2 == r) {
            // 列B'が空の場合
            C[cnt] = A[c1]; c1++;
        } else {
            // いずれでもない場合
            if (A[c1] < A[c2]) {
                C[cnt] = A[c1]; c1++;
            } else {
                C[cnt] = A[c2]; c2++;
            }
        }
        cnt++;
    }

    // 列A', 列B'を合併した配列CをAに移す
    // [C[0], ..., C[cnt-1] -> [A[l], ..., A[r-1]]]
    for (int i = 0; i < cnt; i++) A[l + i] = C[i];
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // マージソート→答えの出力
    // c2 == r のためにN+1を入れている？（数値が入るのはA[r-1]まで）
    MergeSort(1, N + 1);
    for (int i = 1; i <= N; i++) cout << A[i] << endl;
    return 0;
}