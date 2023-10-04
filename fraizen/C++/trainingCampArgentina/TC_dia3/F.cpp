#include <bits/stdc++.h>
#include <sstream>

#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(),(x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno << ": " 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    char a1,a2;
    cin >> n;
    int res = 0;
    int cantA = 0;
    int cantB = 0;
    stringstream strFinal;
    for(int i = 0; i<n; i+=2){
        cin >> a1 >> a2;
        cantA = 0;
        cantB = 0;
        if (a1 == 'a'){
            cantA = cantA + 1;
        } else {
            cantB = cantB + 1;
        }
        if (a2 == 'a'){
            cantA = cantA + 1;
        } else {
            cantB = cantB + 1;
        }
        if (cantA != cantB){
            res += 1;
            if (a1 == 'a'){
                strFinal << "ba";
            } else {
                strFinal << "ab";
            }
        } else {
            strFinal << a1 << a2;
        }
    }

    cout << res << '\n';
    cout << strFinal.str() << '\n';
}