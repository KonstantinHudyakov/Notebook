#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

struct p{
	int x, y;
};

inline int area(p a, p b, p c){
	return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

inline bool intersect_1(int a, int b, int c, int d){
	if(a > b) swap(a,b);
	if(c > d) swap(c,d);
	return max(a,c) <= min(b,d);
}

bool intersect(p a, p b, p c, p d){
	return intersect_1(a.x, b.x, c.x, d.x) &&
		   intersect_1(a.y, b.y, c.y, d.y) &&
			area(a,b,c) * area(a,b,d) <= 0 &&
			area(c,d,a) * area(c,d,b) <= 0;
}

int main(){
	p a, b, c,d ;
	cin >> a.x >> a.y >> b.x >> b.y;
	cin >> c.x >> c.y >> d.x >> d.y;
	cout << (intersect(a,b,c,d)? "YES":"NO") << endl;
	return 0;
	
}




