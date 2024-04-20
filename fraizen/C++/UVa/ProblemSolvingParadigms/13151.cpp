#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

int val(char c){
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
 
// Function to convert a number from given base 'b' to decimal
int toDeci(string str, int base){
    int len = str.size();
    int power = 1;
    int num = 0;
    for (int i = len - 1; i >= 0; i--){
        num += val(str[i]) * power;
        power = power * base;
    }
    return num;
}

// Copiar obligatoriamente 0
void solve() {
    string s; int n;
    while(cin >> s >>n){
        if (s == "0" && n == 0) return;
        int nro = 0;
        if (s[0] != '0'){
            nro = stoi(s);
        } else if (s.size() > 1 && s[1] == 'x'){
            //base 16
            nro = toDeci(s.substr(2), 16);
        } else {
            // base 8
            nro = toDeci(s.substr(1), 8);
        }
        // cout << "NRO = " << nro << endl;
        int exp[n];
        int cur[n];
        int a = 0;
        fr(0,n){
            string s1; int num; cin >> s1 >> num;
            cur[i] = num;
            if (s1 == "++i"){
                exp[i] = 1 + a;
                a = 0;
            } else if (s1 == "i++"){
                exp[i] = a;
                a = 1;
            } else if (s1 == "--i"){
                exp[i] = -1 + a;
                a = 0;
            } else if (s1 == "i--"){
                exp[i] = a;
                a = -1; 
            } else {
                exp[i] = a;
                a = 0;
            }   
        }
        // fr(0,n){
        //     cout << exp[i] << " ";
        // }
        // cout << endl;
        //hago la diferencia del cur nomas y voy comparando con el expected
        int res = cur[0] == nro + exp[0];
        // cout << nro << endl << endl;;
        fr(1,n){
            if (cur[i] - cur[i-1] == exp[i]){
                res++;
            }
        }
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