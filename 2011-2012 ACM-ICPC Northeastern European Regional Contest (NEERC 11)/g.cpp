#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;
bool prime(int p){
	if (p == 1) return false;
	for (int i = 2; i*i <= p; i++){
		if (p%i == 0) return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio();
	freopen("gcd.in", "r", stdin);
	freopen("gcd.out", "w", stdout);
	int n;
	vector<int> primes;
	cin >> n;
	for (int i = 2; i <= n; i++){
		if (prime(i)) primes.push_back(i);
	}
	int ans = 0;
	int i = 0;
	int j = primes.size()-1;
	for (;i <= j;){
		if (i < j){
			if (primes[i]*primes[j] <= n){
				ans ++;
				i++;
				j--;
			}
			else{
				ans++;
				j--;
			}
		}
		else if (i == j){
			ans++;
			i++;
			j--;
		}
	}
	cout << ans << endl;
	return 0;	
}