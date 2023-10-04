DP CSES

ARRAY DESCRIPTION

int dp[MAXN][102];
int a[MAXN];

void solve(int n, int m) {
    fr(2,n+1){
        if (a[i] == 0){
            rep(j,0,m+1){
                dp[i][j] = dp[i-1][j];
                if (j-1 >= 1){
                    dp[i][j] += dp[i-1][j-1];
                    dp[i][j] %= mod;
                }
                if (j+1 <= m){
                    dp[i][j] += dp[i-1][j+1];
                }
                dp[i][j] %= mod;
            }
        } else {
            int j = a[i];
            dp[i][j] = dp[i-1][j];
            if (j-1 >= 1){
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= mod;
            }
            if (j+1 <= m){
                dp[i][j] += dp[i-1][j+1];
            }
            dp[i][j] %= mod;
        }
    }   
}

int main() {
    memset(dp,0, sizeof dp);
    int n,m;
    cin >> n >> m;
    int ultPos = -1;
    fr(1,n+1){
        cin >> a[i];
        if (a[i] != 0) {
            ultPos = i;
        }
    }
    if (n>=1){
        if (a[1] == 0){
            fr(1,m+1){
                dp[1][i] = 1;
            }
        } else {
            dp[1][a[1]] = 1;
        }
    }
    solve(n,m);
    if (a[n] != 0){
        cout << dp[n][a[n]] << "\n";
    } else {
        int res = 0;
        fr(1,m+1){
            res += dp[n][i];
            res %= mod;
        }
        cout << res << "\n";
    }
}

BOOKSHOP

int dp[1002][MAXN];
int costs[1002];
int pages[1002];

void solve(int n, int plata) {
    fr(1,n+1){
        rep(j,1,plata+1){
            dp[i][j] = dp[i-1][j];
            if (j >= costs[i]){
                dp[i][j] = max(dp[i-1][j - costs[i]] + pages[i], dp[i][j]);
            }
        }
    }
}

int main() {
    memset(dp, 0, sizeof dp);
    int n,plata;
    cin >> n >> plata;

    fr(1,n+1){
        cin >> costs[i];
        // cout << costs[i] << ' ';
    }

    fr(1,n+1){
        cin >> pages[i];
        // cout << pages[i] << ' ';
    }


    solve(n, plata);
    cout << dp[n][plata] << "\n";
}

COIN COMBINATIONS

ll coins[105];
ll dp[MAXN];

void solve(ll n, ll x){
    fr(1,x+1){
        rep(j,0,n){
            if (i > coins[j]){
                dp[i] += dp[i-coins[j]] % mod;
                dp[i] %= mod;
            }
        }
    }
}

int main() {
    memset(dp, 0, sizeof dp);
    ll n,x;
    cin >> n >> x;
    fr(0,n){
        cin >> coins[i];
        dp[coins[i]] = 1;
    }
    solve(n, x);
    cout(dp[x]);
}

COIN COMBINATIONS II

int coins[105];
int dp[105][MAXN];

void solve(int n, int x){
    fr(1,n+1){
        rep(j,0,x+1){
            dp[i][j] = dp[i-1][j];
            if (j-coins[i-1] >= 0){
                dp[i][j] += dp[i][j-coins[i-1]] % mod;
                dp[i][j]%=mod;
            }
        }
    }
}

int main() {
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    int n,x;
    cin >> n >> x;
    fr(0,n){
        cin >> coins[i];
    }
    solve(n, x);
    int res = dp[n][x];
    cout << res << "\n";
}

COUNTING TOWERS

ll dp[MAXN][2];

void solve() {
    fr(2,MAXN){
        dp[i][0] = (dp[i-1][0] * 2 + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i-1][1] * 4 + dp[i-1][0]) % mod;
    }
}

int main() {


    int cases;
    cin >> cases;
    
    dp[1][0] = 1;
    dp[1][1] = 1;

    // precomputo todo
    solve();
    while(cases--){
        ll n;
        cin >> n;
        ll res = (dp[n][0] + dp[n][1]) % mod;
        cout << res << "\n";
    }
}

