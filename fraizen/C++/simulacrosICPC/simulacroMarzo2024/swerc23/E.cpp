#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i=a; i<b; i++)
#define rep(i,a,b) for(int i=a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define dforn(i,n) for(int i=n-1; i>-0; i--)
#define sz(c) ((int)c.size())
#define forall(it, v) for(auto it=v.begin(); it != v.end(); it++)
#define mp make_pair

class Rat{
    public:
    ll num,den;
    Rat(ll n=0, ll d = 1){
        set(n,d);
    }
    void set(ll n, ll d){
        num = n;
        den = d;
        reduce();
    }
    void reduce(){
        if (num == 0){
            den = 1;
            return;
        }
        ll factor = gcd(num, den);
        num = num/ factor;
        den = den/factor;
        return;
    }
    ll gcd(ll a, ll b){
        while(b!=0){
            ll temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    Rat& operator=(const Rat& other){
        num = other.num;
        den = other.den;
        return *this;
    }
};

void solve(){
    ll n; cin >> n;
    ll a[n]; fr(0,n) cin >> a[i];
	// fr(0,n){
	// 	cout << a[i] << ' ';
	// }
    ll mayorAnt[n];
    memset(mayorAnt, -1, sizeof(mayorAnt));
    stack<pair<ll,ll> > s1;
    s1.push(mp(a[n-1], n-1));
	// cout << n << endl;
    ll i = n-2;
    while(i >=0){
		// // cout << "i = " << i << endl;
		// cout << a[i] << endl;
		// cout << s1.top().first << endl;
        while(!s1.empty() && s1.top().first < a[i]){
            ll index = s1.top().second;
			// cout << "index = " << index << endl;
            s1.pop();
            mayorAnt[index] = i;
			// cout << "actualizo mayorAnt[ "<< index<< "] = " << i << endl; 
        }
		// cout << "agrego a[i], i" << endl;
        s1.push(mp(a[i], i));
        i--;
    }
    // fr(0,n){
    //     cout << mayorAnt[i] << ' ';
    // }
	// cout << endl;
	// return;
    Rat best = Rat(0,1);
    fr(1,n){
        if (a[i] > a[i-1]){
            if (mayorAnt[i] != -1){
                // cout << mayorAnt[a[i]] << endl;
                // cout <<  i - mayorAnt[a[i]] - 1 << endl;
				// cout << "i = " << i << endl;
				// return;
				// double d = (i - mayorAnt[i] - 1 + 1) * (a[mayorAnt[i]+1] - a[mayorAnt[i]]) - ((i - a[mayorAnt[i]]) / double(a[mayorAnt[i]+1] - a[mayorAnt[i]]));
				// cout << fixed << setprecision(10) << d<< endl;
				// return;

				// cout << "dist = " << (i - mayorAnt[i] - 1 + 1)  << endl;
				// cout << "mult por " << (a[mayorAnt[i]+1] - a[mayorAnt[i]]) << endl;
				// cout << "restar " << (i - a[mayorAnt[i]]) << endl;
				// cout << "division " << a[mayorAnt[i]+1] - a[mayorAnt[i]] << endl;
                // Rat cur = Rat((i - mayorAnt[i] + 1) * (a[mayorAnt[i]+1] - a[mayorAnt[i]]) - (i - a[mayorAnt[i]]), a[mayorAnt[i]+1] - a[mayorAnt[i]]);
                // if ((cur.num / (double)cur.den) > (best.num / (double)best.den)){
                //     best = cur;
                // }
				ll x = i - mayorAnt[i];
				ll y = a[mayorAnt[i]] - a[i];
				ll k = a[mayorAnt[i]] - a[mayorAnt[i] + 1];
				Rat cur = Rat(x*k - y, k);
				 if ((cur.num / (double)cur.den) > (best.num / (double)best.den)){
                    best = cur;
                }
				// cout << "dist = " << fixed << setprecision(5) <<  i - mayorAnt[i] - 1 + 1  << endl;
				// cout << "restar " << fixed << setprecision(10) << 1 - ((i - a[mayorAnt[i]]) / double(a[mayorAnt[i]+1] - a[mayorAnt[i]])) << endl;
				// cout << fixed << setprecision(10) << i - mayorAnt[i] - (((a[mayorAnt[i]] - a[i]) / double(a[mayorAnt[i]] - a[mayorAnt[i] + 1]))) << endl;
                // best = max(best, i - mayorAnt[a[i]] - 1 + 1 - ( (a[i] - a[mayorAnt[a[i]]]) / double(a[mayorAnt[a[i]]+1] - a[mayorAnt[a[i]]]) ));
                // cout << "cur = " << fixed <<setprecision(10) << 1 - ((a[i] - a[mayorAnt[i]])/ (a[mayorAnt[i]+1] / a[mayorAnt[i]]) + i -1 -  mayorAnt[i]) << endl;
                // best = max(best, 1 - ((a[i] - a[mayorAnt[a[i]]])/ (a[mayorAnt[a[i]]+1] / a[mayorAnt[a[i]]]) + i -1 -  mayorAnt[i]));
            }
        }
    } 

    //ahora tengo que hacer el otro lado
    ll mayorPos[n];
    memset(mayorPos, -1, sizeof(mayorPos));
    stack<pair<ll,ll> > s2;
    s2.push(mp(a[0], 0));
    i = 1;
    while(i <= n-1){
        while(!s2.empty() && s2.top().first < a[i]){
            ll index = s2.top().second;
            s2.pop();
            mayorPos[index] = i;
        }
        s2.push(mp(a[i], i));
        i++;
    }

    // fr(0,n){
    //     cout << mayorPos[i] << ' ';
    // }
    //esto supongo que hay que hacerlo al reves
    fr(0,n-1){
        if (a[i] > a[i+1]){
            if (mayorPos[i] != -1){
                // cout << "i " << i << endl;
                // cout << "cur = " << fixed <<setprecision(10) << 1 - ((a[i] - a[mayorAnt[i]])/ (a[mayorAnt[i]+1] / a[mayorAnt[i]]) + i -1 -  mayorAnt[i]) << endl;
                // best = max(best, i - mayorAnt[a[i]] + 1 + a[mayorAnt[a[i]]+1] - ( (a[i] - a[mayorAnt[a[i]]]) / (a[mayorAnt[a[i]]+1] - a[mayorAnt[a[i]]]) ));
                Rat cur = Rat(((mayorPos[i] - 1 - i) * (a[mayorPos[i]-1] - a[mayorPos[i]])) - (a[i] - a[mayorPos[i]-1]), a[mayorPos[i]-1] - a[mayorPos[i]]);
                // best = max(best, cur);
                if ((cur.num / (double)cur.den) > (best.num / (double)best.den)){
                    best = cur;
                }
                // best = max(best, mayorPos[i] - 1 - i + ( (a[i] - a[mayorPos[i]-1]) / (double)(a[mayorPos[i]-1] - a[mayorPos[i]])  ));
                // best = max(best, 1 - ((a[i] - a[mayorAnt[a[i]]])/ (a[mayorAnt[a[i]]+1] / a[mayorAnt[a[i]]]) + i -1 -  mayorAnt[i]));
            }
        }
    }
    if (best.den == 1){
        cout << best.num << "\n";
    } else {
        cout << best.num << "/" << best.den << "\n";
    }
    // cout << best << endl;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef JP
        freopen("E.in", "r", stdin);
    #endif

    int cases = 1;
    // cin >>  cases;
    while(cases--){
        solve();
    }

    #ifdef JF
        cerr << "Time elapsed: " << clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
    #endif


    return 0;
}