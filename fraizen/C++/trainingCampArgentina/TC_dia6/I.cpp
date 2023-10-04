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
#define prDouble(x) cout << fixed << setprecision(15) << x
#define triplet pair<ll,pair<ll,ll>>

void solve(string s) {
    string res = "";
    int cantA, cantB;
    cantA = cantB = 0;
    if (s.length() <= 1){
        cout("NO");
        return;
    } else if (s[0] == 'B') {
        // cout('b');
        cout("NO");
        return;
    } else if (s[s.length()-1] == 'A'){
        // cout('c');
        cout("NO");
        return;
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A'){
            cantA += 1;
        } else {
            cantB += 1;
        }
        if (cantB > cantA){
            cout("NO");
            return;
        }
        // if (s[i - 1] == 'B' && s[i] == 'B') {
        //     // cout('d');
        //     // cout(i);
        //     cout("NO");
        //     return;
        // }
    }
    res = "YES";
    cout(res);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    cin >> cases;
    while (cases >0){
        string s;
        cin >> s; 
        solve(s);
        cases -= 1;
    }
}
