#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fr(a,b) for(int i = a; i<b; i++)
#define mp make_pair

pair<int, int> pos[4];
int mat[10][10];
int n, w, h, l;
int res = 100;
int targetX, targetY;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
unordered_map<int, vector<pair<int, int>>> memo;

inline ll computeHash() {
    ll hash = 0;
    for (int i = 0; i < n; ++i) {
        hash = hash * 100 + pos[i].first * 10 + pos[i].second;
    }
    return hash;
}

inline vector<pair<int, int>> getPositions(int index) {
    ll hashValue = computeHash() * 10 + index;
    
    if (memo.count(hashValue)) {
        return memo[hashValue];
    }

    vector<pair<int, int>> ans;
    // set<pair<int, int>> prohibido;
    vector<pair<int,int>> prohibido(n-1);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (i != index){
            prohibido[j] = pos[i];
            j++;
        } 
    }

    for (auto& [dx, dy] : directions) {
        int x = pos[index].first;
        int y = pos[index].second;
        while (x + dx >= 0 && x + dx < h && y + dy >= 0 && y + dy < w &&
                 mat[x + dx][y + dy] == 0) {
            bool salir = false;
            fr(0,n-1){
                if (mp(x+dx, y+dy) == prohibido[i]){
                    salir = true;
                }
            }
            if (salir){
                break;
            }
            x += dx;
            y += dy;
        }
        if (x != pos[index].first || y != pos[index].second) {
            ans.push_back({x, y});
        }
    }

    memo[hashValue] = ans;
    return ans;
}

void rec(int level) {
    if (level >= res || level > l) return;
    
    if (pos[0].first == targetX && pos[0].second == targetY) {
        res = min(res, level);
        return;
    }
    if (level+1 >= res){
        return;
    }
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> nextPositions = getPositions(i);
        for (auto& nextPos : nextPositions) {
            pair<int, int> prevPos = pos[i];
            pos[i] = nextPos;
            rec(level + 1);
            pos[i] = prevPos;
        }
    }
}

void solve() {
    cin >> n >> w >> h >> l;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char c; cin >> c;
            mat[i][j] = 0; // libre
            if (c == 'X') {
                targetX = i; targetY = j;
            } else if (c >= '1' && c <= '4') {
                pos[c - '1'] = {i, j};
            } else if (c == 'W') {
                mat[i][j] = 1;
            }
        }
    }
    rec(0);
    if (res == 100) {
        cout << "NO SOLUTION\n";
    } else {
        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}