#include <bits/stdc++.h>
using namespace std;

/**
 * 1 / 3 Iatobf(x)dx =  h/3[(y0-yn) + 4(y1+y3...)    + 2(y2+y4...)]  even num of intervals
 * 1 / 8 Iatobf(x)dx = 3h/8[(y0-yn) + 3(y1+y2+y4...) + 2(y3+y6...)]  3's multiple
 */
class SimpsonsRule {
   private:
    double lower, upper, grids;
    double gridSpacing;

    double function(double x) {
        return 1 / (1 + x * x);
    }

   public:
    double answer;

    SimpsonsRule(double a, double b, double n) {
        lower = a;
        upper = b;
        grids = n;
    }

    void solve() {
        gridSpacing = (upper - lower) / grids;
        answer = function(lower) + function(upper);
        for (int k = 1; k < grids; k++) {
            if (k % 2 == 0) {
                answer += 2 * function(lower + k * gridSpacing);
            } else
                answer += 4 * function(lower + k * gridSpacing);
        }
        answer = (gridSpacing / 3) * answer;
        cout << answer;
    }
};

int main() {
    SimpsonsRule x = SimpsonsRule(0, 1, 10);
    x.solve();
    return 0;
}