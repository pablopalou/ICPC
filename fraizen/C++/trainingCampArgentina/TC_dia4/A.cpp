#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    map<char, TrieNode*> children;
    bool is_end_of_word;

    TrieNode() : is_end_of_word(false) {}
    ~TrieNode() {
        for (auto &pair : children) {
            delete pair.second;
        }
    }
};

class Trie {
private:
    TrieNode *root;

    void insert(const string &s, TrieNode *node) {
        for (char c : s) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_end_of_word = true;
    }

    bool find(const string &s, TrieNode *node) {
        for (char c : s) {
            auto it = node->children.find(c);
            if (it == node->children.end()) {
                return false;
            }
            node = it->second;
        }
        return true;
    }

public:
    Trie() : root(new TrieNode()) {}
    ~Trie() {
        delete root;
    }

    void insert(const string &s) {
        insert(s, root);
    }

    bool find(const string &s) {
        return find(s, root);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Trie trie, trie_reversed;
    bool reversed = false;

    for (int i = 0; i < n; ++i) {
        int option;
        cin >> option;

        if (option == 1) {
            string str;
            cin >> str;
            if (reversed) {
                reverse(str.begin(), str.end());
            }
            trie.insert(str);
            string str_reversed = str;
            reverse(str_reversed.begin(), str_reversed.end());
            trie_reversed.insert(str_reversed);
        } else if (option == 2) {
            string str2;
            cin >> str2;

            Trie* target_trie = reversed ? &trie_reversed : &trie;

            cout << target_trie->find(str2) << '\n';

        } else if (option == 3) {
            reversed = !reversed;
        }
    }
}

// #include <bits/stdc++.h>
 
// #define ll long long
// #define pb push_back
// #define fr(a,b) for(int i = a; i<b; i++)
// #define rep(i,a,b) for(int i = a; i<b; i++)
// #define mod 1000000007
// #define inf (1LL<<60)
// #define all(x) (x).begin(),(x).end()
// #define prDouble(x) cout << fixed << setprecision(10) << x
// #define triplet pair<ll,pair<ll,ll>>
// #define goog(tno) cout << "Case #" << tno << ": " 
// #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
// #define read(x) int x; cin >> x
 
// using namespace std;

// string common_prefix(const string &a, const string &b) {
//     size_t min_len = min(a.size(), b.size());
//     size_t i = 0;
//     for (; i < min_len && a[i] == b[i]; ++i) {}
//     return a.substr(0, i);
// }

// string reverse_string(const string &s) {
//     string reversed_s = s;
//     reverse(reversed_s.begin(), reversed_s.end());
//     return reversed_s;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin >> n;
//     vector<string> palomas;
//     int option;
//     string longestPrefix = "";
//     string longestReversedPrefix = "";
//     bool firstStringRead = false;
//     bool reverted = false;
//     fr(0,n){
//         cin >> option;
//         if (option == 1) {
//             string str;
//             cin >> str;
//             if (!firstStringRead) {
//                 longestPrefix = str;
//                 longestReversedPrefix = reverse_string(str);
//                 firstStringRead = true;
//             } else {
//                 longestPrefix = common_prefix(longestPrefix, str);
//                 longestReversedPrefix = common_prefix(longestReversedPrefix, reverse_string(str));
//             }
//         } else if (option == 2) {
//             string str2;
//             cin >> str2;

//             if (!reverted){
//                 if (common_prefix(str2, longestPrefix).size() == str2.size()){
//                     cout << '1' << '\n';
//                 } else {
//                     cout << '0' << '\n';
//                 }
//             } else {
//                 if (common_prefix(str2, longestReversedPrefix).size() == str2.size()){
//                     cout << '1' << '\n';
//                 } else {
//                     cout << '0' << '\n';
//                 }
//             }
//         } else if (option == 3) {
//             reverted = ! reverted;
//         }
//     }
// }
