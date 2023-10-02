#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int numbers[] = {a, b, c};
    sort(numbers, numbers + 3);
    cout << numbers[1] - numbers[0] + (numbers[2] - numbers[1]) << '\n';
    return 0;
}