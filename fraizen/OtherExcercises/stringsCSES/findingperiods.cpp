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
#define f first
// #define s second
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
char s[MAXN];
int z[MAXN];

void z_function(char s[]){
    int n = strlen(s);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}  
//     fr(0, n) z[i]=0;

//     fr(0,n) z[i] = 0;
//     for (int i = 1, l=0, r=0; i<n; ++i){
//         if (i<=r){
//             z[i] = min(r-i+1, z[i-l]);
//         }
//         while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
//         if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
//     }
// }

// vector<int> z_function_string(string s) {
//     int n = s.size();
//     vector<int> z(n);
//     int l = 0, r = 0;
//     for(int i = 1; i < n; i++) {
//         if(i < r) {
//             z[i] = min(r - i, z[i - l]);
//         }
//         while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
//             z[i]++;
//         }
//         if(i + z[i] > r) {
//             l = i;
//             r = i + z[i];
//         }
//     }
//     return z;
// }

void solve(char s[]) {
    // vector<int> z = z_function_string(s);
    z_function(s);
    int n = strlen(s);
    for(int i = 1;i<n;i++){
        if(z[i]+i==n)cout<<i<<" ";
    }
    cout(n);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // Parsing
    // cin >> s;
    cin.getline(s, MAXN);
    
    solve(s);
}

