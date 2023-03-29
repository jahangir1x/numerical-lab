#include <bits/stdc++.h>
using namespace std;

class NewtonBackward {
   private:
    vector<double> x;
    vector<vector<double>> y;

    double calcU(double u, int n) {
        double temp = u;
        for (int i = 1; i < n; i++)
            temp = temp * (u + i);
        return temp;
    }

    // Calculating factorial of given n
    int factorial(int n) {
        int f = 1;
        for (int i = 2; i <= n; i++)
            f *= i;
        return f;
    }

   public:
    NewtonBackward(vector<double> _x, vector<double> _y) {
        x = _x;
        y.resize(_y.size(), vector<double>(_y.size(), 0));
        for (int i = 0; i < _y.size(); i++) {
            y[i][0] = _y[i];
        }
    }

    double interpolateAt(double value) {
        int n = x.size();

        for (int i = 1; i < n; i++) {
            for (int j = n - 1; j >= i; j--)
                y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }

        // Displaying the backward difference table
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++)
                cout << setw(4) << y[i][j]
                     << "\t";
            cout << endl;
        }

        // Initializing u and sum
        float sum = y[n - 1][0];
        float u = (value - x[n - 1]) / (x[1] - x[0]);
        for (int i = 1; i < n; i++) {
            sum = sum + (calcU(u, i) * y[n - 1][i]) /
                            factorial(i);
        }

        return sum;
    }
};

int main() {
    vector<double> x = {1891, 1901, 1911, 1921, 1931};
    vector<double> y = {46, 66, 81, 93, 101};

    NewtonBackward newtonBackward(x, y);
    cout << newtonBackward.interpolateAt(1925) << endl;

    return 0;
}