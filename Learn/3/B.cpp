#include <iostream>
#include <iomanip>

using namespace std;

double function(double x, int n) {
    if (n == 1) {
        return x / (1 + x);
    }
    return x / (n + function(x, n - 1));
}

int main() {
    double x;
    int n;

    cin >> x >> n;

    double result = function(x, n);
    cout << fixed << setprecision(2) << result << endl;
    
    return 0;
}