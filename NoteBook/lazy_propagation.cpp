#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

const int MAXN = 3 * 1e5 + 5;
ll sz;
vector<ll> t, add;


inline ll val(int v, int len){
	return t[v] + add[v] * len;
}

inline void push(int v){
	add[2 * v] += add[v];
	add[2 * v + 1] += add[v];
	add[v] = 0;
}

void ref(int v, int len){
	t[v] = val(2 * v, len) + val(2 * v + 1, len);
}

void upd(int ql, int qr, int x, int v = 1, int tl = 0, int tr = sz - 1){
	if(ql <= tl && tr <= qr){
		add[v] += x;
	}else{
		push(v);
		int mid = (tl + tr) / 2;
		if(ql <= mid)
			upd(ql, qr, x, 2 * v, tl, mid);
		if(qr > mid)
			upd(ql, qr, x, 2 * v + 1, mid + 1, tr);
		t[v] = val(2 * v, mid - tl + 1) + val(2 * v + 1, tr - mid);
		ref(v, tr - mid);
		}
}



ll get(int ql , int qr, int v = 1, int tl = 0, int tr = sz - 1){
	if(ql <= tl && tr <= qr)
		return val(v, tr - tl + 1);
	push(v);
	ll res = 0;
	int mid = (tl + tr) / 2;
	if(ql <= mid)
		res += get(ql, qr, 2 * v, tl, mid);
	if(qr > mid)
		res += get(ql, qr, 2 * v + 1, mid + 1, tr);
	ref(v, tr - mid);
	return res;
}


int main(){
	int n, q;
	cin >> n >> q;
	sz = 1;
	while(sz < n) sz *= 2;
	t.resize(sz + sz, 0);
	add.resize(sz + sz, 0);
	for(int i = 0; i < q; i++){
		int c, l, r;
		cin >> c >> l >> r;
		if(c == 1){
			int x; 
			cin >> x;
			upd(l - 1, r - 1, x);
		}else{
			cout << get(l - 1, r - 1) << endl;
		}
	}
	
	return 0;
}
