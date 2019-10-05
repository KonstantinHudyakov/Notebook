#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)

const int NMAX = 1e5 + 10;

vector<int> g[NMAX];
vector<char> used;
vector<int> p;
int cycle_st, cycle_end;

bool dfs(int v){
	used[v] = 1;
	for(int i = 0; i < (int)g[v].size(); i++){
		int to = g[v][i];
		if(used[to] == 0){
			p[to] = v;
			if(dfs(to)) return true;
		}else if(used[to] == 1){
			cycle_end = v;
			cycle_st = to;
			return true;
		}
	}
	used[v] = 2;
	return false;
}

int main(){
	int n, m;
	cin >> n >> m;
	used.resize(n, 0);
	p.assign(n, -1);
	cycle_st = -1;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		//g[v].pb(u);
	}
	for(int i = 0; i < n; i++){
		if(dfs(i))
			break;
	}
	if(cycle_st != -1){
		cout << "YES" << endl;
		vector<int> cycle;
		for(int v= cycle_end; v!= cycle_st; v = p[v])	
			cycle.pb(v);
		cycle.pb(cycle_st);
		reverse(cycle.begin(), cycle.end());
		for(auto i : cycle){
			cout << i +1 << " ";
		}
		cout << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}
