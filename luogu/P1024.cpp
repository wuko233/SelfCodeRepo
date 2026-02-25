#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double a, b, c, d;

double function(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

double findRoot(double l, double r) {
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        if (function(mid) * function(l) <= 0) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return (l + r) / 2;
}

bool checkRoot(double x, vector<double>& roots) {
    for (double root : roots) {
        if (fabs(root - x) < 1e-6) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> a >> b >> c >> d;

    vector<double> roots;

    for (int i = -100; i < 100; i++) {
        double left = i;
        double right = i + 1;

        double fl = function(left);
        double fr = function(right);

        if (fabs(fl) < 1e-6 && checkRoot(left, roots)) {
            roots.push_back(left);
            continue;
        }

        if (fl * fr < 0) {
            double root = findRoot(left, right);
            if (checkRoot(root, roots)) {
                roots.push_back(root);
            }
        }
    }

    if (fabs(function(100)) < 1e-6 && checkRoot(100, roots)) {
        roots.push_back(100);
    }

    sort(roots.begin(), roots.end());

    for (size_t i = 0; i < roots.size() && i < 3; ++i) {
        printf("%.2f ", roots[i]);
    }

}