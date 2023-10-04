#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
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
#define fre(s) for(auto e: s)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>

vi search(string pattern, string text) {
    ll d = 256;
    ll M = pattern.size();
    ll N = text.size();
    ll i, j;
    ll p = 0; // hash value for pattern
    ll t = 0; // hash value for txt
    ll h = 1;
    ll q = mod;
    vi res;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
 
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
 
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // cout << "Hashes con indices de inicio: " << i << '\n';
        // cout(p);
        // cout(t);
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if (p == t) {
            /* Check for characters one by one */
            // for (j = 0; j < M; j++) {
            //     if (text[i + j] != pattern[j]) {
            //         break;
            //     }
            // }
 
            // if p == t and pat[0...M-1] = txt[i, i+1,
            // ...i+M-1]
 
            // if (j == M)
            res.pb(i);
                // cout << "Pattern found at index " << i
                //      << endl;
        }
 
        // Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - (text[i] * h)) + text[i + M]) % q;
 
            // We might get negative value of t, converting
            // it to positive
            if (t < 0)
                t = (t + q) % q;
        }
    }
    return res;
}


void solve(string text, string pattern) {
    vi indexes = search(pattern, text);
    cout(indexes.size());
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string text, pattern;
    cin >> text;
    cin >> pattern;

    solve(text, pattern);
}