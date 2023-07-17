#include <bits/stdc++.h>
using namespace std;

/**
 * Yn+1 = Yn + hf(Xn, Yn)
*/
class Euler {
   public:
    double function(double x, double y) {
        return x + y;
    }

    void solve() {
        cout << "Initial Condition\n\n"
             << endl;

        double x0, y0, xn, n;
        cout << "Enter x0: ";
        cin >> x0;
        cout << "Enter y0: ";
        cin >> y0;

        cout << "Enter xn: ";
        cin >> xn;

        cout << "Enter number of steps: ";
        cin >> n;

        // step size
        double h = (xn + x0) / n;
        double yn;
        for (int i = 0; i < n; i++) {
            double slope = function(x0, y0);
            double yi = y0 + h * slope;
            cout << "Step " << i + 1 << ": value of x0 = " << x0 << "    value of y0 = " << y0 << "    slope = " << slope << "    value of yn = " << yi << endl;
            y0 = yi;
            x0 = x0 + h;
            if (i == n - 1) {
                yn = yi;
            }
        }

        cout << "value of y(" << xn << ") = " << yn << endl;
    }
};

int main() {
    Euler euler;

    euler.solve();

    return 0;
}