#pragma once

#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <iomanip>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<int, int>
#define mp make_pair


using namespace std;

void dfs(vector<vector<int>> &g, vector<int> &comps, int cur, int compNum);
bool dfs(vector<vector<int>> &g, vector<int> &used, vector<int> &parent, int cur);
void topSort(vector<vector<int>> &g, vector<bool> &used, vector<int> &sorted, int cur);
