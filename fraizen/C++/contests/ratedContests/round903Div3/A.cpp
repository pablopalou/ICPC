//Copiar obligatoriamente 1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define cout(x) cout << x << "\n";

//copiar luego 3
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;

//Copiar luego 4
typedef long double ld;
typedef double d;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;

//Copiar obligatoriamente 2
#define debug(x) cout << #x << ": "; _print(x); cout << "\n";
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i = a; i<b; i++)

//copiar luego 4
#define ff first
#define ss second
#define fre(s) for(auto e:s)
#define MAXN 1000008

// Copiar luego 4
#define ppb pop_back
#define mod 1000000007
#define mod1 998244353
#define PI 3.141592653589793238462
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>

//Copiar luego 4
void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(ld t) {cout << t;}
void _print(d t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, size_t N> void _print(T (&arr)[N]);

template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, size_t N> void _print(T (&arr)[N]) {cout << "[ "; for (size_t i = 0; i < N; ++i) {_print(arr[i]); cout << " ";}cout << "]";}


int doesSubstringExists(string s1, string s2)
{
    // calculating the length of the main string and the substring
    int len1 = s1.length();
    int len2 = s2.length();

    // loop to iterate at each character in the string s1 to match the string s2
    for (int i = 0; i <= len1 - len2; i++)
    {
        int j;

        // inner loop to iterate over each character in the string s2, if it matches that particular string s1 char group, on which we are currently iterating from the outer loop
        for (j = 0; j < len2; j++)
        {
            if (s1[i + j] != s2[j])
            {
                // breaking the loop if the match fails
                break; 
            }
        }
        if (j == len2)
        {
            // returning the current index of i, if finally match completed
            return i; 
        }
    }
    // else returning -1
    return -1; 
}

// Copiar obligatoriamente 0
void solve() {
    int n;
    int m; cin >> n >> m;
    string x; cin >> x;
    string s; cin >> s;
    string x2 = x;
    int res = 0;
    while (x2.size() < 65 * s.size()){
        // cout(x2.size());
        if (x2.size() < s.size()){
            x2 = x2 + x2;
            res++;
            continue;
        } else {
            // cout(x2);
            // cout(x2.size());
            // cout(s);
            bool isFound = x2.find(s) != string::npos;
            // int isFound = doesSubstringExists(s,x2);
            // cout(isFound);
            if (isFound){
                cout(res);
                return;
            }
            x2 = x2+x2;
            res++;
        }
    }
    cout(-1);
}


// ACORDATE DE USAR LONG LONG
// PENSAR LOS EJERCICIOS AL REVES
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // BORRAR
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);

    int cases = 1;
    cin >> cases;
    while(cases--){
        solve();
    }

    return 0;
}