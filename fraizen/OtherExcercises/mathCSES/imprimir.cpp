MATEMATICA ALGORITMOS

GCD (MINIMO COMUN DIVISOR)

// Function to return
// gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


CRIBA DE ERASTOTENES

bitset<500001> Primes;
void SieveOfEratosthenes(int n)
{
    Primes[0] = 1;
    for (int i = 3; i*i <= n; i += 2) {
        if (Primes[i / 2] == 0) {
            for (int j = 3 * i; j <= n; j += 2 * i)
                Primes[j / 2] = 1;
        }
    }
}
  
int main()
{
    int n = 100;
    SieveOfEratosthenes(n);
    for (int i = 1; i <= n; i++) {
        if (i == 2)
            cout << i << ' ';
        else if (i % 2 == 1 && Primes[i / 2] == 0)
            cout << i << ' ';
    }
    return 0;
}


// CRIBA DE ERASTOTENES MODIFICADA 
// Criba de eratóstenes pero guardando el mínimo primo que divide al número, pero luego conseguir los primos (no la factorización, solo los primos).

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())
const int N = int(1e7) + 5;

int mind[N];

void precalc() {
	fore (i, 0, N)
		mind[i] = i;
	
	for (int p = 2; p < N; p++) {
		if (mind[p] != p)
			continue;
		for (int d = 2 * p; d < N; d += p)
			mind[d] = min(mind[d], p);
	}
}

vector<int> getPrimes(int v) {
	vector<int> ps;
	while (v > 1) {
		if (ps.empty() || ps.back() != mind[v])
			ps.push_back(mind[v]);
		v /= mind[v];
	}
	return ps;
}

COMBINACION MODULO P

// Código que use para calcular una combinación modulo p y anduvo joya (ni idea para usar más):
// Time Complexity: O(n)
// Auxiliary Space: O(n)
// (hay mejores(en espacio seguro) y se podrian precomputar los factoriales etc..)

unsigned long long power(unsigned long long x,
int y, int p)
{
unsigned long long res = 1; // Initialize result
x = x % p; // Update x if it is more than or
// equal to p
while (y > 0)
{
// If y is odd, multiply x with result
if (y & 1)
res = (res * x) % p;
// y must be even now
y = y >> 1; // y = y/2
x = (x * x) % p;
}
return res;
}
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,
int p)
{
return power(n, p - 2, p);
}
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
int r, int p)
{
// If n<r, then nCr should return 0
if (n < r)
return 0;
// Base case
if (r == 0)
return 1;
// Fill factorial array so that we
// can find all factorial of r, n
// and n-r
unsigned long long fac[n + 1];
fac[0] = 1;
for (int i = 1; i <= n; i++)
fac[i] = (fac[i - 1] * i) % p;
return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p)% p;
}

// OTRA FORMA DE CALCULAR COMBINACIONES

O(p^2 * (Log_p n)) time
O(r) space

// A Lucas Theorem based solution to compute nCr % p
#include<bits/stdc++.h>
using namespace std;
  
