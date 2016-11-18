#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;
bool beat(int a, int b, int n){
	int xa = a%n, ya = a/n, xb = b%n, yb = b/n;
	return (xa == xb || ya == yb || (xa+ya==xb+yb) || (xa-ya)==(xb-yb));
}
int ans(int n){
	int x = n*n;
	int res = 0;
	for (int i = 0; i < x; i++){
		for (int j = i+1; j < x; j++){
			for (int k = j+1; k < x; k++){
				if (!beat(i, j, n) && !beat(i, k, n) && !beat(k, j, n)){
					res++;
				}
			}
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
	for (int i = 1; i < 20; i++){
		cout << "ans[" << i << "] = BigInteger.valueOf(" << ans(i) << ");" << endl;
	}

	return 0;
}