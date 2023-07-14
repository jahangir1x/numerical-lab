#include<bits/stdc++.h>
using namespace std;

class NewtonForwarrdInterpolation{
public:
    int n, at;
    int x[100];
    double y[100][100];
    double ans;

    NewtonForwarrdInterpolation(){
        cin >> n;
        for(int k = 0; k < n; k++)
        {
            cin >> x[k] << y[k][0];
        }
        cin >> at;
    }

    double proTerm(double n){
        double value = 1;
        for(int k = 0; k < n; k++)
        {
            value = value * (at - x[k]);
        }
        return value;
    }    

    void solve(){
        for(int c = 1; c < n; c++)
        {
            for(int r = 0; r < n - c; r++)
            {
                y[r][c] = (y[r + 1][c - 1] - y[r][c - 1]) / (x[r + c] - x[r]);
            }
        }

        double ans = y[0][0];
        for(int k = 1; k < n; k++)
        {
            ans += proTerm(k) * y[0][k];
        }
        cout << ans;
    }
};

int main(){
    NewtonForwarrdInterpolation x = NewtonForwarrdInterpolation();
    x.solve();
}