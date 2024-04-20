#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

const ll MAXN = 1e3 + 5;
ll A[MAXN][MAXN];

// Copiar obligatoriamente 0
void solve() {
    ll n,k; cin >> n>>k;
    vector<ll> dp[n+1];
    fr(1,n+1){
        rep(j,i,n+1){
            cin >> A[i][j];
        }
    }
    // dp[i] es la respuesta si consideramos hasta i
    dp[0] = {0}; //podemos formar 0 sin tener nada.
    //ahora tengo que llenar la dp de forma relativamente rapida.
    fr(1,n+1){
        priority_queue<array<ll,3> > pq;
        //tengo que meter uno de cada uno de los anteriores (dp 0 a i-1)
        //el i-1 lo dejo como esta, no creo nada
        pq.push({dp[i-1][0], i-1, 0});
        rep(j,-1,i-1){
            if (j == -1){
                pq.push({A[j+2][i] , j, 0});
            } else {
                pq.push({dp[j][0] + A[j+2][i] , j, 0});
            }
        }
        //luego un while el size de la dp sea menor a k (y tenga cosas en la pq), voy poniendo el mas grande y pongo el proximo de ese indice
        while( !pq.empty() && dp[i].size() < k){
            auto [val, index, pos] = pq.top();
            pq.pop();
            dp[i].pb(val);
            //ahi ya meti el valor del tope, ahora tengo que meter de esa misma fila uno mas
            //primero chequeo que el index no sea negativo y que no haya terminado en esa lista
            if (index < 0 || ((pos + 1) >= dp[index].size())){
                continue;
            }
            //ahora si seguro puedo agregar, tengo que fijarme si pinte el ultimo o no basicamente
            if ( index == i-1){
                pq.push({dp[index][pos+1], index, pos+1});
            } else {
                pq.push({dp[index][pos+1] + A[index+2][i], index, pos+1});
            }
        }
    }


    for(auto i : dp[n]){
        cout << i << ' ';
    }
    cout << endl;
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
 
// void solve(){
//     int n, k;
//     cin >> n >> k;
 
//     int A[n + 1][n + 1];
 
//     for (int i = 1; i <= n; i++)
//         for (int j = i; j <= n; j++)
//             cin >> A[i][j];
    
//     // dp[i] = Answer if we consider 1...i
//     vector<int> dp[n + 1];
//     dp[0] = {0};
 
    // for (int i = 1; i <= n; i++){
        // priority_queue<array<int, 3> > pq;
 
        // // Don't create an interval
        // pq.push({dp[i - 1][0], i - 1, 0});
 
        // // Create interval j+2...i (transition from j)
        // for (int j = i - 2; j >= -1; j--){
        //     pq.push({(j < 0 ? 0 : dp[j][0]) + A[j + 2][i], j, 0});
        // }
 
        // while (pq.size() and dp[i].size() < k){
        //     auto [val, j, num] = pq.top(); pq.pop();
        //     dp[i].push_back(val);
            
        //     if (j < 0 or num + 1 >= dp[j].size())
        //         continue;
            
        //     // Don't create interval
        //     if (j == i - 1)
        //         pq.push({dp[i - 1][num + 1], i - 1, num + 1});
            
        //     // Create interval j+2...i (transition from j)
        //     else 
        //         pq.push({dp[j][num + 1] + A[j + 2][i], j, num + 1});
        // }
    // }
//     for (int i : dp[n])
//         cout << i << " ";
//     cout << "\n";
// }
 
// int main(){
//     ios_base::sync_with_stdio(0); cin.tie(0); 
//     int tc; 
//     cin >> tc;
 
//     while (tc--) 
//         solve();
// }