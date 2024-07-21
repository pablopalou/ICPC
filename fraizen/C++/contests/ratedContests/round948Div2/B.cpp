#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(a,b) for(int i = a; i<b; i++)
#define rep(i,a,b) for(int i = a; i<b; i++)
#define fre(s) for(auto e:s)
#define pb push_back

void solve() {
    int n; cin >> n;
    vector<int> res(32,0);
    fr(0,32){
        res[i] = n&1;
        n>>=1;
    }
    int i = 0;
    while(i <= 31){
        if (res[i] == 1 && res[i+1] == 1){
            int l = i, r = i;
            while(res[r] == 1){
                res[r] = 0;
                r++;
                if (r == 32){
                    break;
                }
            }
            res[r] =1;
            res[l] = -1;
            i = r-1;
        }
        i++;
    }
    fr(0,31){
        if (res[i+1] == -1 && res[i] == 1){
            res[i] = -1;
            res[i+1] = 0;
        }
    }
    cout << "32\n";
    fr(0,32){
        cout << res[i] << ' ';
    }
    cout << '\n';
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
    cin >> cases;
    while(cases--){
        solve();
    }

    #ifdef JP
		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
	#endif

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define fr(a,b) for(int i = a; i<b; i++)
// #define rep(i,a,b) for(int i = a; i<b; i++)
// #define fre(s) for(auto e:s)
// #define pb push_back

// vector<int> DecimalToBinary(int num)
// {
//     vector<int> vec;
//     while(num){
//         if(num & 1) // 1
//             vec.pb(1);
//         else // 0
//             vec.pb(0);
//         num >>= 1; // Right Shift by 1  
//     }
//     reverse(vec.begin(), vec.end());
//     return vec;
// }

// void imp(const vector<int>& vec){
//     fr(0, vec.size()){
//         cout << vec[i] << " ";
//     }
//     cout << '\n';
// }

// void imp2(const vector<int>& vec){
//     fr(0, vec.size() - 1){
//         if (vec[i] == 1){
//             cout << "-1 ";
//         } else {
//             cout << "0 ";
//         }
//     }
//     cout << "1";
//     cout << '\n';
// }

// void reverseVec(const vector<int>& vec)
// {
//     for(int i = vec.size() - 1; i >= 0; i--)
//         cout << vec[i]; 
//     cout << endl;
// }

// bool esBueno(const vector<int>& vec){
//     fr(0, vec.size() - 1){
//         if (vec[i] == 1 && vec[i+1] == 1){
//             return false;
//         }
//     }
//     return true;
// }

// int esBuenoPos(const vector<int>& vec){
//     for(int i = vec.size() - 1; i >= 1; i--){
//         if ((vec[i] == 1 || vec[i] == -1) && (vec[i-1] == 1 || vec[i-1] == -1)){
//             return i - 1;
//         }
//     }
//     return -1;
// }

// void removeLeadingZeros(vector<int>& vec){
//     while(!vec.empty() && vec[0] == 0){
//         vec.erase(vec.begin());
//     }
// }

// void solve() {
//     ll n; cin >> n;
//     if (n == 1){
//         cout << "1\n";
//         cout << "1\n";
//         return;
//     }
//     vector<int> vec = DecimalToBinary(n);
//     if (esBueno(vec)){
//         cout << vec.size() << "\n";
//         imp(vec);
//     } else {
//         // cout << "here " << endl;
//         reverse(vec.begin(), vec.end());
//         int a = esBuenoPos(vec);
//         // fr(0,vec.size()){
//         //         cout << vec[i] << " ";
//         //     }
//         //     cout << '\n';
//         // cout << a << endl; 
//         while(a != -1){
//             // cout << "a = " << a << endl; 
//             if (a == 0){
//                 vec.insert(vec.begin() + 1, 0);
//                 vec[0] = -1;
//                 break;
//             }
//             vector<int> newVec(vec.begin(), vec.begin() + a ); // Copy the part before the position 'a'
//             newVec.pb(-1);
//             newVec.pb(0);
//             for (int i = a + 1; i < vec.size(); i++) { // Copy the remaining part after the position 'a'
//                 newVec.pb(vec[i]);
//             }
//             vec = newVec;
//             a = esBuenoPos(vec);
//             // fr(0,vec.size()){
//             //     cout << vec[i] << " ";
//             // }
//             // cout << '\n';
//             //i want here to put the vec as the same vec until the position i, and then change the following number to two numbers. I want to put -1 0 and then all the rest
//             // vec[a-1] = -1;
//             // vec[a] = 0;
//             // a = esBuenoPos(vec);
//         }
//         removeLeadingZeros(vec);
//         cout << vec.size() << "\n";
//         imp(vec);
//     }
// }

// int main() {
//     std::iostream::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     #ifdef JP
//         freopen("A.in", "r", stdin);
//         freopen("A.out", "w", stdout);
//     #endif

//     int cases = 1;
//     cin >> cases;
//     while(cases--){
//         solve();
//     }

//     #ifdef JP
//         cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
//     #endif

//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define fr(a,b) for(int i = a; i<b; i++)
// #define rep(i,a,b) for(int i = a; i<b; i++)
// #define fre(s) for(auto e:s)
// #define pb push_back

// string DecimalToBinary(int num)
// {
//     string str;
//       while(num){
//       if(num & 1) // 1
//         str+='1';
//       else // 0
//         str+='0';
//       num>>=1; // Right Shift by 1  
//     }    
//       return str;
// }
// void imp(string s){
//     fr(0,s.size()){
//         cout << s[i] << " ";
//     }
//     cout << '\n';
// }
// void imp2(string s){
//     fr(0,s.size()-1){
//         if (s[i] == '1'){
//             cout << "-1 ";
//         } else {
//             cout << "0 ";
//         }
//     }
//     cout << "1";
//     cout << '\n';
// }

// void reverse(string str)
// {
//   for(int i=str.size()-1 ; i>=0 ; i--)
//    cout<< str[i]; 
//    cout << endl;
// }

// bool esBueno(string s){
//     fr(0,s.size()-1){
//         if (s[i] == '1' && s[i+1] == '1'){
//             return false;
//         }
//     }
//     return true;
// }

// int esBuenoPos(string s){
//     for( int i = s.size(); i >= 1; i--){
//         if ((s[i] == '1' || s[i] == '-1') && (s[i-1] == '1' || s[i-1] == '0')){
//             return i-1;
//         }
//     }
//     return -1;
// }

// void solve() {
//     ll n; cin >> n;
//     if (n == 1){
//         cout << "1\n";
//         cout << "1\n";
//         return;
//     }
//     string s = DecimalToBinary(n);
//     if (esBueno(s)){
//         cout << s.size() << "\n";
//         imp(s);
//     } else {
//         //tengo el string y voy viendo si tengo 2 unos
//         int a = esBuenoPos(s);
//         while(a == -1){
//             if (a == 0){
//                 if (s[1] == '1'){
//                     s = "10" + s.substr(1);
//                 } else {
//                     s = "10" + s.substr(1);
//                 }
//                 break;
//             }
//             s[a-1] = "-1";
//             s[a] = "0";
//             a = esBuenoPos(s);
//         }
//         cout << s2.size() << "\n";
//         fr(0,s2.size()){
//             cout << s2[i] << ' ';
//         }
//         cout << '\n';
//     }
// }

// // ACORDATE DE USAR LONG LONG
// int main() {
//     std::iostream::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     #ifdef JP
//         freopen("A.in", "r", stdin);
//         freopen("A.out", "w", stdout);
// 	#endif

//     int cases = 1;
//     cin >> cases;
//     while(cases--){
//         solve();
//     }

//     #ifdef JP
// 		cerr << "Time elapsed: " <<  clock() * 1000 / CLOCKS_PER_SEC << " ms\n";
// 	#endif

//     return 0;
// }