DICE COMBINATIONS

ll dp[MAXN];

void solve(ll n) {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    fr(7,n+1){
        rep(j,1,7){
            dp[i] += dp[i-j] % mod;
            dp[i] %= mod;
        }
    }
    cout << dp[n] << "\n";
}

int main() {
    memset(dp, 0, sizeof dp);
    ll n;
    cin >> n;
    
    solve(n);
}

EDIT DISTANCE

int dp1[5005];
int dp2[5005];

void solve(string a, string b)
{
    int n, m;
    n = a.size();
    m = b.size();

    for (int i = 0; i <= m; ++i)
    {
        dp1[i] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        dp2[0] = i;
        for (int j = 1; j <= m; ++j)
        {
            dp2[j] = min({dp1[j] + 1, dp2[j - 1] + 1, dp1[j - 1] + (a[i - 1] != b[j - 1])});
        }
        swap(dp1, dp2);
        // fill(dp2, dp2+m+1,0); este fill es innecesario
    }
    cout << dp1[m] << "\n";
}

int main()
{
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    std::cout.tie(nullptr);
    string a, b;
    cin >> a >> b;

    solve(a, b);
}

ELEVATORS RIDES


int main() {
    int n;
    ll maxWeight;
    cin >> n >> maxWeight;
    vector<ll> people(n);
    fr(0,n) cin >> people[i];

    int limit = 1 << n;
    vp dp(limit);
    dp[0] = {1,0}; // un elevador con capacidad hasta el momento 0
    rep(mask,1,limit){
        pair<ll,ll> bestResult = {INT_MAX, INT_MAX};
        fr(0,n){ // tenemos que iterar y apagar un bit donde sea posible para ver el resultado
            if (((1 << i) & mask) == 0) continue; // Si el bit esta apagado, no tenemos que hacer nada.
            // ahora nos fijamos que da si apagamos uno de los bits que esta en uno.
            pair<ll,ll> res = dp[ (1 << i) ^ mask];
            if (res.second + people[i] <= maxWeight){
                res.second += people[i];
            } else {
                res.first += 1;
                res.second = people[i];
            }
            bestResult = min(bestResult, res);
        }
        dp[mask] = bestResult;
    }
    cout << dp[limit-1].first;
}

GRID PATHS

int dp[1009][1009];

void solve(int n) {
    fr(1,n){
        if ((dp[0][i] == 0) && (dp[0][i-1] == 1)){
            dp[0][i] = 1;
        } else {
            dp[0][i] = 0;
        }
        if ((dp[i][0] == 0) && (dp[i-1][0] == 1)){
            dp[i][0] = 1;
        } else {
            dp[i][0] = 0;
        }
    }

    fr(1,n){
        rep(j,1,n){
            if (dp[i][j] == -1){continue;}
            if (dp[i][j-1] != -1){
                dp[i][j] += dp[i][j-1] % mod;
            }
            if (dp[i-1][j] != -1){
                dp[i][j] += dp[i-1][j] % mod;
            }
            dp[i][j] %= mod;
        }
    }

    // fr(0,n){
    //     rep(j,0,n){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout(' ');
    // }
}

int main() {
    memset(dp, 0, sizeof dp);
    int n;
    cin >> n;
    char number;
    fr(0,n){
        rep(j,0,n){
            cin >> number;
            if (number == '.'){
                dp[i][j] = 0; 
            } else {
                dp[i][j] = -1;
            }
        }
    }
    if (dp[0][0] == -1 || dp[n-1][n-1]){
        cout(0);
    } else {
        dp[0][0] = 1;
        solve(n);
        cout << dp[n-1][n-1] << "\n";
    }
}

LIS 

int a[MAXN];

void solve(int n) {
    vi res;
    fr(0,n){
        auto it = lower_bound(res.begin(), res.end(), a[i]);
        if (it == res.end()){
            res.pb(a[i]);
        } else if (*it > a[i]) {
            *it = a[i];
        }
    }
    cout << res.size() << "\n";
}

