#include <bits/stdc++.h>
using namespace std;
// "NO FUNCIONA"
void solve() {
    int n;
    cin >> n;
    vector<map<int, int>> m(n);
    map<int, int> total;

    for (int i = 0; i < n; i++) {
        int cant;
        cin >> cant;
        for (int j = 0; j < cant; j++) {
            int a;
            cin >> a;
            m[i][a]++;
            total[a]++;
        }
    }

    int maximo = total.size();
    // cout << "maximo " << maximo << endl;
    vector<bool> discard(n, false);
    vector<bool> juntar(n, false);

    for (int i = 0; i < n; i++) {
        if (m[i].size() == maximo) {
            discard[i] = true;
            for (auto &it : m[i]) {
                total[it.first]--;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (discard[i]) {
            continue;
        }
        int bajar = 0;
        for (auto &it : m[i]) {
            if (total[it.first] - it.second == 0) {
                bajar++;
            }
        }
        // cout << "bajar " << bajar << endl;
        if (bajar != 0){
            juntar[i] = true;
            res = max(res, (maximo - bajar));
        }
    }
    set<int> juntos;
    for (int i = 0; i < n; i++) {
        if (! juntar[i]) {
            continue;
        }
        for (auto &it : m[i]) {
            juntos.insert(it.first);
        }
    }
    if (juntos.size() !=  maximo){
        res = max(res, int(juntos.size()));
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }
}