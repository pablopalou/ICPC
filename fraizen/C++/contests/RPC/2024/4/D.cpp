#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";
#define pb push_back

bool isVowel(char c){
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}


// Copiar obligatoriamente 0
void solve() {
    string s1,s2; cin >> s1 >> s2;
    string s2Orig = s2;
    string res1, res2;
    res1 = s1[0];
    int i = 1;
    bool tengoV1 = false;
    char v1,v2;
    bool tengoV2 = false;
    while(i<s1.size() && !isVowel(s1[i])){
        res1 += s1[i];
        i++;
    }
    if (i<s1.size()){
        tengoV1 = true;
        v1 = s1[i];
    }

    reverse(s2.begin(), s2.end());
    i = 1;
    res2 = s2[0];
    while(i<s2.size() && !isVowel(s2[i])){
        res2 += s2[i];
        i++;
    }
    if (i<s2.size()){
        tengoV2 = true;
        v2 = s2[i];
    }
    reverse(res2.begin(), res2.end());
    
    if (tengoV2){
        cout << res1 + v2 + res2 << '\n';
    } else if (tengoV1){
        cout << res1 + v1 + res2 << '\n';
    } else {
        cout << res1 + "o" + res2 << '\n';
    }
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