int main() {
    int n;
    cin >> n;
    fr(0,n){
        cin >> a[i];
    }
    
    solve(n);
}

MINIMIZING COINS

ll dp[MAXN];
ll coins[105];

void solve(ll n, ll x) {
    ll minCant;
    fr(1,x+1){
        if (dp[i] == 1){continue;}
        minCant = inf;
        rep(j,0,n){
            if (i > coins[j]){
                minCant = min(minCant, dp[i-coins[j]] + 1);
            }
        }
        dp[i] = minCant;
    }
}

int main() {
    memset(dp, 0, sizeof dp);
    ll n,x;
    cin >> n >> x;
    fr(0,n){
        cin >> coins[i];
        dp[coins[i]] = 1;
    }

    solve(n,x);

    if (dp[x] == 0 || dp[x] == inf){
        cout("-1");
    } else {
        cout(dp[x]);
    }
}

PROJECTS

int dp[MAXN];

void solve(int n,const vector<tuple<ll,ll,ll>>& projects) {
    ll best = 0;
    map<ll, ll> dp; // {end: totalRewardSoFar}
    dp[0] = 0;
    for (auto project: projects){
        ll start, end, reward;
        tie(end, start, reward) = project;

        auto it = dp.lower_bound(start);
        it--;
        ll totalReward = it->second + reward;
        best = max(best, totalReward);
        dp[end] = best;
    }
    cout << best << "\n";
}

int main() {
    int n;
    cin >> n;
    vector<tuple<ll,ll,ll>> projects(n);
    fr(0,n){
        ll start, end, reward;
        cin >> start >> end >> reward;
        projects[i] = {end, start, reward};
    }
    sort(projects.begin(), projects.end());
    solve(n, projects);
}

REMOVAL GAME

ll dp[5002][5002];
ll a[5002];

ll solve(ll l, ll r) {
    if (dp[l][r] != -inf){
        return dp[l][r];
    }
    ll ans;
    ans = max(- solve(l+1,r) + a[l], a[r] - solve(l,r-1));
    return dp[l][r] = ans;
}

int main() {
    ll  n;
    cin >> n;
    fr(0,n){
        cin >> a[i];
    }
    ll total = 0;
    fr(0,n){
        total += ll(a[i]);
    }
    fr(0,n){
        rep(j,0,n){
            dp[i][j] = -inf;
        }
    }
    fr(0,n){
        dp[i][i] = a[i];
    }
    ll dif = solve(0,n-1);
    ll jug2 = ( total - dif ) / 2;
    cout << jug2 + dif << "\n";
}

REMOVING DIGITS

int dp[MAXN];

void solve(int n) {
    fr(1,n+1){
        for (char c: to_string(i)){
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }
    }
}

int main() {
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < MAXN; ++i) {
        dp[i] = 1e9;
    }
    dp[0] = 0;
    int n;
    cin >> n;
    
    solve(n);
    cout << dp[n] << "\n";
}

TWO SETS II

int dp[502][504*504/4];

