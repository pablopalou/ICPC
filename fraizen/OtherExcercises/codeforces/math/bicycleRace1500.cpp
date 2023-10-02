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
};

void solve() {

}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    
    P p1,p2,p3,p4;
    p1.read();
    p2.read();
    p3.read();
    ll cross_product = (p2-p1) * (p3 - p1);
    int res = 0;
    if (cross_product > 0){
        res+=1;
    }
    fr(4,n+1){
        p1 = p2;
        p2 = p3;
        p3.read();
        cross_product = (p2-p1) * (p3 - p1);
        if (cross_product > 0){
            res+=1;
        }
    }
    cout(res);
}