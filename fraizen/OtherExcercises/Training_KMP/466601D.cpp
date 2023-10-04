#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> si;
typedef multiset<int> msi;
typedef unordered_set<int> usi;
typedef map<int, string> mis;
typedef unordered_map<int, string> umis;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define MAXLEN 100010

int b[MAXLEN];

void kmppre(string s1, string s2){
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

void solve(string s1, string s2) {
    //ojo que este es modficado me parece
    kmppre(s1,s2);
    int res = 0;
    int i=0, j=0;
    while (i < s1.size()){
        // cout(j);
        while(j >= 0 && s1[i] != s2[j]){
            j = b[j];
        }
        i++, j++;
        if (j == s2.size()){
            res += 1;
            j = 0;
        }
    }
    cout(res);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string a,b;
    cin >> a >> b;
    
    solve(a,b);
}