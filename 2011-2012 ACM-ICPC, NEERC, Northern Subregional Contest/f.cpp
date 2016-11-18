#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	freopen("flat.in", "r", stdin);
	//freopen("flat.out", "w", stdout);
	int n, c;
	cin >> n >> c;
	int total = 0, bedrooms = 0, balconies = 0;
	for (int i = 0; i < n; i++){
		int area;
		string room;
		cin >> area >> room;
		if (room == "bedroom"){
			bedrooms += area;
		}
		else if (room == "balcony"){
			balconies += area;
		}
		total += area;
	}
	cout << total << endl << bedrooms << endl;
	double cost = ((double)total - ((double)balconies)/2)*(double)c;
	printf("%6lf\n", cost);
	return 0;
}