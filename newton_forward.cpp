#include <bits/stdc++.h>
using namespace std;

class NewtonForward {
   private:
    vector<double> x;
    vector<vector<double>> y;
    
    double calcU(double u, int n) {
        double temp = u;
        for (int i = 1; i < n; i++)
            temp = temp * (u - i);
        return temp;
    }

    int factorial(int n) {
        int f = 1;
        for (int i = 2; i <= n; i++)
            f *= i;
        return f;
    }

   public:
    NewtonForward(vector<double> _x, vector<double> _y) {
        x = _x;
        y.resize(_y.size(), vector<double>(_y.size(), 0));
        for (int i = 0; i < _y.size(); i++) {
            y[i][0] = _y[i];
        }
    }

    double interpolateAt(double value) {
        int n = x.size();

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++)
                y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }

        // Displaying the forward difference table
        for (int i = 0; i < n; i++) {
            cout << setw(4) << x[i]
                 << "\t";
            for (int j = 0; j < n - i; j++)
                cout << setw(4) << y[i][j]
                     << "\t";
            cout << endl;
        }

        // initializing u and sum
        float sum = y[0][0];
        float u = (value - x[0]) / (x[1] - x[0]);
        for (int i = 1; i < n; i++) {
            sum = sum + (calcU(u, i) * y[0][i]) /
                            factorial(i);
        }

        return sum;
    }
};

int main() {
    vector<double> x = {45, 50, 55, 60};
    vector<double> y = {0.7071, 0.7660, 0.8192, 0.8660};

    NewtonForward newtonForward(x, y);
    cout << newtonForward.interpolateAt(52) << endl;

    return 0;
}
