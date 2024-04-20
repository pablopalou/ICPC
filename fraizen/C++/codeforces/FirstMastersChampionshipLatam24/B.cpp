#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

ll a[25];

unsigned long long power(unsigned long long x,
                                  int y)
{
    unsigned long long res = 1;
    x = x; 
    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

ll dp(string s, int pos, bool menor, int digits, int puedo){
    if (pos > puedo){
        // cout << "retorno 0"<<endl;
        return 0; // o 1 en el caso de que justo sea igual...
    }
    if (menor){
        // cout << "retorno " << power(10,puedo-pos) << endl;
        return power(10,puedo-pos);
    } else {
        if (pos == 0){
            // cout << "retorno pos 0 " <<dp(s, pos+1, true, digits, puedo) * (s[pos]-'0'-1) + dp(s, pos+1, false, digits, puedo) << endl;
            return dp(s, pos+1, true, digits, puedo) * (s[pos]-'0'-1) + dp(s, pos+1, false, digits, puedo);
        } else {
            // cout << "retorno pos fraizen " <<dp(s, pos+1, true, digits, puedo) * (s[pos]-'0') + dp(s, pos+1, false, digits, puedo);
            return dp(s, pos+1, true, digits, puedo) * (s[pos]-'0') + dp(s, pos+1, false, digits, puedo);
        }
    }
}

bool isPalindrome(ll n) {
    if (n < 0) return false;
    ll original = n;
    ll reversed = 0;
    while (n > 0) {
        ll digit = n % 10; // Extract the last digit
        reversed = reversed * 10 + digit; // Add it to the reversed number
        n /= 10; // Remove the last digit from n
    }
    return original == reversed;
}

ll contar(ll n){
    // cout << n << endl;
    ll oldN = n;
    ll digits = 0;
    while(n){
        n/=10;
        digits++;
    }
    if (digits == 0){
        return 0;
    }
    ll res = a[digits-1];
    ll puedo = (digits + 1)/2;
    string s;
    s = to_string(oldN);
    res += dp(s, 0, false, digits, puedo) + isPalindrome(oldN);
    // cout << "Dp " << dp(s, 0, false, digits, puedo) << endl;
    return res;
}

// Copiar obligatoriamente 0
void solve() {
    a[0] = 0;
    a[1]=9;
    a[2] = 9;
    for (int i = 3; i <= 18; i+=2){
        a[i] = a[i-2] * 10;
        a[i+1] = a[i];
    }
    fr(1,19){
        a[i] += a[i-1];
    }
    fr(0,19){
        cout << a[i] << " ";
    }
    cout << endl;
    ll q; cin >> q;
    fr(0,q){
        ll l,r; cin >> l >> r;
        ll res = contar(r) - contar(l-1);
        cout << res << "\n";
    }
}

// ACORDATE DE USAR LONG LONG
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("A.in", "r", stdin);
        freopen("A.out", "w", stdout);
	#endif

    int cases = 1;
    // cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}