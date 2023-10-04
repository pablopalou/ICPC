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
    //fijarse el tema de 100 y eso
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string ini, fin;
    cin >> ini >> fin;
    string cur = ini;
    vector<string> numbers;

    int res = 1;
    while (cur != fin){
        string number = "";
        res++;
        map<int, int> m;
        fr(0,cur.size()){
            m[cur[i] - '0']++;
        }
        fr(0,10){
            if (m[i] > 0){
                number = number + to_string(m[i]);
                number = number + to_string(i);
            }
        }
        // cout << "number "<< res <<": " << number << endl;
        if (number == fin){
            cout << res << endl;
            return 0;
        }
        //ver si encuentro al coso en el vector
        fr(0,numbers.size()){
            if (numbers[i] == number){
                int dif = numbers.size() - i;
                if (dif <= 100){
                    cout << "Does not appear";
                    return 0;
                } else {
                    cout << "I'm bored";
                    return 0;
                }
            }
        }
        // if (numbers.find(number) != numbers.end()){ //si lo encuentro
        //     if (numbers.size() - distance(numbers.begin(), numbers.find(number)) <= 100){
        //         cout << "Does not appear";
        //         return 0;
        //     } else {
        //         cout << "I'm bored";
        //         return 0;
        //     }
        // }
        numbers.pb(number);
        cur = number;
    }
    cout(1);
}