// Returns nCr % p.  In this Lucas Theorem based program,
// this function is only called for n < p and r < p.
int nCrModpDP(int n, int r, int p)
{
    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    int C[r+1];
    memset(C, 0, sizeof(C));
  
    C[0] = 1; // Top row of Pascal Triangle
  
    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (int i = 1; i <= n; i++)
    {
        // Fill entries of current row using previous
        // row values
        for (int j = min(i, r); j > 0; j--)
  
            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}
  
// Lucas Theorem based function that returns nCr % p
// This function works like decimal to binary conversion
// recursive function.  First we compute last digits of
// n and r in base p, then recur for remaining digits
int nCrModpLucas(int n, int r, int p)
{
   // Base case
   if (r==0)
      return 1;
  
   // Compute last digits of n and r in base p
   int ni = n%p, ri = r%p;
  
   // Compute result for last digits computed above, and
   // for remaining digits.  Multiply the two results and
   // compute the result of multiplication in modulo p.
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits
}


EXPONENCIACION MODULAR

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

//otra forma o algo de eso 

/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(long long x, unsigned int y, int p)
{
    int res = 1; 	// Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}


INVERSO MODULAR


int inv(int a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

//otra forma (inversom odulo A en O(logM) si m y a son coprimos)

int gcdExtended(int a, int b, int* x, int* y);
 
// Function to find modulo inverse of a
void modInverse(int A, int M)
{
    int x, y;
    int g = gcdExtended(A, M, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else {
 
        // m is added to handle negative x
        int res = (x % M + M) % M;
        cout << "Modular multiplicative inverse is " << res;
    }
}
 
// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y)
{
 
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
 
    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}

FACTORIALES PRECOMPUTADOS

ll factorials[MAXN];
void precompute() {
    factorials[0] = factorials[1] = 1;
    fr(2,MAXN){
        factorials[i] = (factorials[i-1] % mod * i % mod) % mod;
    }
}

CALCULO DE FUNCION PHI, CANTIDAD DE COPRIMOS

int phi(int n)
{
    // Initialize result as n
    int result = n;
  
    // Consider all prime factors of n
    // and subtract their multiples
    // from result
    for(int p = 2; p * p <= n; ++p)
    {
         
        // Check if p is a prime factor.
        if (n % p == 0)
        {
             
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
                 
            result -= result / p;
        }
    }
  
    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
         
    return result;
}

TRIANGULO DE PASCAL EN O(N) Y espacio O(1)

void printPascal(int n)
{ 
    for (int line = 1; line <= n; line++)
    {
        int C = 1; // used to represent C(line, i)
        for (int i = 1; i <= line; i++) 
        {
            
            // The first value in a line is always 1
            cout<< C<<" "; 
            C = C * (line - i) / i; 
        }
        cout<<"\n";
}

TEOREMA CHINO DEL RESTO

Time Complexity  : O(M), M is the product of all elements of num[] array.
Auxiliary Space : O(1)

// k is size of num[] and rem[].  Returns the smallest
// number x such that:
//  x % num[0] = rem[0], 
//  x % num[1] = rem[1], 
//  ..................
//  x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime 
// (gcd for every pair is 1)
int findMinX(int num[], int rem[], int k)
{
    int x = 1; // Initialize result
  
    // As per the Chinese remainder theorem,
    // this loop will always break.
    while (true)
    {
        // Check if remainder of x % num[j] is 
        // rem[j] or not (for all j from 0 to k-1)
        int j;
        for (j=0; j<k; j++ )
            if (x%num[j] != rem[j])
               break;
  
        // If all remainders matched, we found x
        if (j == k)
            return x;
  
        // Else try next number
        x++;
    }
  
    return x;
}
  
// Driver method
int main(void)
{
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = sizeof(num)/sizeof(num[0]);
    cout << "x is " << findMinX(num, rem, k);
    return 0;
}


Criba de eratóstenes hasta cierto límite. (Sirve cuando el array de O(n) se pasa de memoria)

Time Complexity : O(n * ln(sqrt(n)))
Auxiliary Space: O(sqrt(n))

// This functions finds all primes smaller than 'limit'
// using simple sieve of eratosthenes. It also stores
// found primes in vector prime[]
void simpleSieve(int limit, vector<int> &prime)
{
    // Create a boolean array "mark[0..n-1]" and initialize
    // all entries of it as true. A value in mark[p] will
    // finally be false if 'p' is Not a prime, else true.
    vector<bool> mark(limit + 1, true);
 
    for (int p=2; p*p<limit; p++)
    {
        // If p is not changed, then it is a prime
        if (mark[p] == true)
        {
            // Update all multiples of p
            for (int i=p*p; i<limit; i+=p)
                mark[i] = false;
        }
    }
 
    // Print all prime numbers and store them in prime
    for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            cout << p << " ";
        }
    }
}
 
// Prints all prime numbers smaller than 'n'
void segmentedSieve(int n)
{
    // Compute all primes smaller than or equal
    // to square root of n using simple sieve
    int limit = floor(sqrt(n))+1;
    vector<int> prime;
    prime.reserve(limit);
    simpleSieve(limit, prime);
 
    // Divide the range [0..n-1] in different segments
    // We have chosen segment size as sqrt(n).
    int low = limit;
    int high = 2*limit;
 
    // While all segments of range [0..n-1] are not processed,
    // process one segment at a time
    while (low < n)
    {
        if (high >= n)
           high = n;
         
        // To mark primes in current range. A value in mark[i]
        // will finally be false if 'i-low' is Not a prime,
        // else true.
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        // Use the found primes by simpleSieve() to find
        // primes in current range
        for (int i = 0; i < prime.size(); i++)
        {
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i] (divisible by prime[i])
            // For example, if low is 31 and prime[i] is 3,
            // we start with 33.
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
 
            /* Mark multiples of prime[i] in [low..high]:
                We are marking j - low for j, i.e. each number
                in range [low, high] is mapped to [0, high-low]
                so if range is [50, 100] marking 50 corresponds
                to marking 0, marking 51 corresponds to 1 and
                so on. In this way we need to allocate space only
                for range */
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
 
        // Numbers which are not marked as false are prime
        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
                cout << i << " ";
 
        // Update low and high for next segment
        low = low + limit;
        high = high + limit;
    }
}

____________________________________________

MATEMATICA CSES

BINOMIAL COEFFICIENTS

ll factorials[MAXN];

int inv(int a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void precompute() {
    factorials[0] = factorials[1] = 1;
    fr(2,MAXN){
        factorials[i] = (factorials[i-1] % mod * i % mod) % mod;
    }
}

int main() {
    precompute();
    ll n;
    cin >> n;
    fr(0,n){
        int a, b;
        cin >> a >> b;
        ll ans = ((factorials[a]%mod * ll(inv(factorials[b]))) % mod * ll(inv(factorials[a-b]))) % mod;
        cout(ans);
    }
}

CHRISTMAS PARTY


int main() {
    ll n;
    cin >> n;
    ll d[n+1];
    d[1] = 0;
    d[2] = 1;
    fr(3,n+1){
        d[i] = ((d[i-1] + d[i-2]) * (i-1)) % mod;
    }
    
    cout(d[n]);
}

CREATING STRING

ll factorials[MAXN];

int inv(int a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void precompute() {
    factorials[0] = factorials[1] = 1;
    fr(2,MAXN){
        factorials[i] = (factorials[i-1] * i) % mod;
    }
}

int main() {
    precompute();
    string s;
    cin >> s;
    map<char, int> m;
    for (char c: s){
        m[c]++;
    }
    ll denominador = 1;
    for (const auto& e : m){
        denominador = (denominador * factorials[e.second]) % mod;
    }
    cout((factorials[s.length()] * inv(denominador)) % mod);
}

DICE PROBABILITY

db dp[102][610];
void solve() {

}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    
    fr(0,n+1){
        rep(j,1, 6*n+1){
            dp[i][j] = 0.0;
        }
    }
    dp[0][0] = 1.0;
    
    fr(1,n+1){
        rep(j,1,6*n + 1){
            rep(k,1,7){
                if (j-k >=0){
                    dp[i][j] += dp[i-1][j-k];
                }
            }
            dp[i][j] /= 6;
        }
    }
    db ans = 0;
    fr(a,b+1){
        ans += dp[n][i];
    }
    ans *= 1e6;
    ans = llround(ans);
    ans /= 1e6;
    cout << fixed << setprecision(6) << ans;
}

DISTRIBUTING APPLES

ll factorials[MAXN];

int inv(int a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void precompute() {
    factorials[0] = factorials[1] = 1;
    fr(2,MAXN){
        factorials[i] = (factorials[i-1] % mod * i % mod) % mod;
    }
}

int main() {
    precompute();
    int n,m;
    cin >> n >> m;
    
    ll denominador = (factorials[m] * factorials[n-1]) % mod;
    cout((factorials[n+m-1] * inv(denominador))%mod);
}

FIBONACCI NUMBERS

struct M22{
    ll a,b,c,d;
    M22 operator*(const M22 &p) const {
        return (M22){(a*p.a + b*p.c)%mod, (a*p.b + b*p.d)%mod, (c*p.a + d*p.c)%mod, (c*p.b + d*p.d)%mod};
    }
};

M22 operator^ (const M22 &p, ll n){
    if (!n) return (M22){1,0,0,1}; //identidad
    M22 q=p^(n/2); q = q * q;
    return n%2 ? p*q: q;
}


void solve(ll n) {
    M22 mat = (M22){1,1,1,0}^n;
    cout(mat.b%mod);
}

int main() {
    ll n;
    cin >> n;
    
    solve(n);
}

INVERSION PROBABILITY

int a[102];

void solve(ll n) {
    db ans = 0.0;
    fr(0,n){
        for(int j = i+1; j < n; j++){
            ll cur = 0;
            if (a[j] < a[i]){
                cur += (a[i] - a[j]) * a[j];
                cur += (a[j] * (a[j] - 1)) / 2;
            } else {
                cur += (a[i] * (a[i] - 1)) / 2;
            }
            // cout << "Pair (" << i << ',' << j << ") tiene: " << cur << "\n";
            ans += (db)cur / (db)(a[j] * a[i]);
        }
    }

    cout << fixed << setprecision(6) << ans;
}

int main() {
    ll n;
    cin >> n;
    fr(0,n){
        cin >> a[i];
    }
    solve(n);
}

NIM GAME

int sticks[MAXN];

void solve(int n) {
    ll ans = 0;
    fr(0,n){
        ans ^= sticks[i];
    }
    cout << (ans == 0 ? "second" : "first") << "\n";
}

int main() {
    int cases;
    cin >> cases;
    int n;
    while (cases--){
        cin >> n;
        fr(0,n){
            cin >> sticks[i];
        }
        solve(n);
    }
}

NIM GAME II

int sticks[MAXN];

void solve(int n) {
    ll ans = 0;
    fr(0,n){
        ans ^= sticks[i];
    }
    cout << (ans == 0 ? "second" : "first") << "\n";
}

int main() {
    int cases;
    cin >> cases;
    int n;
    while (cases--){
        cin >> n;
        fr(0,n){
            cin >> sticks[i];
            sticks[i] %= 4;
        }
        solve(n);
    }
}

PRIME MULTIPLES

ll sumar(int mask, int k, vector<ll>& primes, ll n){
    ll prod = 1;
    fr(0,k){
        if ((1 << i) & mask){
            if (prod > n / primes[i]) {
                // Overflow detected, break out of the loop
                return 0;
            }
            prod *= primes[i];
        }
    }
    return __builtin_popcount(mask) & 1 ? n/prod : -n/prod;
}

int main() {
    ll n;
    int k;
    cin >> n >> k;
    vector<ll> primes(k);
    fr(0,k){
        cin >> primes[i]; 
    }
    ll ans = 0;
    rep(mask, 1, 1<<k){
        // cout("Sumo:");
        // cout(sumar(mask, k, primes, n));
        ans += sumar(mask, k, primes, n);
    }
    cout(ans);
}


STICK GAME

bool dp[MAXN];
int a[102];

void solve(int n, int k) {
    fr(1,n+1){
        rep(j, 0, k){
            if (dp[i]){
                break;
            }
            if (i - a[j] >= 0 && (!dp[i-a[j]])){
                dp[i] = true;
            }
        }
    }

    fr(1,n+1){
        cout << ((dp[i] == 1) ? "W" : "L");
    }
}

int main() {
    memset(dp,false,sizeof(dp));
    int n,k;
    cin >> n >> k;
    fr(0,k){
        cin >> a[i];
        dp[a[i]] = 1;
    }
    
    solve(n,k);
}

SUM OF DIVISORS


int power(long long x, unsigned int y, int p)
{
    int res = 1; 	// Initialize result
    x = x % p; // Update x if it is more than or
                // equal to p
    if (x == 0) return 0; // In case x is divisible by p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1,j; i<=n; i=j){
        ll q = n/i;
        j = n/q + 1;
        ll rangeSumUpToJminus1 = ((((j%mod) * ((j-1)%mod)) % mod) * (power(2,mod-2, mod)))%mod;
        ll rangeSumUpToIminus1 = ((((i%mod) * ((i-1)%mod)) % mod) * (power(2,mod-2, mod)))%mod;
        ll rangeWithQuotientQ = (rangeSumUpToJminus1 - rangeSumUpToIminus1 + mod) % mod;
        ans = (ans + (q%mod) * (rangeWithQuotientQ)) % mod;
    }
    
    cout(ans);
}

THROWING DICE (CON EXPONENCIACION DE MATRIZ EN O(LOG N))

#define SIZE 6

// cambiar por matriz de transformacion
ll matrix[SIZE][SIZE] = {
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
};

void multiply(ll a[SIZE][SIZE], ll b[SIZE][SIZE]) {
    ll result[SIZE][SIZE] = {0};
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result[i][j] = (result[i][j] %mod + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            a[i][j] = result[i][j] % mod;
        }
    }
}

void matrix_pow(ll a[SIZE][SIZE], ll n) {
    // cambiar por matriz de transformacion
    ll result[SIZE][SIZE] = {
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1}
    };
    while (n > 0) {
        if (n % 2 == 1) {
            multiply(result, a);
        }
        multiply(a, a);
        n /= 2;
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            a[i][j] = result[i][j] % mod;
        }
    }
}

int main() {
    ll n;
    cin >> n;
    if (n <= SIZE) {
        cout << (1 << (n - 1)) << endl;
    } else {
        matrix_pow(matrix, n - SIZE);
        ll ans = 0;
        // Aca lo que hace es multiplicar por el vector
        // Justo en este caso es 1,2,4,8,16,32 y por eso hace (1<<i)
        // en realidad aca tenemos que multiplicar por el vector inicial que tengamos (casos base)
        for (int i = 0; i < SIZE; i++) {
            ans = (ans + (matrix[5][i] * (1 << i))%mod) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}


MATH CODEFORCES 

FACTORIAL DIVISIBILITY (number theory)

int cant[MAXN];

void solve() {

}

int main() {
    int n, k;
    cin >> n >> k;
    memset(cant, 0, sizeof(cant));
    fr(0,n){
        int a;
        cin >> a;
        cant[a]++;
    }
    
    fr(0,k){
        while (cant[i] > i){
            cant[i] -= i+1;
            cant[i+1]++;
        }
    }
    fr(0,k){
        if (cant[i] != 0){
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes" << "\n";
}

LUCKY CHAINS (number theory, 1600)

const int N = int(1e7) + 5;

int mind[N];

void precalc(){
    fore(i,0,N){
        mind[i] = i;
    }
    for(int p = 2; p < N; p++){
        if (mind[p] != p)
            continue;
        for(int d=2*p; d < N; d+=p)
            mind[d] = min(mind[d],p);
    }
}

vector<int> getPrimes(int v){
    vector<int> ps;
    while (v > 1){
        if (ps.empty() || ps.back() != mind[v])
            ps.push_back(mind[v]);
        v/=mind[v];
    }
    return ps;
}

void solve(int x, int y) {
    int d  = y-x;
    if (d == 1){
        cout << -1 << "\n";
        return;
    }
    int r = 1e9+8;
    for (int p: getPrimes(d)){
        r = min(r, ((x+p-1)/p)*p);
    }
    cout << r - x << "\n";
}

int main() {
    precalc();
    int cases;
    cin >> cases;
    while(cases--){
        int x, y;
        cin >> x >> y;
        solve(x,y);
    }
}

BICYCLE RACE (GEOMETRY, 1500)


struct P {
    int x,y;
    void read(){
        cin >> x >> y;
    }
    P operator - (const P& b) const{
        return P{x-b.x, y -b.y};
    }
    void operator -=(const P& b){
        x -= b.x;
        y -= b.y;
    }
    ll operator * (const P& b) const{
        return (ll) x*b.y - (ll) y * b.x;
    }
};

void solve() {

}

int main() {
    int n;
    cin >> n;
    
    P p1,p2,p3,p4;
    p1.read();
    p2.read();
    p3.read();
    ll cross_product = (p2-p1) * (p3 - p1);
    int res = 0;
    if (cross_product > 0){
        res+=1;
    }
    fr(4,n+1){
        p1 = p2;
        p2 = p3;
        p3.read();
        cross_product = (p2-p1) * (p3 - p1);
        if (cross_product > 0){
            res+=1;
        }
    }
    cout(res);
}

GARAGE (1500)

int n;
    cin >> n;
    if (n==1){
        cout(3);
        return 0;
    }
    cout(3 + 4 * (n/3) + n%3);

POLYCARP RESTORES PERMUTATION


int main() {
    int n;
    cin >> n;
    vector<int> v(n-1);
    fr(0,n-1){
        int b;
        cin >> b;
        v[i] = b;
    }
    vector<ll> prefix(n-1,0);
    prefix[0] = v[0];
    ll maximo = max(0,v[0]);
    ll minimo = min(0,v[0]);
    fr(1,n-1){
        prefix[i] = prefix[i-1] + v[i];
        if (prefix[i] > maximo){
            maximo = prefix[i];
        } else if (prefix[i] < minimo){
            minimo = prefix[i];
        }
    }

// cout(maximo);
// cout(minimo);
// cout(n-1);
    if (maximo - minimo > n-1){
        cout("-1");
        return 0;
    }

    set<int> s;
    int inicio = maximo > 0 ? n-maximo : n ;
    vector<int> res(n);
    res[0] = inicio;
    int cur = inicio;
    s.insert(inicio);
    fr(1,n){
        res[i] = cur + v[i-1];
        cur = res[i];
        if (s.find(cur) == s.end()){
            s.insert(cur);
        } else {
            cout("-1");
            return 0;
        }
    }

    fr(0,n){
        cout << res[i] << ' ';
    }
}

RANDOM EVENTS (PROBABILITY, 1500)

void solve(int n, int m, vector<ll> arr, vector<pair<ll,d>> prob) {
    ll cur = n;
    while (cur >= 1 && cur == arr[cur-1]){
        cur--;
    }
    if (cur == 0){
        prDouble(1.0);
        cout << "\n";
        return;
    }
    d res = 1.0;
    ll pos;
    d p;
    fr(0,m){
        pos= prob[i].first;
        p= prob[i].second;
        if (pos < cur){
            continue;
        }
        // cout << "Multiplico por 1-" << p << "\n";
        res *= (1-p);
    }
    prDouble(1- res);
    cout << "\n";
}

int main() {
    int cases;
    cin >> cases;
    while (cases--){
        int n, m;
        cin >> n >> m;
        vector<ll> arr(n);
        fr(0,n){
            ll a;
            cin >> a;
            arr[i] = a; 
        }
        vector<pair<ll,d>> prob(m);
        fr(0,m){
            ll pos;
            d p;
            cin >> pos >> p;
            prob[i] = make_pair(pos, p);
        }
        solve(n,m ,arr, prob);
    }
}

TRIANGLE COLORING (COMBINACIONES, 1600)


unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, 
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

int main() {
    ll mul = 1;
    int n;
    cin >> n;

    fr(0,n/3){
        int a,b,c;
        cin >> a >> b >> c;
        if (a==b && b==c){
            mul = (mul * 3) % mod;
        } else if ((a > b && b == c) || (b > a && a == c) || (c > a && b == a)){
            mul = (mul * 2) % mod;
        }
    }
    
    int combinaciones = nCrModPFermat(n/3,n/6,mod);
    cout << ((combinaciones * mul) % mod);
}

