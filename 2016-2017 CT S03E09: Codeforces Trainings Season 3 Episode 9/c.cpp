#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;
int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
	int a, b;
	cin >> a >> b;
	if (gcd(a, b) > 1){
		cout << "infinity infinity" << endl;
	}
	else{
		
	}
	return 0;
}