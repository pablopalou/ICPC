#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define cout(x) cout << x << "\n";

// Copiar obligatoriamente 0
void solve() {
    string line;
    while (getline(cin,line)){
        vector <string> p;
        stringstream check1(line);
        string intermediate;

        while(getline(check1, intermediate, ' ')){
            p.push_back(intermediate);
        }
        if (p[0] == "Game"){
            return;
        }

        int res = 0;
        int tir = 0;
        int frame = 0;
        int score[12];
        int first = true;
        int curFrame = 0;
        set<int> posX;
        set<int> posBarra;
        int tiradas[30];
        while (tir < p.size()){
            if (p[tir] == "X" || (p[tir] == "/")){
                tiradas[tir] = 10;
            } else {
                tiradas[tir] = stoi(p[tir]);
            }
            // cout << "Mirando " << p[tir] << endl;
            // cout << "frame actual " << frame << endl;
            if (frame >= 10){
                if (p[tir] == "X" || (p[tir] == "/")){
                    score[frame] = 10;
                } else {
                    score[frame] = stoi(p[tir]);
                }
                frame++;
                tir++;
                continue;
            }
            if (p[tir] == "X" || (p[tir] == "/")){
                if (p[tir] == "X"){
                    posX.insert(tir);
                } else {
                    posBarra.insert(tir);
                }
                score[frame] = 10;
                tir++;
                frame++;
                first = true;
                curFrame = 0;
            } else {
                if (first) {
                    curFrame += stoi(p[tir]);
                    first = false;
                } else {
                    score[frame] = curFrame + stoi(p[tir]);
                    curFrame = 0;
                    frame++;
                    first = true;
                }
                tir++;
            }
        }
        fr(0,10){
            // cout << score[i] << " ";
            res+=score[i];
        }
        // cout << endl;
        // cout << "X" << endl;
        fre(posX){
            // cout << e << ' ';
            if (tiradas[e+2] == 10 && tiradas[e+1]!=10){
                res += 10;
            } else {
                res+=tiradas[e+1] + tiradas[e+2];
            }
        }
        // cout << endl;
        // cout << "barras = " << endl;
        fre(posBarra){
            // cout << e << ' ';
            res += tiradas[e+1];
        }
        // cout << endl;
        // cout << "Until frame" << frame - 1 << endl;
        // fr(0,12){
        //     cout << score[i] << endl;
        // }
        cout << res << "\n";
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