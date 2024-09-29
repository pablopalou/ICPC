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
#define MAXN 1005
int n,m;
int mat[MAXN][MAXN];

bool esP(int x, int y){
    if (x < 2) return false;
    return mat[x][y] && mat[x][y-1] && mat[x][y-2] && mat[x-1][y] && mat[x-1][y-2] && mat[x-2][y] && mat[x-2][y-1] && mat[x-2][y-2] && mat[x+1][y-2] && mat[x+2][y-2];
    // bool res = true;
    // fr(1,5){
    //     if (!mat[x-i][y]){
    //         res = false;
    //     }
    // }
    // x-=4;
    // y+=1;
    // res = res && mat[x][y] && mat[x][y+1] && mat[x+1][y+1] && mat[x+2][y] && mat[x+2][y+1];
    // return res;
}

void borrarP(int x, int y){
    mat[x][y]=false;
    mat[x][y-1]=false;
    mat[x][y-2]=false;
    mat[x-1][y]=false;
    mat[x-1][y-2]=false;
    mat[x-2][y]=false;
    mat[x-2][y-1]=false;
    mat[x-2][y-2]=false;
    mat[x+1][y-2]=false;
    mat[x+2][y-2]=false;
    // mat[x][y] = 2;
    // fr(1,5){
    //     mat[x-i][y] = 2;
    // }
    // x-=4;
    // y+=1;
    // mat[x][y]  =2;
    // mat[x][y+1]  =2;
    // mat[x+1][y+1]  =2;
    // mat[x+2][y]  =2;
    // mat[x+2][y+1] =2;

}

bool esA(int x, int y){
    if (x < 4) return false;
    return mat[x][y] && mat[x][y-2] && mat[x-1][y] && mat[x-1][y-2] && mat[x-2][y] && mat[x-2][y-1] && mat[x-2][y-2] && mat[x-3][y] && mat[x-3][y-2] && mat[x-4][y] && mat[x-4][y-1] && mat[x-4][y-2]; 
    //me tengo que asegurar que puede estar una A. 
    // bool res = true;
    // fr(1,5){
    //     if (!mat[x-i][y]){
    //         res = false;
    //     }
    // }
    // fr(0,5){
    //     if (!mat[x-i][y-2]){
    //         res = false;
    //     }
    // }
    // res = res && mat[x-2][y-1] && mat[x-4][y-1];
    // return res;
}

void borrarA(int x, int y){
    mat[x][y]=false;
    mat[x][y-2]=false;
    mat[x-1][y]=false;
    mat[x-1][y-2]=false;
    mat[x-2][y]=false;
    mat[x-2][y-1]=false;
    mat[x-2][y-2]=false;
    mat[x-3][y]=false;
    mat[x-3][y-2]=false;
    mat[x-4][y]=false;
    mat[x-4][y-1]=false;
    mat[x-4][y-2]=false;
    // mat[x][y] = 2;
    // fr(1,5){
    //     mat[x-i][y] = 2;
    // }
    // fr(0,5){
    //     mat[x-i][y-2] = 2;
    // }
    // mat[x-2][y-1] = 2;
    // mat[x-4][y-1] = 2;
    // cout << "cant borrar en A -> " << cantBorrar << endl;
}

bool esT(int x, int y){
    return mat[x][y] && mat[x][y-1] && mat[x][y-2] && mat[x+1][y-1] && mat[x+2][y-1] && mat[x+3][y-1] && mat[x+4][y-1];
    // cout << "verifico T "<< endl;
    // bool res = true;
    // fr(1,5){
    //     if (!mat[x-i][y]){
    //         res = false;
    //     }
    // }
    // x-=4;
    // res = res && mat[x][y-1] && mat[x][y+1];
    // return res;
}

void borrarT(int x, int y){
    mat[x][y]=false;
    mat[x][y-1]=false;
    mat[x][y-2]=false;
    mat[x+1][y-1]=false;
    mat[x+2][y-1]=false;
    mat[x+3][y-1]=false;
    mat[x+4][y-1]=false;
    // mat[x][y] = 2;
    // fr(1,5){
    //     mat[x-i][y] = 2;
    // }
    // x-=4;
    // mat[x][y-1] =2;
    // mat[x][y+1]=2;
}

void solve() {
    cin >> n >> m;
    int cantT, cantA, cantP;
    cantT = 0;
    cantA = 0;
    cantP = 0;
    fr(0,MAXN){
        rep(j,0,MAXN){
            mat[i][j] = 0;
        }
    }
    fr(0,n){
        rep(j,0,m){
            char c; cin >> c;
            if (c == '#'){
                mat[i][j] = 1;
            }
        }
    }

    for(int j=m-1; j>=2; j--){
        for(int i=n-1;i>=0;i--){
            if (mat[i][j] == 1){
                if (esP(i,j)){
                    cantP++;
                    borrarP(i,j);
                } else if (esA(i,j)){
                    cantA++;
                    borrarA(i,j);
                } else if (esT(i,j)){
                    cantT++;
                    borrarT(i,j);
                }
            }
        }
    }
    cout << cantT <<" " << cantA <<" "<< cantP <<'\n';
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