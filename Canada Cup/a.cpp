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
	//freopen("a.in","r",stdin);
	int n;
	cin >> n;
	string ss;
	cin>> ss;
	
	int ans = 0;
	int kek = true;
	for(int i = 0; i <n;i++){
		if(ss[i] == '<' && kek) ans++;
		else kek = false; 
	}
	kek = true;
	for(int i = n-1; i >=0; i--){
		if(ss[i] == '>' && kek) ans++;
		else kek = false; 
	}
	cout << ans << endl;
}