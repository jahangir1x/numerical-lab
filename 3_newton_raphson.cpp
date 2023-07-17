#include <bits/stdc++.h>
using namespace std;

/*
 * Xn+1 = Xn - (f(Xn) / df(Xn))
 */
class NewtonRaphson {
   private:
    double epsilon = 0.0001;
    double dEpsilon = 0.00001;
    int total_steps = 100;
    double f(double x) {  // original polynomial
        return (x * x * x + x * x - 1);
    }

    double df(double x) {  // derivative function
        return (f(x + dEpsilon) - f(x)) / dEpsilon;
    }

   public:
    void solve() {
        srand(time(NULL));

        double previousRoot;

        while (true) {
            previousRoot = -(RAND_MAX / 2) + rand();
            if (df(previousRoot) != 0) {
                break;
            }
        }

        double root;
        int step = 0;
        while (true) {
            root = previousRoot - (f(previousRoot) / df(previousRoot));  // finding the new root

            printf("Iteration: %3d : x: %15.8lf f(x): %12.8lf\n", ++step, root, f(root));
            
            if (f(root) == 0.0 || abs(f(root)) < epsilon) {
                break;
            }


            previousRoot = root;

            if (step > total_steps) {
                cout << "non convergent.." << endl;
                return;
            }
        }

        cout << "the value of the root is: " << root << endl;
    }
};

int main() {
    NewtonRaphson newtonRaphson = NewtonRaphson();

    newtonRaphson.solve();

    return 0;
}