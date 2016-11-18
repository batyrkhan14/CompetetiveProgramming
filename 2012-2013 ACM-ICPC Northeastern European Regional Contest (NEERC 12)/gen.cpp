#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
	srand(time(0));
	freopen("a.in", "w", stdout);
	int n = 262130;
	cout << n << endl;
	char j = 'a';
	for (int i = 0; i < n; i++){
		int x = rand()%2;
		int y = rand()%26;
		char b;
		if (x == 0){ b = 'a';}
		else{
			b = 'A';
		}
		cout << (char)(b+y);
	}
	cout << endl;
	return 0;
}