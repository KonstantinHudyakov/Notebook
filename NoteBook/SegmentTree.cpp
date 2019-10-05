#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef pair<int, int> P;
typedef long double ld;
typedef long long ll;

void BuildMax(vector<ll> &a, ll musor, ll & n) {
	n = 1;
	while (n < a.size()) n *= 2;
	a.resize(n + n, musor);
	for (int i = 0; i < n; i++)
		a[n + i] = a[i];
	for (int i = n - 1; i > 0; i--)
		a[i] = max(a[i + i], a[i + i + 1]);
}

void BuildMin(vector<ll> &a, ll musor, ll & n) {
	n = 1;
	while (n < a.size()) n *= 2;
	a.resize(n + n, musor);
	for (int i = 0; i < n; i++) 
		a[n + i] = a[i];
	for (int i = n - 1; i > 0; i--)
		a[i] = min(a[i + i], a[i + i + 1]);
}

void UpdMax(vector<ll> &arr, ll i, ll x, ll n) {
	i += n;
	arr[i] = x;
	for (i /= 2; i > 0; i /= 2)
		arr[i] = max(arr[i + i],arr[i + i + 1]);
}

void UpdMin(vector<ll> &arr, ll i, ll x, ll n) {
	i += n;
	arr[i] = x;
	for (i /= 2; i > 0; i /= 2)
		arr[i] = min(arr[i + i], arr[i + i + 1]);
}

ll SegmentMax(const vector<ll> &arr, ll v, ll L, ll R, ll l, ll r) {
	if (L == l && R == r) return arr[v];
	ll M = (R + L) / 2;
	ll res = -ll(1e10);
	if (l <= M)
		res = max(res, SegmentMax(arr, v + v, L, M, l, min(r, M)));
	if (r >= M + 1)
		res = max(res, SegmentMax(arr, v + v + 1, M + 1, R, max(l, M + 1), r));
	return res;
}

ll SegmentMin(const vector<ll> &arr, ll v, ll L, ll R, ll l, ll r) {
	if (L == l && R == r) return arr[v];
	ll M = (R + L) / 2;
	ll res = ll(1e10);
	if (l <= M)
		res = min(res, SegmentMin(arr, v + v, L, M, l, min(r, M)));
	if (r >= M + 1)
		res = min(res, SegmentMin(arr, v + v + 1, M + 1, R, max(l, M + 1), r));
	return res;
}

int main()
{
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n, 0), b(n, 0);
	BuildMax(a, -ll(1e10), n);
	BuildMin(b, ll(1e10), n);
	for (int i = 0; i < m; i++) {
		ll cm, first, second;
		cin >> cm >> first >> second;
		if (cm == 1) {
			cout << SegmentMax(a, 1, 0, n - 1, first - 1, second - 1) - SegmentMin(b, 1, 0, n - 1, first - 1, second - 1) << endl;
		}
		else {
			UpdMax(a, first - 1, second, n);
			UpdMin(b, first - 1, second, n);
		}
	}
	//system("pause");
	return 0;
}
