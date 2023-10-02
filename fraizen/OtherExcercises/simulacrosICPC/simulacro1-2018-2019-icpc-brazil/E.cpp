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

void solve(string s, string s2) {
    int ans = 0;
    fr(0,s.size()-s2.size() + 1){
        int k = i;
        rep(j, 0, s2.size()){
            // cout << s[k] << ' ' << s2[j];
            if (s[k] == s2[j]){
                break;
            }
            k+=1;
            if (j == s2.size()-1){
                ans+=1;
            }
        }
    }
    cout(ans);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s; 
    string s2;
    cin >> s; 
    cin >> s2;
    
    solve(s,s2);
}