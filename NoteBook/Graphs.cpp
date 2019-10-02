#include "stdafx.h"
#include "Graphs.h"

// Раскраска графа для поиска компонент связности
void dfs(vector<vector<int>> &g, vector<int> &comps, int cur, int compNum) {
	comps[cur] = compNum;
	for (auto &it : g[cur]) {
		if (comps[it] == 0)
			dfs(g, comps, it, compNum);
	}
}


// Поиск цикла в графе
//int cycleStart, cycleEnd;

bool dfs(vector<vector<int>> &g, vector<int> &used, vector<int> &parent, int cur) {
	used[cur] = 1;

	for (auto &it : g[cur]) {
		if (used[it] == 0) {
			parent[it] = cur;
			if (dfs(g, used, parent, it))
				return true;
		}
		else if (used[it] == 1) {
			//cycleEnd = cur;
			//cycleStart = it;
			return true;
		}
	}

	used[cur] = 2;
	return false;
}


// Топологическая сортировка(результат надо реверсировать)
void topSort(vector<vector<int>> &g, vector<bool> &used, vector<int> &sorted, int cur) {
	used[cur] = true;

	for (auto &it : g[cur]) {
		if (!used[it]) {
			topSort(g, used, sorted, it);
		}
	}
	sorted.push_back(cur);
}

