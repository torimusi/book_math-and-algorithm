#include <iostream>
using namespace std;

const long long mod = 1000000007;

struct Matrix {
    long long p[2][2] = { {0, 0}, {0, 0} };
};

// 2 * 2 行列 A, B の積を返す関数
Matrix Multiplication(Matrix A, Matrix B) {
    Matrix C;
    for (int i = 0; i < 2; i++) {
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < 2; j++) {
                C.p[i][j] += A.p[i][k] * B.p[k][j];
                C.p[i][j] %= mod;
            }
        }
    }
    return C;
}

// A の n 乗を返す関数
Matrix Power(Matrix A, long long n) {
    Matrix P = A, Q;
    bool flag = false;
    for (int i = 0; i < 60; i++) {
        if ((n & (1LL << i)) != 0LL) {
            if (flag == false) { // Q の初期値を 1（スカラー）と置けないため？初めに必要な A ^ i で置く
                Q = P;
                flag = true;
            } else {
                Q = Multiplication(Q, P);
            }
        }
        P = Multiplication(P, P);
    }
    return Q;
}

int main() {
    long long N;
    cin >> N;

    // 累乗の計算
    Matrix A;
    A.p[0][0] = 2; A.p[0][1] = 1; A.p[1][0] = 1; // 2 * 2 の行列の(0, 0)成分を2にすれば良い
    Matrix B = Power(A, N - 1);

    cout << (B.p[1][0] + B.p[1][1]) % mod << endl;
    return 0;
}