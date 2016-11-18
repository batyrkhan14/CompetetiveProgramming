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
	string ss;
	cin >> ss;
	long long n = 0;
	char s = ss[ss.size()-1];
	for (int i = 0; i < (int)ss.size()-1; i++){
		n = n*10+ss[i]-'0';
	}
	long long ans = 0;
	if (n%4 == 1 || n%4 == 2){
		ans += 6*((n/4)*2 + (n%4-1)) + n-1;
	}
	else{
		ans += 6*((n-1)/4*2 + (n+1)%4) + n-3;
	}
	if (s >= 'a' && s <= 'c'){
		ans += 3 + s-'a';
	}	
	else{
		ans += 'f'-s;
	}
	cout << ans+1 << endl;
	return 0;
}