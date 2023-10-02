#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <math.h>
// #include <bits/stdc++.h>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second); 
        return h1 ^ h2;  
    }
};

int solve(unordered_map<pair<char, char>, set<int>, pair_hash> costos, string a, string b) {
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        pair<char, char> a_b = make_pair(a[i], b[i]);
        pair<char, char> b_a = make_pair(b[i], a[i]);
        if (a[i] != b[i]) {
            if (costos.find(a_b) != costos.end() && !costos[a_b].empty() && costos.find(b_a) != costos.end() && !costos[b_a].empty()) {
                    if (int(*costos[a_b].begin()) < int(*costos[b_a].begin())) {
                        a[i] = b[i];
                        res += int(*costos[a_b].begin());
                        // costos[a_b].erase(costos[a_b].begin());
                    } else {
                        b[i] = a[i];
                        res += int(*costos[b_a].begin());
                        // costos[b_a].erase(costos[b_a].begin());
                    }
            } else if (costos.find(a_b) != costos.end() && !costos[a_b].empty()) {
                a[i] = b[i];
                res += int(*costos[a_b].begin());
                // costos[a_b].erase(costos[a_b].begin());
            } else if (costos.find(b_a) != costos.end() && !costos[b_a].empty()) {
                b[i] = a[i];
                res += int(*costos[b_a].begin());
                // costos[b_a].erase(costos[b_a].begin());
            } else {
                cout << "-1" << "\n";
                return 0;
            }
        }
    }

    cout << res << "\n";
    cout << a << "\n";

    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a;
    string b;
    cin >> a;
    cin >> b;

    if (a.size() != b.size()) {
        cout << "-1";
        return 0;
    }

    int largo;
    cin >> largo;
    unordered_map<pair<char, char>, set<int>, pair_hash> costos;
    while (largo > 0) {
        char a_cambiar;
        cin >> a_cambiar;
        char destino;
        cin >> destino;
        int costo;
        cin >> costo;
        costos[make_pair(a_cambiar, destino)].insert(costo);
        largo--;
    }
    solve(costos, a, b);
}