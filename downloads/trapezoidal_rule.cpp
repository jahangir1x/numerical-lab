#include<bits/stdc++.h>
using namespace std;

class Trapezoidal{
private:
    double lower, upper, grids, gridspacing;

    double func(double x){
        return 1 / (1 + x * x);
    }

public:
    double answer;

    Trapezoidal(double a, double b, double n){
        lower = a;
        upper = b;
        grids = n;
    }

    void solve(){
        gridspacing = (upper - lower) / grids;
        answer = func(lower) + func(upper);

        for(int k = 1; k < grids; k++)
        {
            answer += 2 * func(lower + k * gridspacing);
        }
        answer = (gridspacing / 2) * answer;
        cout << answer;
    }
};

int main(){
    Trapezoidal x = Trapezoidal(0, 6, 6);
    x.solve();
}