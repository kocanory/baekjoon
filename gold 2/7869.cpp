#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double x1, y1, r1, x2, y2, r2, d, res = 0.000, pi = 3.14159265358979323846;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    if (r1 + r2 <= d) {
        printf("%.3f", res);
    }
    else if (abs(r2 - r1) >= d) {
        double r = min(r1, r2);
        res = pow(r, 2) * pi;
        printf("%.3f", res);
    }
    else {
        double theta1 = acos((pow(r1, 2) + pow(d, 2) - pow(r2, 2)) / (2 * r1 * d)), theta2 = acos((pow(r2, 2) + pow(d, 2) - pow(r1, 2)) / (2 * r2 * d));
        double tri1 = pow(r1, 2) * sin(theta1 * 2) / 2, tri2 = pow(r2, 2) * sin(theta2 * 2) / 2;
        double s1 = pow(r1, 2) * theta1 - tri1, s2 = pow(r2, 2) * theta2 - tri2;
        printf("%.3lf", s1 + s2);
    }

    return 0;
}