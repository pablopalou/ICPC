#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define fr(a,b) for (int i = a; i < b; i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define fre(s) for(auto e: s)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2e5 + 5;
int n, isc, tot, g;
vi v;
map<int, int> mp;
bitset<MX> dp;

//GENERA NUMEROS DE MAS EN LA MOCHILA
void main_() {
	cin >> n;
	
	forn (i, n) {
		int x, y;
		cin >> x >> y;
		
		tot += x;
		
		if (x) mp[x]++;
		else isc = 1;
		
		g = gcd(g, y);
	}
	fre(mp){
        cout << e.first << " " << e.second << endl;
    }
    int i = 0;
	while (mp.size()) {
        cout << "Iteracion " << i << endl;
		while (mp.begin()->se > 2) {
			mp[2 * mp.begin()->fi]++;
			mp.begin()->se -= 2;
		}
        cout << "Mapa despues del primer while "<<endl;
        fre(mp){
            cout << e.first << " " << e.second << endl;
        }
		
		while (mp.begin()->se) {
			v.pb(mp.begin()->fi);
			mp.begin()->se--;
		}
		cout << "Mapa despues del segundo while "<<endl;
        fre(mp){
            cout << e.first << " " << e.second << endl;
        }
        cout << "El vector queda => " << endl;
        fr(0,v.size()){
            cout << v[i] << ' ';
        }
        cout << endl;

		mp.erase(mp.begin());
        cout << "Borro del mapa al primero y queda "<< endl;
        cout << "Mapa despues del borrado "<<endl;
        fre(mp){
            cout << e.first << " " << e.second << endl;
        }
        i++;
	}
	
	dp[0] = 1;
	for (int x : v)
		dp |= dp << x;
	
	forr (i, 1 - isc, tot - 1 + isc)
		if (dp[i] && abs(2 * i - tot) % g == 0) {
			cout << "Y" << endl;
			return;
		}
	
	cout << "N" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}
