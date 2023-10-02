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

void solve(int n, int k,int* a) {
    long double maximo = 0.0;
    fr(1,n+1){
        a[i] += a[i-1];
    }  
    for (int i = k; i < n+1; i++){
        for (int j = i; j < n+1; j++){
            
            long double suma = (double) (a[j] - a[j-i]);
            // prDouble(suma);
            long double den = (double) (i);
            // prDouble(den);
            long double cur = (double) suma / (double) den;
            // cout(cur);
            maximo = max(maximo, cur);
        }
    }
    prDouble(maximo);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    int m = n+1;
    int a[m];
    a[0] = 0;
    fr(1,m){
        cin >> a[i];
    }
    solve(n,k,a);
}
