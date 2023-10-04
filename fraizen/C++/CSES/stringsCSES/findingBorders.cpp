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

// Al parecer para encontrar los borders de un string tengo que fijarme el ultimo border y los border de ese borders. Ya que el border de un border tambien es un border del string original. 
// Primero hacemos la table pi (que es la que muestro en el codigo de abajo).
// longest proper prefix that is also a suffix for each substring.

vi preProcessPiTable(string s1) {
    int n = s1.length();
    int len = 0;
    vi pi(n);
    int i = 1;
    while (i < n){
        if (s1[i] == s1[len]){
            len++;
            pi[i] = len;
            i++;
        } else {
            if (len!=0){
                len = pi[len-1];
            } else {
                pi[i] = 0;
                i++;
            }
        }
    }
    return pi;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string a;
    cin >> a;
    vector<int>pi = preProcessPiTable(a);
    vector<int>res;
    int j = pi[pi.size()-1];
    while(j > 0){
        res.push_back(j);
        j = pi[j-1];
    }
    reverse(res.begin(), res.end());
    for(auto it: res)
        cout << it << " ";
}