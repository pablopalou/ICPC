#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define mp make_pair
#define pb push_back

string x = "What are you doing while sending \"";
string y = "\"? Are you busy? Will you send \"";
string z = "\"?";
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
ll largo[55];

void rec(ll f, ll pos){
    // cout << "Entre con f = " << f << " y pos = " << pos << endl;
    // cout <<"A"<<endl;
    if (f == 0){
        cout << f0[pos-1];
        return;
    }
    // cout <<"B"<<endl;
    if (pos <= x.size()){
        cout << x[pos-1];return;
    }
    // cout <<"C"<<endl;
    if (pos <= x.size() + largo[f-1]){
        rec(f-1, pos-x.size()); return;
    }
    // cout <<"D"<<endl;
    if (pos <= x.size() + largo[f-1] + y.size()){
        pos -= x.size() + largo[f-1];
        cout << y[pos-1]; return;
    }
    // cout <<"E"<<endl;
    if (pos <= x.size() + 2 * largo[f-1] + y.size()){
        pos -= x.size() + largo[f-1] + y.size();
        rec(f-1, pos); return;
    }
    // cout <<"F"<<endl;
    pos -= x.size() + 2 * largo[f-1] + y.size();
    cout << z[pos-1];
}

void solve(){
    int q; cin >> q;
    largo[0] = 75;
    fr(1,55){
        largo[i] = 68 + 2*largo[i-1];
        // cout << i << "=>"<< largo[i] << endl;
    }
    ll largox = x.size();
    // cout << y.size() << endl;
    // cout << x.size() + y.size() + z.size() + 2*f0.size();return;
    fr(0,q){
        // cout << "Query " << i << endl;
        ll f, pos; cin >> f >> pos;
        // cout << "pos = " << pos;
        if (f < 55 && pos > largo[f]){
            cout << ".";
            continue;
        }
        if (f >= 55){
            if (pos <= largox * (f-54)){
                pos %= largox;
                cout << x[pos-1];
                continue;
            }
            rec(54, pos - largox * (f-54));
            continue;
        } else {
            // cout << "Me llamo aca " << endl;
            rec(f, pos);
        }
    }
}

int main(int argc, char const *argv[])
{
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    #ifdef JP
        freopen("I.in", "r", stdin);
    #endif

    int cases=1;
    // cin >> cases;
    while(cases--){
        solve();
    }
    return 0;
}



// f0 = What are you doing at the end of the world? Are you busy? Will you save us?

// fi = What are you doing while sending "fi - 1"? Are you busy? Will you send "fi - 1"?

// f1 = What are you doing while sending "What are you doing at the end of the world? Are you busy? Will you save us?"? Are you busy? Will you send "What are you doing at the end of the world? Are you busy? Will you save us?"?

// f2 = What are you doing while sending "What are you doing while sending "What are you doing at the end of the world? Are you busy? Will you save us?"? Are you busy? Will you send "What are you doing at the end of the world? Are you busy? Will you save us?"?"? Are you busy? Will you send "What are you doing while sending "What are you doing at the end of the world? Are you busy? Will you save us?"? Are you busy? Will you send "What are you doing at the end of the world? Are you busy? Will you save us?"?"?