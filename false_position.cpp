#include <bits/stdc++.h>
using namespace std;
#define MAX_ITER 1000000
#define EPS 1e-4

class FalsePosition {
   private:
    double func(double x) {
        return x * x * x - x * x + 2;
    }

   public:
    pair<double, int> guess(double a, double b, double tolerance) {
        if (func(a) * func(b) > 0) {
            return {-1, -1};
        }
        double c = a;
        int iterationCount = 0;
        while (abs(func(c)) > tolerance) {
            c = (a * func(b) - b * func(a)) / (func(b) - func(a));
            if (func(a) * func(c) < 0) {
                b = c;
            } else {
                a = c;
            }
            iterationCount++;
        }
        return {c, iterationCount};
    }
};

int main() {
    srand(time(NULL));
    FalsePosition falsePosition;
    pair<double, int> answer = {-1, -1};
    while (answer.second == -1) {
        answer = falsePosition.guess(-rand(), rand(), 0.001);
    }
    cout << answer.first << " " << answer.second << endl;
    return 0;
}
