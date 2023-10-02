#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000008

struct P {
    int x,y;
    void read(){
        cin >> x >> y;
    }
    P operator - (const P& b) const{
        return P{x-b.x, y -b.y};
    }
    void operator -=(const P& b){
        x -= b.x;
        y -= b.y;
    }
    ll operator * (const P& b) const{
        return (ll) x*b.y - (ll) y * b.x;
    }
    bool operator < (const P& B) const{
        return make_pair(x,y) < make_pair(B.x, B.y);
    }
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<P> points(n);
    fr(0,n){
        points[i].read();
    }
    sort(points.begin(), points.end());
    vector<P> hull;
    fr(0,2){
        const int S = hull.size();
        for(P C: points){
            while ((int) hull.size() - S >= 2){
                P A = hull.end()[-2];
                P B = hull.end()[-1];
                if ((B-A) * (C-A) <= 0){
                    break;
                }
                hull.pop_back();
            }
            hull.push_back(C);
        }
        hull.pop_back(); //remove rightmost point
        reverse(points.begin(), points.end());
    }
    cout << hull.size() << "\n";
    for(P p:hull){
        cout << p.x << ' ' << p.y << "\n";
    }
}