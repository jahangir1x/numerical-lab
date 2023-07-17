#include <bits/stdc++.h>
using namespace std;
/*
 * y = a + bx
 * ySum = a * size + b * xSum
 * xySum = a * xSum + b * xSquareSum
 */
class LeastSquareCurveFitting {
   private:
    int size;
    double x[100], y[100];

   public:
    double a, b;

    LeastSquareCurveFitting() {
        cin >> size;
        for (int k = 0; k < size; k++) {
            cin >> x[k] >> y[k];
        }
    }

    void solve() {
        double xSum = 0, ySum = 0, xySum = 0, xSquareSum = 0;
        for (int k = 0; k < size; k++) {
            xSum += x[k];
            ySum += y[k];
            xSquareSum += x[k] * x[k];
            xySum += x[k] * y[k];
        }
        b = (size * xySum) - (xSum * ySum);
        b /= (size * xSquareSum) - (xSum * xSum);
        a = (ySum - b * xSum) / size;
        printf("Y = %lf + %lfX\n", a, b);
    }
};

int main() {
    LeastSquareCurveFitting leastSquareCurveFitting = LeastSquareCurveFitting();
    leastSquareCurveFitting.solve();
}