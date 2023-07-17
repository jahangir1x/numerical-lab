#include <bits/stdc++.h>
using namespace std;
/*
 * Xn+1 = (Xn-1 * f(Xn) - Xn * f(Xn-1)) / (f(Xn) - f(Xn-1))
 */
class Secant {
   private:
    const double epsilon = 0.0001;

    double f(double x) {
        // return (x * x * exp(-(x / 2)) - 1);
        return (x * x * x + x * x - 1);
    }

   public:
    void solve() {
        double a, b;
        srand(time(NULL));
        while (true) {
            a = -(rand() % 100);
            b = rand() % 100;
            if (f(a) * f(b) < 0) {
                break;
            }
        }

        double root;

        while (true) {
            root = (b * f(a) - a * f(b)) / (f(a) - f(b));

            printf("a: %15.8lf root: %15.8lf b: %15.8lf\n", a, root, b);

            if (f(root) == 0 || abs(f(root)) < epsilon) {
                break;
            }

            a = b;
            b = root;
        }
        cout << "\n\nThe root is : " << root << endl;
    }
};

int main() {
    Secant secant;

    secant.solve();

    return 0;
}