m,#include <bits/stdc++.h>

using namespace std;

class bisectionMethod
{
private:
    double error = 0.0001;
    double a, b;
    double function(double x)
    {
        return x * x * x + x * x - 1;
    }

public:
    double root;
    void solve()
    {
        int cnt = 0;
        srand((int)time(0));
        while (true)
        {
            a = rand() % 10 - 9;
            b = rand() % 10;
            if (function(a) * function(b) <= 0)
            {
                break;
            }
        }
        if (a > b)
        {
            swap(a, b);
        }
        while (b - a > error)
        {
            root = (a + b) / 2;
            cout << "a = " << a << "    b = " << b;
            cout << "   The root value of this iteration is: " << root << endl;
            if (function(root) * function(a) < 0)
            {
                b = root;
            }
            else if (function(root) == 0.0)
            {
                break;
            }
            else
            {
                a = root;
            }
            cnt++;
        }
        cout << "The root value of false position method is " << root << "\n";
        cout << "Total number of iteration: " << cnt << endl;
    }
};

class FalsePositionMethod
{
private:
    double epsilon = 0.0001;
    double a, b;

    double function(double x)
    {
        return x * x * x + x * x - 1;
    }
    double intersect(double x, double y)
    {
        return x - (function(x) * (x - y)) / (function(x) - function(y));
    }

public:
    double root;

    void solve()
    {
        int cnt = 0;
        srand((int)time(0));
        while (true)
        {
            a = rand() % 10 - 9;
            b = rand() % 10;
            if (function(a) * function(b) <= 0)
            {
                break;
            }
        }
        if (a > b)
            swap(a, b);
        while (true)
        {
            root = intersect(b, a);
            cout << "a = " << a << "    b = " << b;
            cout << "   The root value of this iteration is: " << root << endl;
            if (function(root) * function(a) <= 0)
            {
                b = root;
            }
            else if (function(root) == 0.0)
            {
                break;
            }
            else
            {
                a = root;
            }
            if (abs((root - intersect(b, a)) / root) < epsilon)
            {
                break;
            }
            cnt++;
        }
        cout << "The root value of false position method is " << root << "\n";
        cout << "Total number of iteration: " << cnt << endl;
    }
};

class newtonRaphsonMethod {
private:
    double epsilon = 0.001;

    double function(double x) {
        return x * x * x + x * x - 1;
    }

    double functionPrime(double x) {
        return 3 * x * x + 2 * x;
    }
public:
    double root;

    void solve()
    {
        
        srand((int)time(0));
        while(true)
        {
            root = -9 + rand() % 10;
            if(functionPrime(root) != 0)
                break;
        }

        double previousRoot = function(root) / functionPrime(root);
        while(abs(previousRoot) >= epsilon)
        {
            previousRoot = function(root) / functionPrime(root);
            root = root - previousRoot;
        }

        cout << "The root value of newtonRaphsonMethod is : " << root << endl;
    }
};


int main()
{
    bisectionMethod b = bisectionMethod();
    //b.solve();
    FalsePositionMethod f = FalsePositionMethod();
    //f.solve();
    newtonRaphsonMethod n = newtonRaphsonMethod();
    n.solve();

    cout << endl;
    // cout << "The root value of bisection method is: " << b.root << endl;
    // cout << "The root value of false position method is: " << f.root << endl;

    return 0;
}
