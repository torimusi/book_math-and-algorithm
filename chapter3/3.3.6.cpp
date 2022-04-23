#include <iostream>
using namespace std;

long long N, A[200009];
long long ans = 0; 
long long cnt[100009]; //1 ~ 99999までの数の個数を入れる配列

int main() {
    cin >> N;
    for (long long i = 1; i <= N; i++) cin >> A[i];

    // 1 ~ 99999までの個数を数える
    for (int i = 1; i <= 99999; i++) cnt[i] = 0;
	for (int i = 1; i <= N; i++) cnt[A[i]] += 1;

    // 1 + 99999, 2 + 99998 ... のそれぞれ個数を求める
    for (int i = 1; i <= 49999; i++) {
		ans += cnt[i] * cnt[100000 - i];
	}
	ans += cnt[50000] * (cnt[50000] - 1) / 2;

    cout << ans << endl;
    return 0;
}