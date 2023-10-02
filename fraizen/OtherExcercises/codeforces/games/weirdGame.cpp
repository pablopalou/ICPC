#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double d;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
typedef set<ll> si;
typedef multiset<ll> msi;
typedef unordered_set<ll> usi;
typedef map<ll, string> mis;
typedef unordered_map<ll, string> umis;
#define pb push_back
#define mp make_pair
#define cout(x) cout << x << "\n";
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fre(s) for(auto e:s)
#define MAXN 1000008

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int ganados = 0;
    int perdidos = 0;
    int empates = 0;

    fr(0,2*n){
        if (s1[i] == '1' && s2[i] == '1'){
            empates++;
        } 
        if(s1[i] == '1' && s2[i] == '0'){
            ganados ++;
        }
        if(s1[i] == '0' && s2[i] == '1'){
            perdidos ++;
        }
    }
    if (ganados > perdidos){
        cout("First");
    } else if (ganados == perdidos && (empates % 2 == 1)){
        cout ("First");
    } else if (ganados < perdidos){
        int dif = (perdidos - ganados)/2; 
        if ((dif == 1 && (empates % 2 == 1)) || dif ==0 ){
            cout("Draw");
        } else {
            cout("Second");
        }
    } else if (ganados == perdidos && (empates % 2 == 0)) {
        cout("Draw");
    } else {
        cout("Second");
    }
}