#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

string removeDuplicates(const string& str) {
    set<char> seen;
    string result;
    
    for (char ch : str) {
        if (seen.find(ch) == seen.end()) {
            seen.insert(ch);
            result += ch;
        }
    }
    
    return result;
}

void solve() {
    int n; 
    cin >> n; 
    string b; 
    cin >> b;

    // Construir la cadena r a partir de b
    string r = removeDuplicates(b);
    sort(r.begin(), r.end());

    // Crear un mapa para la decodificación
    unordered_map<char, char> decode_map;
    int r_size = r.size();
    fr(0, r_size) {
        decode_map[r[i]] = r[r_size - 1 - i];
    }

    // Decodificar la cadena b para obtener la cadena original s
    string s;
    s.reserve(n);
    fr(0, n) {
        s += decode_map[b[i]];
    }

    cout << s << '\n';
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
        cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
    #endif

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define fr(a,b) for(int i = a; i<b; i++)
// #define rep(i,a,b) for(int i = a; i<b; i++)
// #define fre(s) for(auto e:s)
// #define pb push_back

// string removeDuplicates(const string& str) {
//     set<char> seen;
//     string result;
    
//     for (char ch : str) {
//         if (seen.find(ch) == seen.end()) {
//             seen.insert(ch);
//             result += ch;
//         }
//     }
    
//     return result;
// }

// void solve() {
//     // int n; cin >> n; string s2; cin >> s2;
//     // string s = s2;
//     // s = removeDuplicates(s);
//     // // sort(s.begin(), s.end());
//     // cout << s << endl;
//     // map<char, char> m;
//     // fr(0,s.size()){
//     //     m[s[i]] = s[n-1-i];
//     //     m[s[n-1-i]] = s[i];
//     // }
//     // if (n & 1){
//     //     m[s[s.size()/2]] = s[s.size()/2];
//     // }
//     // fre(m){
//     //     cout << e.first << " " << e.second << endl;
//     // }
//     // fr(0,n){
//     //     cout << m[s2[i]];
//     // }
//     // cout << '\n';
// }

// // ACORDATE DE USAR LONG LONG
// int main() {
//     std::iostream::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     #ifdef JP
//         freopen("A.in", "r", stdin);
//         freopen("A.out", "w", stdout);
// 	#endif

//     int cases = 1;
//     cin >> cases;
//     while(cases--){
//         solve();
//     }

//     #ifdef JP
// 		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
// 	#endif

//     return 0;
// }