int inv(int a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void solve(int n) {
    int m = (n * (n+1)) / 4;
    ll inversoModularDe2 = ll(inv(2));
    fr(1,n+1){
        rep(j,1,min(m+1, i * (i+1) / 2 + 1)){
            // cout << i  << ',' << j << "\n";
            if (j < i){
                dp[i][j] = dp[i-1][j] % mod;
            } else if (i == j){
                dp[i][j] = (dp[i-1][j] + 1) % mod;
            } else {
                dp[i][j] = (dp[i-1][j] % mod + dp[i-1][j-i] % mod) % mod;
            }
        }
    }
    // cout((dp[n][m] * 500000004ll) % mod); // Multiply by 500000004, which is (mod + 1) / 2 (modular inverse of 2 under the modulo 1e9+7)
    cout((dp[n][m] * inversoModularDe2) % mod);
}

int main() {
    int n; 
    cin >> n;
    if ((n * (n+1)) % 4 != 0){
        cout(0);
        return 0;
    }
    int m = (n * (n+1)) / 4;
    fr(0,n+1){
        rep(j,0,m+1){
            dp[i][j] = 0;
        }
    }
    solve(n);
}

EJERCICIOS CODEFORCES

BASKETBALL EXERCISE 1400

ll team1[MAXN];
ll team2[MAXN];
ll dp[MAXN][2];

void solve(ll n) {
    fr(1,n+1){
        dp[i][0] = max(dp[i-1][1] + team1[i-1], dp[i-1][0]);
        dp[i][1] = max(dp[i-1][0] + team2[i-1], dp[i-1][1]);
    }

    cout(max(dp[n][0], dp[n][1]));
}

int main() 

    ll n;
    cin >> n;
    fr(0,n){
        ll a;
        cin >> a;
        team1[i] = a;
    }
    fr(0,n){
        ll a;
        cin >> a;
        team2[i] = a;
    }
    fr(0,n+1){
        rep(j,0,2){
            dp[i][j] = 0;
        }
    }
    solve(n);
}

BASKETBALL TEAM 1600

int teams[MAXN];

void solve(int n, int m, int h, int total) {
    if (total < n){ // no llego a la cant suficiente de jugadores
        cout(-1);
        return;
    }
    if (teams[h] == 0){ //no tengo jugadores en el equipo
        cout(0);
        return;
    }
    if ((n-1) > total - (teams[h] + 1)){ // si o si tengo que poner los del equipo h porque sino no llego 
        cout(1);
        return;
    }

    //caso normal, sacamos probabilidades
    ld res = 1.0;
    ld productoria = 1.0;
    int cantDistintoH = total - (teams[h] + 1);
    total--;
    fr(1,n){ //necesito n-1 jugadores, xq hay uno que ya esta
        productoria *= ((ld)cantDistintoH / (ld)total);
        total--;
        cantDistintoH--;
    }
    res = res - productoria;
    cout << fixed << setprecision(6) << res;
}

int main() {
    int n, m, h;
    cin >> n >> m >> h;
    int total = 0;
    fr(1,m+1){
        int a;
        cin >> a;
        total += a;
        teams[i] = a;
        if (i == h){
            teams[i] -= 1;
        }
    }
    
    solve(n,m,h,total);
}

CONSTANZES MACHINE 1400 


void solve(string s) {
    int n = s.length();
    vector<ll> dp(n+10);
    dp[0] = 1;
    char ant = '4';
    fr(0,n){
        if (s[i] == 'm' || s[i] == 'w'){
            cout(0);
            return;
        }
        if (s[i] == 'n' && ant == 'n' || s[i] == 'u' && ant == 'u'){
            dp[i+1] = (dp[i] + dp[i-1]) % mod;
        } else {
            dp[i+1] = dp[i];
        }
        ant = s[i];
    }
    cout(dp[n]);
}

int main() {
    // devolver con mod
    string s;
    cin >> s;
    solve(s);
}

HITS DIFFERENT 1600

tuple<ll,ll,ll> dp[MAXN];

void precalc() {
    // NUMERO, NIVEL, VALOR
    dp[0] = {0,0,0};
    dp[1] = {1,1,1};
    ll actual = 2;
    ll cur = 2;
    ll nivel = 2;
    while (true){
        dp[cur] = {cur, nivel,cur*cur};
        cur+=1;
        actual-=1;
        if (actual == 0){
            nivel++;
            actual = nivel;
        }
        if (cur > 1000020){
            break;
        }
    }
    // fr(0,100){
    //     ll a, b;
    //     ll c;
    //     tie(a,b,c) = dp[i];
    //     cout << a << ' ' << b << ' ' << c;
    //     cout(' ');
    // }
}

