GAMES

1-2-K GAME 1700

void solve() {
    int n, k;
    cin >> n >> k;
    bool win = true;
    if (k%3 != 0){
        if (n % 3 == 0){
            win = false;
        }
    } else {
        int np = n % (k+1);
        if (np%3 == 0 && np != k){
            win = false;
        }
    }
    cout << (win? "Alice" : "Bob") << "\n";
}

int main() {
    int cases;
    cin >> cases;
    while (cases--){
        solve();
    }
}

ALICE AND BOB 1600


int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); } 

int main() {
    int n; 
    cin >> n;
    vector<int> v(n);
    int maximo;
    fr(0,n){
        int a;
        cin >> a;
        if (i == 0){
            maximo = a;
        } else {
            maximo = max(maximo, a);
        }
        v[i] = a;
    }
    
    int divisor = v[0];
    fr(1,n){
        divisor = gcd(v[i], divisor);
    }
    cout << ((maximo / divisor - n) % 2 == 1 ? "Alice" : "Bob") << "\n";
}

BOARD GAME 1700


void solve(int a, int b, int c, int d) {
    if (a+b <= max(c,d)){
        cout("Polycarp");
    } else if (a <= c && b <=d){
        cout("Polycarp");
    } else {
        cout("Vasiliy");
    }
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    solve(a,b,c,d);
}

CIRCLE GAME 1700 


void solve() {
    ll d, k;
    cin >> d >> k;
    ll res = 0;
    pair<ll, ll> best = make_pair(0,0);
    pair<ll, ll> cur = make_pair(0,0);
    ll total = d * d;
    while (cur.first * cur.first + cur.second*cur.second <= total){
        cur = make_pair(cur.first + k, cur.second + k);
        if (cur.first * cur.first + cur.second*cur.second <= total){
            best = cur;
        }
        // cout <<"Cur:" <<  cur.first << ' ' << cur.second << endl;
        // cout <<"Best:" << best.first << ' ' << best.second << endl; 
    }
    if ((best.first + k) * (best.first + k) + best.second*best.second <= total){
        best = make_pair(best.first +k, best.second);
    }
    // cout <<"Best:" << best.first << ' ' << best.second << endl; 
    res = best.first / k + best.second / k;
    cout << ((res % 2 == 1) ? "Ashish" : "Utkarsh") << "\n";
}

int main() {
    ll cases;
    cin >> cases;
    while(cases--){
        solve();
    }
}