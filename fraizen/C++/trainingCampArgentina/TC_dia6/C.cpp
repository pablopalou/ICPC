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


void solve(int n, int k, queue<int> q) {
    int res = 0;
    int first = q.front();
    q.pop();
    int wins = 0;
    while (!q.empty()){
        int second = q.front();
        // cout(first);
        // cout(second);
        if (first > second){
            wins += 1;
            // cout(wins);
            if (wins == k){
                cout(first);
                break;
            }
            q.pop();
            q.push(second);
        } else {
            q.pop();
            q.push(first);
            first = second;
            wins = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k;
    cin >> n >> k;
    queue<int> q;
    ll maximo = 0;
    fr(0,n){
        ll s;
        cin >> s;
        maximo = max(maximo, s);
        q.push(s);
    }
    if (k >= n-1){
        cout(maximo);
    } else {
        solve(n,k,q);
    }
}
