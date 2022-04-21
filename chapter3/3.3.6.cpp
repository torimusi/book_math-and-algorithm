#include <iostream>
using namespace std;

long long N, A[200009];
long long ans = 0; 

int main() {
    cin >> N;
    for (long long i = 1; i <= N; i++) cin >> A[i];

    for (long long i = 1; i <= N; i++) {
        for (long long j = 1; j <= N; j++) {
            if (A[i] + A[j] == 100000) ans++; 
        }
    }

    cout << ans << endl;
    return 0;
}