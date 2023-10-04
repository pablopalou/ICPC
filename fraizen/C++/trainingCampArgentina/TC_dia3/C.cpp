#include <bits/stdc++.h>

using namespace std;

int solve(string amigo, unordered_map<char, vector<int>>& showcase_index) {
    vector<int> counter(26, 0);

    for (char c : amigo) {
        counter[c - 'a']++;
    }

    int index = INT_MAX;
    for (char c : amigo) {
        int value = counter[c - 'a'];
        index = min(index, showcase_index[c][value - 1] + 1);
    }

    cout << index << "\n";

    return 0;
}

int main() {
    int largo;
    cin >> largo;
    string showcase;

    unordered_map<char, vector<int>> showcase_index;
    for (int i = 0; i < largo; i++) {
        char c;
        cin >> c;
        showcase.push_back(c);
    }

    for (int i = 0; i < showcase.size(); i++) {
        showcase_index[showcase[i]].push_back(i);
    }

    int casos;
    cin >> casos;
    string s;
    getline(cin, s);

    while (casos > 0) {
        string amigo;
        getline(cin, amigo);

        solve(amigo, showcase_index);
        casos--;
    }
}