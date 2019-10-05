#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void simple_multi(ll a, vector<int>& p, vector<int>& al) {
	for (int i = 2; i * i <= a; i++) {
		if (a % i) continue;
		p.push_back(i);
		al.push_back(0);
		while (a % i == 0)
			a /= i, ++al.back();
	}
	if (a > 1)
		p.push_back(a), al.push_back(1);
}


int main()
{
	
	return 0;
}
