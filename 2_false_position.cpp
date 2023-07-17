#include <bits/stdc++.h>

using namespace std;
/*
 * c = (a * f(b) - b * f(a)) / (f(b) - f(a))
 */
class FalsePositionMethod {
   private:
    double epsilon = 0.001;
    double a, b;

    double f(double x) {
        return x * x * x + x * x - 1;
    }

   public:
    void solve() {
        srand(time(NULL));
        while (true) {
            a = -(rand() % 100);
            b = rand() % 100;
            if (f(a) * f(b) <= 0) {
                break;
            }
        }

        if (a > b) {
            swap(a, b);
        }

        double c;
        while (true) {
            c = (a * f(b) - b * f(a)) / (f(b) - f(a));
            if (f(c) == 0.0 || abs(f(c)) < epsilon) {
                break;
            }
            if (f(c) * f(a) < 0) {
                b = c;
            } else {
                a = c;
            }
        }
        cout << setprecision(10);
        cout << "The root is " << c << "\n";
    }
};

int main() {
    FalsePositionMethod x = FalsePositionMethod();
    x.solve();
    return 0;
}