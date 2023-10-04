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


void solve(string a) {
    ll res = 0;
    map<char, int> alphabet_map;
    for (char letter = 'a'; letter <= 'z'; ++letter) {
        alphabet_map[letter] = letter - 'a';
    }
    int pos = 0;
    for (char c : a) {
        int d,e;
        d = max(alphabet_map[c],pos);
        e = min(alphabet_map[c],pos);
        res += min(abs(d-e), e + 26-d);
        pos = alphabet_map[c];
    }
    cout(res);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a;
    cin >> a;
    solve(a);
}
