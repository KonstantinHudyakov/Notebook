#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

const int nmax = 1005;
vector<int> g[nmax];
int color[nmax];

inline char invert(int c){
	return c == 1? 2 : 1;
}

void dfs(int v, int c){
	color[v] = c;
	for(int u : g[v]){
		if(color[u] == 0){
			dfs(u, invert(c));
		}else if(color[u] == c){
			cout << "NO" << endl;
			exit(0);
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i = 1; i <= n; i++){
		if(color[i] == 0)
			dfs(i, 1);
	}
	cout << "YES" << endl;
	return 0;
}
