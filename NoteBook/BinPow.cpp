#include <bits/stdc++.h>
using namespace std;

int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int main(){
	cout << binpow(34,4) << endl;
	return 0;
}
