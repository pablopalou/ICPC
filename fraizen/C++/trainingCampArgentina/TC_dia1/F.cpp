#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(),(x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno << ": " 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
 
using namespace std;

// Function to convert degrees to radians
double toRadians(double angleInDegrees) {
    return (angleInDegrees * M_PI) / 180.0;
}

// Function to calculate the area of a triangle
double triangleArea(double side1, double side2, double angleInDegrees) {
    double angleInRadians = toRadians(angleInDegrees);
    return 0.5 * side1 * side2 * sin(angleInRadians);
}

void solve(int n, int R, int r) {
    double res = 0;
    double angle_between_outer_points = 360.0 / n;
    double angle = angle_between_outer_points / 2;
    res = triangleArea(r, R, angle);
    res = res * 2 * n;
    prDouble(res);
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,R,r,w;
    cin >> n >> R >> r;
    solve(n,R,r);
}
