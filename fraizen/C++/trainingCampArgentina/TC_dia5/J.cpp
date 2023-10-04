#include <bits/stdc++.h>
 
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
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

string smallest(string s) {
    if (s.length() % 2 == 1) return s;
    string s1 = smallest(s.substr(0, s.length()/2));
    string s2 = smallest(s.substr((s.length()/2), s.length()));
    if (s1 < s2) return s1 + s2;
    else return s2 + s1;
}

void solve(string m, string n) {
    cout(smallest(m));
    cout(smallest(n));
    if (smallest(m) == (smallest(n))){
        cout("YES");
    } else {
        cout("NO");
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string m,n;
    cin >> m >> n;
    solve(m,n);
}

