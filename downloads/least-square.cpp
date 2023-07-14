#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double myFunc(double x) {
    return 2.0 * sin(x) + 0.5;
}

struct Point {
    double x, y;
};

void leastSquaresFit(const vector<Point>& data, double& a, double& b) {
    double sumX = 0.0, sumY = 0.0, sumXX = 0.0, sumXY = 0.0;
    for ( auto& p : data) {
        sumX += p.x;
        sumY += p.y;
        sumXX += p.x * p.x;
        sumXY += p.x * p.y;
    }
    int n = data.size();
    a = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
    b = (sumY - a * sumX) / n;
}

int main() {
    vector<Point> data;
    for (double x = 0.0; x < 10.0; x += 0.1) {
        double y = myFunc(x);
        // Add some noise to the data points
        y += ((double)rand() / RAND_MAX - 0.5) * 0.5;
        data.push_back({x, y});
    }

    double a, b;
    leastSquaresFit(data, a, b);
    cout << "Fitted function: y = " << a << " * x + " << b << endl;

    return 0;
}







#include <bits/stdc++.h>

using namespace std;

class LeastSquareCurveFitting {
private:
    int size;
    int x[100], y[100];
public:
    double a, b;

    LeastSquareCurveFitting() {
        cin >> size;
        for (int k = 0; k < size; k++) {
            cin >> x[k] >> y[k];
        }
    }
    
    void solve() {
        double xSum = 0, ySum = 0, xySum = 0, xSquare = 0;
        for (int k = 0; k < size; k++) {
            xSum += x[k];
            ySum += y[k];
            xSquare += x[k] * x[k];
            xySum += x[k] * y[k];
        }
        a = (size * xySum) - (xSum * ySum);
        a /= (size * xSquare) - (xSum * xSum);
        b = (ySum - a * xSum) / size;
        cout << fixed << showpoint;
        cout << setprecision(1);
        cout << "Y = " << a << " * X + " << b << "\n";
    }
};

int main() {
    LeastSquareCurveFitting x = LeastSquareCurveFitting();
    x.solve();
}