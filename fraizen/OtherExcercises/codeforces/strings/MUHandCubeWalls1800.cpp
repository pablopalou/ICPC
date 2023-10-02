#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double d;
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
#define MAXLEN 200010

int b[MAXLEN];

void kmppre(vi s1, vi s2){
    int i = 0, j = -1;
    b[0] = -1;
    while (i < s2.size()){
        while (j >= 0 && s2[i] != s2[j]){
            j = b[j];
        }
        i++,j++;
        b[i] = j;
    }
}

void kmp(vi s1, vi s2) {
    kmppre(s1,s2);
    int res = 0;
    int i=0, j=0;
    while (i < s1.size()){
        while(j >= 0 && s1[i] != s2[j]){
            j = b[j];
        }
        i++, j++;
        if (j == s2.size()){
            res += 1;
            j = b[j];
        }
    }
    cout(res);
}

vector<ll> toDiffArray(vector<ll> v) {
    vector<ll> res(v.size()-1);
    fr(1,v.size()){
        res[i-1] = v[i] - v[i-1];
    }
    return res;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, w;
    cin >> n >> w;
    if (w == 1){
        cout(n);
        return 0;
    }

    vector<ll> v1(n);
    vector<ll> v2(w);
    
    fr(0,n){
        int a;
        cin >> a;
        v1[i] = a;        
    }

    fr(0,w){
        int a;
        cin >> a;
        v2[i] = a;        
    }

    vector<ll> aDiff = toDiffArray(v1);
    vector<ll> bDiff = toDiffArray(v2);

    kmp(aDiff, bDiff);
}