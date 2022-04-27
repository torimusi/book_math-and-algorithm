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

}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    //マージソート→答えの出力
    MergeSort(1, N + 1);
    for (int i = 1; i <= N; i++) cout << A[i] << endl;
    return 0;
}