void armardp(){
    fr(2,1000018){
        ll a, nivel;
        ll valor;
        tie(a,nivel,valor) = dp[i];
        
        if (get<1>(dp[i-1]) == nivel-1){
            get<2>(dp[i]) = valor + get<2>(dp[i-nivel+1]);
        } else if (get<1>(dp[i+1]) == nivel+1){
            get<2>(dp[i]) = valor + get<2>(dp[i-nivel]);
        } else {
            get<2>(dp[i]) = valor + get<2>(dp[i-nivel+1]) + get<2>(dp[i-nivel]) - get<2>(dp[i-(nivel-1)*2]);
        }
    }
}

int main() {

    // o(n)
    // primero precalculo el array con (nro, nivel, valor), valor en principio es el numero al cuadrado.
    precalc();
    armardp();
    // luego ya si armo la dp. O(n)
    // Si el de la izquierda es un nivel menos, solo agarro el valor del que tengo nivel-1 a la izquierda. 
    // Si el de la derecha es un nivel mas, solo agarro el valor del nivel a la izquierda. 
    // Si estoy en el medio, no hay cambio de nivel a los costados, agarro el valor del n-1 a la izquierda y tambien el del n a la izquieda.  
    
    int cases;
    cin >> cases;
    while (cases--){
        // respondo las queries en O(1)
        ll n;
        cin >> n;
        ll a, b;
        ll c;
        tie(a,b,c) = dp[n];
        cout << c << "\n";
    }
}

MULTICOLORES MARBLES 1600
ll dp[MAXN];

int inv(int a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

ll modular_expo(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
            res = ((res % mod) * (x % mod)) % mod;
        x = ((x % mod) * (x % mod)) % mod;
        n = n / 2;
    }
    return res % mod;
}

void solve(int n) {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 6;
    fr(4,n+1){
        dp[i] = (dp[i-1] + dp[i-2] + 2) %mod;
        // dp[i] = (dp[i]%mod + (modular_expo(2,n-3) % mod - 1) %mod) % mod;
    }
    cout(dp[n]);
    return;
}

int main() {
    ll n;
    cin >> n;
    solve(n);
}

NEW YEAR AND DOMINO 1500

int grid[502][502];
int dp[502][502];

void precompute(int n, int m) {
    //inicializo fila y columna 1. 
    int seguidos = 0;
    fr(1,n+1){
        if (grid[i][1] == 1){
            seguidos++;
            if (seguidos == 1){
                dp[i][1] = dp[i-1][1];
            } else {
                dp[i][1] = dp[i-1][1] + 1;
            }
        } else {
            seguidos = 0;
            dp[i][1] = dp[i-1][1];
        }
    }
    seguidos = 0;
    fr(1,m+1){
        if (grid[1][i] == 1){
            seguidos++;
            if (seguidos == 1){
                dp[1][i] = dp[1][i-1];
            } else {
                dp[1][i] = dp[1][i-1] + 1;
            }
        } else {
            seguidos = 0;
            dp[1][i] = dp[1][i-1];
        }
    }

    fr(2,n+1){
        rep(j,2,m+1){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if (grid[i][j] == 1 && (grid[i-1][j] == 1)){
                dp[i][j] += 1;
            }
            if (grid[i][j] == 1 && (grid[i][j-1] == 1)){
                dp[i][j] += 1;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    fr(1,n+1){
        rep(j,1,m+1){
            char c;
            cin >> c;
            if (c == '#'){
                grid[i][j] = 0;
            } else {
                grid[i][j] = 1;
            }
        }
    }
    precompute(n,m);
    int q;
    cin >> q;
    fr(0,q){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int res = dp[c][d];
        if ((b-1) >= 1){
            res -= dp[c][b-1];
            rep(j,a,c+1){
                if (grid[j][b-1] == 1 && (grid[j][b] == 1)){
                    res--;
                }
            }
        } 
        if ((a-1) >= 1){
            res -= dp[a-1][d];
            rep(j,b,d+1){
                if (grid[a][j] == 1 && (grid[a-1][j] == 1)){
                    res--;
                }
            }
        }
        if ((a-1) >= 1 && (b-1) >= 1){
            res += dp[a-1][b-1];
        } 
        cout(res);
    }
}