// @tarche
// H. The Child and Polygon
// Codeforces
// Geometry
// https://codeforces.com/group/AOLjpHeTiB/contest/496424/problem/H
// 2024-01-26
#include <bits/stdc++.h>
#define forn(i, n) for (tint i = 0; i < tint(n); i++)
#define forsn(i, s, n) for (tint i = s; i < tint(n); i++)
#define dforn(i, n) for (tint i = tint(n) - 1; i >= 0; i--)
#define dforsn(i, s, n) for (tint i = tint(n) - 1; i >= s; i--)
#define sz(x) tint(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define DBG(x) cerr << #x << " = " << x << endl
 
using namespace std;
 
#ifndef SMALL_TINT
using tint = long long;
#else
using tint = int;
#endif
using vi = vector<tint>;
using pii = pair<tint, tint>;
 
inline void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
 
inline string YN(bool x, string y = "YES", string n = "NO") { return (x ? y : n); }
 
template <typename T>
inline void chmax(T &lhs, T rhs) {
  lhs = max(lhs, rhs);
}
 
template <typename T>
inline void chmin(T &lhs, T rhs) {
  lhs = min(lhs, rhs);
}
 
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
 
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  forn(i, sz(v)) {
    if (i > 0) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}
 
template <typename T, size_t N>
ostream &operator<<(ostream &os, const array<T, N> &v) {
  os << "[";
  forn(i, N) {
    if (i > 0) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}
const tint MOD = 1e9 + 7;
 
struct Point {
  tint x, y;
  Point() {}
  Point(tint _x, tint _y) : x{_x}, y{_y} {}
  Point operator-(const Point &o) const { return Point(x - o.x, y - o.y); }
  tint cross(const Point &p) const { return x * p.y - y * p.x; }
  tint cross(const Point &a, const Point &b) const { return (a - *this).cross(b - *this); }
};
 
tint sgn(const tint &x) { return x >= 0 ? (x > 0 ? 1 : 0) : -1; }
bool inter1(tint a, tint b, tint c, tint d) {
  if (a > b) swap(a, b);
  if (c > d) swap(c, d);
  return max(a, c) <= min(b, d);
}
 
bool intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
  if (c.cross(a, d) == 0 && c.cross(b, d) == 0) return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
  return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) && sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}
 
bool areCollinear(const Point &a, const Point &b, const Point &c) { return a.cross(b, c) == 0; }
 
bool isInsidePolygon(const vector<Point> &poly, const Point &p) {
  tint n = sz(poly);
  const tint MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
  Point ray = {p.x + MOD1, p.y + MOD2};
  bool inside = false;
  forn(i, n) { inside ^= intersect(poly[i], poly[(i + 1) % n], p, ray); }
  return inside;
}
 
int main() {
  fastIO();
 
  tint n;
  cin >> n;
 
  vector<Point> points(n);
  forn(i, n) {
    cin >> points[i].x >> points[i].y;
    points[i].x *= 2, points[i].y *= 2;
  }
 
  vector<vector<bool>> intersectsPoly(n, vector<bool>(n, false));
  forn(i, n) forn(j, n) forn(k, n) {
    if (i == j || i == k || j == k || i == (k + 1) % n || j == (k + 1) % n) continue;
    if (intersect(points[i], points[j], points[k], points[(k + 1) % n])) intersectsPoly[i][j] = true;
  }
 
  vector<vector<bool>> segmentOutsidePoly(n, vector<bool>(n, false));
  forn(i, n) forn(j, n) {
    if (i == j || i + 1 == j || (i + n - 1) % n == j) continue;
    tint x = (points[i].x + points[j].x) / 2;
    tint y = (points[i].y + points[j].y) / 2;
    segmentOutsidePoly[i][j] = !isInsidePolygon(points, {x, y});
  }
 
  vector<vi> dp(n, vi(n, 0));
  forn(i, n - 1) dp[i][i + 1] = 1;
  forsn(len, 2, n) forn(i, n - len) forsn(j, i + 1, i + len) {
    if (intersectsPoly[i][j] || intersectsPoly[i + len][j]) continue;
    if (areCollinear(points[i], points[i + len], points[j])) continue;
    if (segmentOutsidePoly[i][j] || segmentOutsidePoly[i + len][j]) continue;
 
    dp[i][i + len] += dp[i][j] * dp[j][i + len];
    dp[i][i + len] %= MOD;
  }
//   for(int i = 0; i < n; i++){
//     for(int j = 0; j < n; j++){
//         cout << dp[i][j] << ' ';
//     }
//     cout << "\n";
//   }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        cout << intersectsPoly[i][j] << ' ';
    }
    cout << "\n";
  }
 
  cout << dp[0][n - 1] << '\n';
}