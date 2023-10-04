#include<bits/stdc++.h>
using namespace std;

#define fr(a,b) for(int i = a; i<b; i++)
#define int long long
#define endl '\n'

const int mxN = 1e5+5;
int sa[mxN], pos[mxN], tmp[mxN], lcp[mxN];
int gap, N;
string S;

bool comp(int x, int y) {
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}

void suffix() {
    for (int i = 0; i < N; i++)
        sa[i] = i, pos[i] = S[i];

    for (gap = 1;; gap <<= 1) {
        sort(sa, sa+N, comp);
        for (int i = 0; i < N-1; i++)
            tmp[i+1] = tmp[i] + comp(sa[i], sa[i+1]);
        for (int i = 0; i < N; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}

void print()
{
    fr(0, N)
        cout << i << " " << S.substr(sa[i], S.find('$', sa[i]) - sa[i]) << endl;
}

void printLCP()
{
    fr(0, N) {
        cout << lcp[i] << " ";
    }
}

void build_lcp() {
    for (int i = 0, k = 0; i < N; i++) if (pos[i] != N-1) {
        int j = sa[pos[i] + 1];
        while (S[i + k] == S[j + k])
            k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin>>S; N = S.size();
    suffix();
    build_lcp();
    int sm = accumulate(lcp, lcp+N, 0LL);
    cout << N*(N+1)/2 - sm;
}

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define pb push_back
// #define fr(a, b) for (int i = a; i < b; i++)
// #define forr(i,a,b) for(int i=(a); i<(b); i++)
// #define forn(i,n) forr(i,0,n)
// #define rep(i, a, b) for (int i = a; i < b; i++)
// #define mod 1000000007
// #define inf (1LL << 60)
// #define prDouble(x) cout << fixed << setprecision(10) << x
// #define triplet pair<ll, pair<ll, ll>>

// #define MAX_N 100100
// // #define rBOUND(x) (x < n - 1 ? r[x] : 0)
// #define rBOUND(x) (x < n ? r[x] : 0)

// int sa[MAX_N], r[MAX_N], n;
// string s; // input string, n=s.size()
// int f[MAX_N], tmpsa[MAX_N];

// int LCP[MAX_N], phi[MAX_N], PLCP[MAX_N];

// void countingSort(int k)
// {
//     memset(f, 0, sizeof(f));
//     forn(i, n) f[rBOUND(i + k)]++;
//     int sum = 0;
//     forn(i, max(255, n))
//     {
//         int t = f[i];
//         f[i] = sum;
//         sum += t;
//     }
//     forn(i, n)
//         tmpsa[f[rBOUND(sa[i] + k)]++] = sa[i];
//     memcpy(sa, tmpsa, sizeof(sa));
// }

// void constructsa()
// {
//     n = s.size();
//     forn(i, n) sa[i] = i, r[i] = s[i];
//     for (int k = 1; k < n; k <<= 1)
//     {
//         countingSort(k), countingSort(0);
//         int rank, tmpr[MAX_N];
//         tmpr[sa[0]] = rank = 0;
//         for (int i = 1; i < n; i++)
//         {
//             tmpr[sa[i]] = (r[sa[i]] == r[sa[i - 1]] && r[sa[i] + k] == r[sa[i - 1] + k])
//                               ? rank
//                               : ++rank;
//         }
//         memcpy(r, tmpr, sizeof(r));
//         if (r[sa[n - 1]] == n - 1) break;
//     }
// }
// // void computeLCP(){
// //     phi[sa[0]]=-1;
// //     forr(i,1,n) phi[sa[i]]=sa[i-1];
// //     int L=0;
// //     forn(i,n){
// //         if (phi[i]==-1){
// //             PLCP[i]=0;
// //             continue;
// //         }
// //         while(s[i+L]==s[phi[i]+L]){
// //             L++;
// //         }
// //         PLCP[i] = L;
// //         L = max(L-1,0);
// //     }
// //     forn(i,n) LCP[i] = PLCP[sa[i]];
// // }
// void computeLCP() {
//     phi[sa[0]] = -1;
//     forr(i, 1, n) phi[sa[i]] = sa[i - 1];
//     int L = 0;
//     forn(i, n) {
//         if (phi[i] == -1) {
//             PLCP[i] = 0;
//             continue;
//         }
//         while (i + L < n && phi[i] + L < n && s[i + L] == s[phi[i] + L]) {
//             L++;
//         }
//         PLCP[i] = L;
//         L = max(L - 1, 0);
//     }
//     forn(i, n) LCP[i] = PLCP[sa[i]];
// }

// void print()
// {
//     forn(i, n)
//         cout << i << " " << s.substr(sa[i], s.find('$', sa[i]) - sa[i]) << endl;
// }

// void printLCP()
// {
//     forn(i, 10) {
//         cout << LCP[i] << " ";
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> s;
//     n = s.size() - 1;
//     constructsa();
//     computeLCP();
//     // printLCP();
//     // Add your test input and function calls here
//     ll iguales = 0;
//     forr(i,1,n){
//         iguales += LCP[i];
//     }
//     ll posibles = (static_cast<ll>(n) * (n+1)) / 2;
//     // cout << posibles << "\n";
//     // cout << iguales << "\n";
//     cout << posibles - iguales << "\n";
//     return 0;
// }
