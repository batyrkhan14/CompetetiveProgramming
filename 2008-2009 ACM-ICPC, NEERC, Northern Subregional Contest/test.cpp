#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
	multiset<int> ms;
	ms.insert(1);
	ms.insert(3);
	ms.insert(3);
	ms.insert(3);
	ms.insert(5);
	ms.insert(7);
	multiset<int>::iterator it;
	cout << (1ll<<62) << endl;
	for (it = ms.lower_bound(8); it != ms.upper_bound(5); it++){
		cout << *it << " here ";
	}
	cout << endl;
	return 0;
}