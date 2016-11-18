#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio();
	//freopen("a.in", "r", stdin);
	int k, r;
	cin >> k >> r;
	int i = 1;
	while (true){
		if ((k*i)%10 == 0 || (k*i)%10 == r){
			cout << i << endl;
			return 0;
		}
		i++;
	}
	return 0;
}