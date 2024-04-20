#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

#ifdef NANO
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;


typedef ll tipo;  // maybe use double or other depending on the problem

const ll MOD = 1'000'000'007;
struct Mat {
  int N;  // square matrix
  vector<vector<tipo>> m;
  Mat(int n) : N(n), m(n, vector<tipo>(n, 0)) {}
  vector<tipo>& operator[](int p) { return m[p]; }
  Mat operator*(Mat& b) {  // O(N^3), multiplication
    assert(N == b.N);
    Mat res(N);
    forn(i, N) forn(j, N) forn(k, N)  // remove MOD if not needed
        res[i][j] = (res[i][j] + m[i][k] * b[k][j]) % MOD;
    return res;
  }
  Mat operator^(int k) {  // O(N^3 * logk), exponentiation
    Mat res(N), aux = *this;
    forn(i, N) res[i][i] = 1;
    while (k)
      if (k & 1) res = res * aux, k--;
      else aux = aux * aux, k /= 2;
    return res;
  }
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	int n,m;
	cin>>n>>m;
	
	Mat mat(m);
	
	for(int i = 0; i<=m-1; i++){
		for(int j = 0; j<=m-1; j++){
			if(gcd(i+1,j+1) == 1) mat[i][j] = 1;
		}
	}
	
	for(int i = 0; i<=m-1; i++) mat[0][i] = 1;

	mat = mat^(n-1);
	ll ans = 0;
	for(int i = 0; i<=m-1;i++){
		for(int j = 0; j<=m-1; j++){
			ans = (ans +  mat[i][j] ) % MOD;
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}
