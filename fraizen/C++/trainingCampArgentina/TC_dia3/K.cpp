#include <bits/stdc++.h>
 
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

void solve(string word) {
    unordered_map<char, int> alphabet_values;
    
    for (char c = 'a'; c <= 'z'; ++c) {
        alphabet_values[c] = c - 'a' + 1;
    }

    unordered_map<char, vector<int>> letter_indices;

    for (size_t i = 0; i < word.size(); ++i) {
        char letter = word[i];
        letter_indices[letter].emplace_back(i);
    }

    char first_letter = word.front();
    char last_letter = word.back();
    vector<int> index_result;
    int tiles = 0;

    if (first_letter < last_letter) {
        for (char c = first_letter; c <= last_letter; ++c) {
            for (int index : letter_indices[c]) {
                tiles += 1;
                index_result.push_back(index + 1);
            }
        }
    } else {
        for (char c = first_letter; c >= last_letter; --c) {
            for (int index : letter_indices[c]) {
                tiles += 1;
                index_result.push_back(index + 1);
            }
        }
    }

    int res;
    if (alphabet_values[last_letter] - alphabet_values[first_letter] > 0){
        res = alphabet_values[last_letter] - alphabet_values[first_letter];
    } else {
        res = alphabet_values[first_letter] -alphabet_values[last_letter];
    }
    cout << res << ' ' << tiles << '\n';
    for (size_t i = 0; i < index_result.size(); ++i) {
        cout << index_result[i];
        if (i < index_result.size() - 1) {
            cout << ' ';
        }
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int casos;
    cin >> casos;
    string temp;
    getline(cin, temp);
    while (casos > 0){
        string word;
        getline(cin, word);
        solve(word);
        casos--;
    }
}
