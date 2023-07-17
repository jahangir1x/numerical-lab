#include <bits/stdc++.h>
using namespace std;

class BisectionMethod {
   private:
    double epsilon = 0.001;
    double lower, upper;

    double f(double x) {
        return x * x * x + x * x - 1;
        // return (x * x) + (5 * x) + 6;
    }

   public:
    void solve() {
        srand(time(NULL));
        while (true) {
            lower = -rand();
            upper = rand();
            if (f(lower) * f(upper) < 0) {
                break;
            }
        }

        if (lower > upper) {
            swap(lower, upper);
        }

        double root;
        while (true) {
            root = (lower + upper) / 2;
            if (f(root) == 0.0 || abs(f(root)) < epsilon) {
                break;
            }
            if (f(root) * f(lower) < 0) {
                upper = root;
            } else {
                lower = root;
            }
        }
        cout << setprecision(10);
        cout << "The root is " << root << "\n";
    }
};

int main() {
    BisectionMethod bisectionMethod = BisectionMethod();
    bisectionMethod.solve();
}