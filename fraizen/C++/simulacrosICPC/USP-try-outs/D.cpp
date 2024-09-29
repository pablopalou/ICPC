#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
typedef long double ld;
ll x,y,z; 
ld tx,ty,tz;
ld radius;

ld dist(ld x1,ld y1, ld z1, ld x2, ld y2, ld z2){
    return ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1));
}

//NO USAR SQRT
bool puedo(ld R){
    //pruebo las 8 ""esquinas"" posibles segun este radio de la valija y veo si alguna esta mas lejos de la otra pelota
    ld fraizen =(R + radius) * ((R + radius));
    //  cout << fixed << setprecision(10) << fraizen << endl;
    //  cout << fixed << setprecision(10) <<  dist(R,R,R,tx,ty,tz) << endl;
    if (dist(R,R,R,tx,ty,tz) >= fraizen){
        return true;
    }
    if (dist(R,R,z-R,tx,ty,tz) >= fraizen){
        return true;
    }
    if (dist(R,y-R,R,tx,ty,tz) >= fraizen){
        return true;
    }
    if (dist(R,y-R,z-R,tx,ty,tz) >= fraizen){
        return true;
    }
    if (dist(x-R,R,R,tx,ty,tz) >= fraizen){
        return true;
    }
    if (dist(x-R,R,z-R,tx,ty,tz) >= fraizen){
        return true;
    }
    if (dist(x-R,y-R,R,tx,ty,tz) >= fraizen){
        return true;
    }
    if (dist(x-R,y-R,z-R,tx,ty,tz) >= fraizen){
        return true;
    }
    return false;
}

void solve() {
    cin >> x >> y >> z;
     cin >> tx >> ty >> tz;
     cin >> radius;
    ld l = 0.0;
    ld r = min({x,y,z}) / 2.0;
    // cout << fixed << setprecision(10) << l << endl;
    // cout << fixed << setprecision(10) << r << endl;
    fr(0,10000){
        ld mid = l + (r-l)/2.0;
        // cout << fixed << setprecision(10) << "Pruebo mid = " <<mid << endl;
        if (puedo(mid)){
            l = mid;
        } else {
            r = mid;
        }
        // cout << endl;
    }
    cout << fixed << setprecision(10) << l << '\n';
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