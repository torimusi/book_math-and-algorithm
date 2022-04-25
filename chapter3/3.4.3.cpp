#include <iostream>
using namespace std;

long long N;
double A[200009], B[200009];

int main() {
    cin >> N;
    for (long long i = 1; i <= N; i++) cin >> A[i];
    for (long long i = 1; i <= N; i++) cin >> B[i];

    double ans = 0;
    for (long long i = 1; i <= N; i++) {
        ans += A[i] / 3 + B[i] / 3 * 2;
    } 
    cout << ans << endl;
    return 0;
}