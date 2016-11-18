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
	freopen("dice.in", "r", stdin);
	freopen("dice.out", "w", stdout);
	int n, sum = 0;
	scanf("%d", &n);
	vector<pair<int, int> > a;
	for (int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		sum += x;
		a.push_back(make_pair(x, i));
	}
	sort(a.begin(), a.end());
	vector<int> ans[1010];
	double exp = 0;
	for (int i = 0; i < n; i++){
		double ex = 0;
		for (int j = 0; j < a[i].first; j++){
			ans[a[i].second].push_back(sum);
			ex += (double)sum;
			sum--;
		}
		ex /= (double)a[i].first;
		exp += ex;
	}
	printf("%6lf\n", exp);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < ans[i].size(); j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}