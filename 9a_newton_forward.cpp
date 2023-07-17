#include <bits/stdc++.h>
using namespace std;

/**
 * /\f(x) = f(x+h) - f(x)
 * f(a+hu) = f(a) + u/1! * /\f(a) + u(u-1)/2! * /\^2f(a)...
 * a + hu = given
 * a = base
 * h = nextBase - base
 */
class NewtonsForwardInterpolationFormula {
   public:
    int n, value;
    int x[100];
    double y[100][100];
    double ans;

    NewtonsForwardInterpolationFormula() {
        cin >> n;
        for (int k = 0; k < n; k++) {
            cin >> x[k] >> y[k][0];
        }
        cin >> value;
    }

    double uFunction(double u, int n) {
        double value = u;
        for (int k = 1; k < n; k++) value = value * (u - k);
        return value;
    }

    int factorial(int n) {
        if (n) {
            return n * factorial(n - 1);
        } else
            return 1;
    }

    void solve() {
        for (int c = 1; c < n; c++) {
            for (int r = 0; r < n - c; r++) {
                y[r][c] = y[r + 1][c - 1] - y[r][c - 1];
            }
        }
        ans = y[0][0];
        double u = (value - x[0]) / (x[1] - x[0]);
        for (int k = 1; k < n; k++) {
            ans += (uFunction(u, k) * y[0][k]) / factorial(k);
        }
        cout << ans;
    }
};

int main() {
    NewtonsForwardInterpolationFormula x = NewtonsForwardInterpolationFormula();
    x.solve();
}