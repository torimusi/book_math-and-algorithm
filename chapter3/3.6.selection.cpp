#include <iostream>
using namespace std;

int N, A[200009];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    for (int i = 1; i <= N - 1; i++) {
        int Min = i, Min_Value = A[i];
        for (int j = i + 1; j <= N; j++) {
            if (A[j] < Min_Value) {
                Min = j;
                Min_Value = A[j];
            }
        }
        swap(A[i], A[Min]);
    }

    for (int i = 1; i <= N; i++) cout << A[i] << endl;
    return 0;
}