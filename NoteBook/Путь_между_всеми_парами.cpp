#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
 
 
 /*
  * На вход программе подаётся граф, заданный в виде матрицы смежности — двумерного массива 
  * d[][] размера n \times n, в котором каждый элемент задаёт длину ребра между с
  * оответствующими вершинами.
	Требуется, чтобы выполнялось d[i][i] = 0 для любых i.*/
	
/*Предполагается, что если между двумя какими-то вершинами нет ребра, то в матрице смежности 
 * было записано какое-то большое число (достаточно большое, чтобы оно было больше длины любого 
 * пути в этом графе); тогда это ребро всегда будет невыгодно брать, и алгоритм сработает правильно.*/
 
 
int main() {
	for (int k=0; k<n; ++k)
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
}
