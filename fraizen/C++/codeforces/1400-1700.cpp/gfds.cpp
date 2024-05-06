#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    //prefijo es cuanto necesita para matar a este si primero mato a todos los de la derecha
    //sufijo es cuanto necesito para matar a este si primero mato a todos los de la izq
    //luego hago maximo de eso porque es tipo de aca pa la derecha, cuanto es lo maximo que cuesta.
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a) cin >> it;
    
    vector<int> pref(n), suf(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = a[i] + (n - i - 1);
        suf[i] = a[i] + i;
    }
    cout << "Pref " << endl;
    for(int i =0;i<=n-1;i++){
        cout << pref[i] << " ";
    }
    cout << endl << "SUf = " << endl;
    for(int i =0;i<=n-1;i++){
        cout << suf[i] << " ";
    }

    for (int i = 1; i < n; ++i) {
        pref[i] = max(pref[i], pref[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = max(suf[i], suf[i + 1]);
    }
    
    int ans = 2e9;
    for (int i = 0; i < n; ++i) {
        int cur = a[i];
        if (i > 0) cur = max(cur, pref[i - 1]);
        if (i + 1 < n) cur = max(cur, suf[i + 1]);
        ans = min(ans, cur);
    }
    cout << "Pref " << endl;
    for(int i =0;i<=n-1;i++){
        cout << pref[i] << " ";
    }
    cout << endl << "SUf = " << endl;
    for(int i =0;i<=n-1;i++){
        cout << suf[i] << " ";
    }

    cout << ans << endl;
    
    return 0;
}