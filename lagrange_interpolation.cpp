#include <bits/stdc++.h>
using namespace std;

class LagrangeInterpolation {
   private:
    vector<double> x;
    vector<double> y;

   public:
    LagrangeInterpolation(vector<double> _x, vector<double> _y) {
        x = _x;
        y = _y;
    }

    // function to interpolate the given data points using Lagrange's formula
    // xi corresponds to the new data point whose value is to be obtained
    // n represents the number of known data points
    double interpolateAt(int value) {
        int n = x.size();
        double result = 0;  // Initialize result

        for (int i = 0; i < n; i++) {
            // Compute individual terms of above formula
            double term = y[i];
            for (int j = 0; j < n; j++) {
                if (j != i)
                    term = term * (value - x[j]) / double(x[i] - x[j]);
            }

            // Add current term to result
            result += term;
        }

        return result;
    }
};

// driver function to check the program
int main() {
    vector<double> x = {0, 1, 2, 5};
    vector<double> y = {2, 3, 12, 147};

    LagrangeInterpolation lagrangeInterpolation(x, y);
    cout << lagrangeInterpolation.interpolateAt(3) << endl;

    return 0;
}
