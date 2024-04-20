#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

// Copiar obligatoriamente 0
void solve() {
    string s;
    while(getline(cin, s)){
        // if (s.size() == 0) return;
        // cout << s << endl;
        stack<char> st;
        string newS;
        int i = 0;
        while( i< s.size()){
            if (s[i] != '(' && s[i]!='*'){
                newS.pb(s[i]);
            } else {
                if (i+1 < s.size() && s[i] == '(' && s[i+1] == '*'){
                    newS.pb('%');
                    i++;
                } else if (i+1 < s.size() && s[i] == '*' && s[i+1] == ')'){
                    newS.pb('$');
                    i++;
                } else {
                    newS.pb(s[i]);
                }
            }
            i++;
        }
        map<char, char> m;
        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';
        m['<'] = '>';
        m['%'] = '$';

        //another way to initialize map
        // map<char, char> m{
        //     {'(' ,')'},
        //     {'[' ,']'},
        //     {'{' ,'}'},
        //     {'<' ,'>'},
        //     {'%' ,'$'},
        // };

        map<char, char> m2;
        m2[')'] = '(';
        m2[']'] = '[';
        m2['}'] = '{';
        m2['>'] = '<';
        m2['$'] = '%';

        set<char> sett; 
        sett.insert(')');
        sett.insert(']');
        sett.insert('}');
        sett.insert('>');
        sett.insert('$');

        bool salir = false;
        fr(0,newS.size()){
            // cout << newS[i] << endl;
            if (m.find(newS[i])==m.end()){
                if (sett.find(newS[i]) == sett.end()){
                    // cout << "sigo" << endl;
                    continue;
                } else {
                    if (st.empty() || m2[newS[i]] != st.top()){
                        cout << "NO " << i+1 << "\n"; salir = true; break;
                    } else {
                        st.pop();
                        // cout << "saco pila" << endl;
                    }
                }
            } else {
                st.push(newS[i]);
                // cout << "pongo pila" << endl;
            }
        }
        if (!salir){
            if (st.empty()){
                cout << "YES" << "\n";
            } else {
                cout << "NO " << newS.size()+1 << "\n";
            }
        }
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