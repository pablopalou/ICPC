#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

bool is_on_crust(const int &r, const int &main_radius, const int &x, const int &y, const int &sausage_radius) {
    double distance_to_center = sqrt(x * x + y * y);
    double sausage_inner_radius = distance_to_center - sausage_radius;
    double sausage_outer_radius = distance_to_center + sausage_radius;

    if (sausage_inner_radius >= main_radius && sausage_outer_radius <= r) {
        return true;
    }
    return false;
}

int main() {
    int r, d, n;
    cin >> r >> d >> n;
    int main_radius = r - d;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        int xi, yi, ri;
        cin >> xi >> yi >> ri;

        if (is_on_crust(r, main_radius, xi, yi, ri)) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}