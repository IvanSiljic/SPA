#include "iostream"

using namespace std;

struct Matrix {
public:
    long long list[2][2] = {{1, 1},
                      {1, 0}
    };
    Matrix operator*=(const Matrix& Mat)
    {
        long long a1 = list[0][0] * Mat.list[0][0] + list[0][1] * Mat.list[1][0];
        long long a2 = list[0][0] * Mat.list[1][0] + list[0][1] * Mat.list[1][1];;
        long long b1 = list[1][0] * Mat.list[0][0] + list[1][1] * Mat.list[1][0];
        long long b2 = list[1][0] * Mat.list[0][1] + list[1][1] * Mat.list[1][1];
        list[0][0] = a1;
        list[0][1] = a2;
        list[1][0] = b1;
        list[1][1] = b2;
        return *this;
    }
};

Matrix matPow(Matrix A, int n, int i) {
    if (n == 0) {
        Matrix R;
        R.list[0][1] = 0;
        R.list[1][0] = 0;
        R.list[1][1] = 1;
        return R;
    } else if (n%2 == 0) {
        Matrix A, B;
        B = matPow(A, n/2, ++i);
        B*=B;
        return B;
    } else {
        Matrix A, B;
        B = matPow(A, (n-1)/2, ++i);
        B *= B;
        B *= A;
        return B;
    }
}

long long fib(int n) {
    Matrix A;
    return matPow(A, n, 0).list[0][1];
}

int main() {
    int n;

    cin >> n;

    while (n != -1) {
        cout << n << ". fibonacci number: " << fib(n) << endl;
        cin >> n;
    }

    return 0;
}