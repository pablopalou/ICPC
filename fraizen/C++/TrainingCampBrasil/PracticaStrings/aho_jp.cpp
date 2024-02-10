#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i<b; i++)
#define forn(i,n) forr(i,0,n)
#define dfornt(i,n) for(int i = n-1; i>-1; i--)
#define forall(i,v) for(auto i = v.begin(); i != v.end(); i++)
#define sz(v) ((int) v.size()) 
#define pb push_back
#define fst first
#define snd second
#define lb lower_bound
#define ub upper_bound
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct vertex {
	map<char,int> next,go,matching;
	int p,link,leafLink;
	char pch;
	vector<int> leaf;
	vertex(int p=-1, char pch=-1):p(p),link(-1),leafLink(-1),pch(pch){}
};
vector<vertex> t;
void aho_init(){
	t.clear();t.pb(vertex());
}
void add_string(string s, int id){
	int v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.pb(vertex(v,c));
		}
		v=t[v].next[c];
	}
	t[v].leaf.pb(id);
}
int go(int v, char c);
int get_link(int v){
	if(t[v].link<0)
		if(!v||!t[v].p)t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
	return t[v].link;
}
int go(int v, char c){
	if(!t[v].go.count(c))
		if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
	return t[v].go[c];
}
int get_leaf_link(int v){
	if(t[v].leafLink < 0){
		if(!v||!t[v].p) t[v].leafLink = 0;
		else
		{
			if(t[get_link(v)].leaf.empty()) t[v].leafLink = get_leaf_link(t[v].link);
			else t[v].leafLink = t[v].link;
		}
	}
	return t[v].leafLink;
}

int get_matching(int v, char c) {
	if(!t[v].matching.count(c)){
		if(t[v].next.count(c)) 
			t[v].matching[c] += sz(t[t[v].next[c]].leaf);
		if(v != get_link(v))
			t[v].matching[c] += get_matching(get_link(v),c);
	}
	return t[v].matching[c];
}


int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, q; cin >> n >> q;
	aho_init();
	
	forn(i,n) {
		string p; cin >> p;
		add_string(p,i);
	}
	
	string text; cin >> text;
	vector<int> node(sz(text)+1);
	forr(i,1,sz(text)+1) {
		node[i] = go(node[i-1],text[i-1]);
	}
	
	int ans = 0;
	vector<int> matching(sz(text));
	forn(i,sz(text)){
		matching[i] = get_matching(node[i], text[i]);
		ans += matching[i];
	}
	
	cout << ans << "\n";
	forn(Q,q) {
		int idx; cin >> idx; idx--;
		char c; cin >> c;
		int to_erase = 0;
		int to_add = 0;
		text[idx] = c;
		forn(i,100) {
			if(idx+i+1>sz(text)) continue;
			to_erase += matching[idx+i];
			node[idx+i+1] = go(node[idx+i],text[idx+i]);
			matching[idx+i] = get_matching(node[idx+i], text[idx+i]);
			to_add += matching[idx+i];
		}
		ans += to_add;
		ans -= to_erase;
		cout << ans << "\n";
	}
}
