#include <bits/stdc++.h>
using namespace std;

class LagrangeInterpolation {
   private:
    vector<double> x;
    vector<double> y;

   public:
    LagrangeInterpolation(vector<double> x, vector<double> y) {
        this->x = x;
        this->y = y;
    }

    double interpolateAt(int value) {
        int n = x.size();
        double result = 0;  

        for (int i = 0; i < n; i++) {
            double term = y[i];
            for (int j = 0; j < n; j++) {
                if (j != i)
                    term = term * (value - x[j]) / double(x[i] - x[j]);
            }
            result += term;
        }

        return result;
    }
};

int main() {
    vector<double> x = {0, 1, 2, 5, 6};
    vector<double> y = {2, 3, 12, 147, 160};

    LagrangeInterpolation lagrangeInterpolation(x, y);
    cout << "The value is: " << lagrangeInterpolation.interpolateAt(5) << endl;

    return 0;
}

class LagrangeInterpolation{
private:
    vector<double> x;
    vector<double> y;

public:
    LagrangeInterpolation(vector<double> x, vector<double> y)
    {
        this->x = x;
        this->y = y;
    }

    double interpolation(double value)
    {
        int n = x.size();
        double result = 0;

        for(int i = 0; i < n; i++)
        {
            double term = y[i];
            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    term = term * (value - x[j])/ double(x[i] - x[j]);
                }
            }
            result += term;
        }
        return result;
    }
}
int main()
{
    vector<double> x = {};
    vector<double> y = {};
    LagrangeInterpolation LagrangeInterpolation(x, y);
    cout << LagrangeInterpolation.interpolation(5)<<
}