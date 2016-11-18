#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

string s1, s2, s3, s4, s5, s6;
char a[10], b[10], bb[10], s[10], ss[10], sa[10], se[10];
bool was[10], w[10];
int k, kk, d[10], q = 0;
map<string, bool> pp;

bool check(string ss)	{
	int i;
	for (i = 1; i <= 4; i++)
		bb[i] = ss[i];
	sort(bb + 1, bb + 5);
	for (i = 1; i <= 6; i++)
		if (!w[i] && ss[0] == s[i])	{
			int l;
			k = 0;
			for (l = 1; l <= 6; l++)
				if (l != d[i] && i != l)
					b[++k] = s[l];
			sort(b + 1, b + 5);
			if (b[1] == bb[1] && b[2] == bb[2] && b[3] == bb[3] && b[4] == bb[4])	{
				w[i] = true;
				return true;
			}
		}
	return false;
}

void go(int n)	{
	int j;
	if (n == 7)	{
		int l;

		if (pp[s + 1]) return;
		for (l = 1; l <= 6; l++)	{
			ss[1] = s[l];
			ss[6] = s[d[l]];
			if (l == 1)	
				ss[2] = s[2]; ss[3] = s[3]; ss[4] = s[4]; ss[5] = s[5];
			if (l == 2)	
				ss[2] = s[1]; ss[3] = s[3]; ss[4] = s[6]; ss[5] = s[5];
			if (l == 3)	
				ss[2] = s[1]; ss[3] = s[2]; ss[4] = s[6]; ss[5] = s[4];
			if (l == 4)	
				ss[2] = s[5]; ss[3] = s[6]; ss[4] = s[3]; ss[5] = s[1];
			if (l == 5)	
				ss[2] = s[4]; ss[3] = s[6]; ss[4] = s[2]; ss[5] = s[1];
			if (l == 6)	
				ss[2] = s[5]; ss[3] = s[4]; ss[4] = s[3]; ss[5] = s[2];
			se[1] = ss[2];
			se[2] = ss[3];
			se[3] = ss[4];
			se[4] = ss[5];
			for (int z = 1; z <= 4; z++)	{
				int x = z; 
				for (int r = 2; r <= 5; r++)	{
					ss[r] = se[x++];
					if (x > 4) x = 1;
				}
				if (s[1] == 'A' && s[2] == 'B' && s[3] == 'C')
					cout<<"string "<<ss + 1<<endl;
				pp[ss + 1] = true;
			}
		}

		for (l = 1; l <= 6; l++)
			w[l] = false;	
		if (check(s1) && check(s2) && check(s3) && check(s4) && check(s5) && check(s6))	{
			q = 1;
			printf("%s\n", s + 1);
			if (++kk == 2) exit(0); 
		}
		return;
	}
	for (j = 1; j <= 6; j++)	{
		if (!was[j])	{
			was[j] = true;
			s[n] = a[j];
			go(n + 1);
		}
		was[j] = false;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	freopen("cube.in", "r", stdin);
	//freopen("cube.out", "w", stdout);
	cin>>s1>>s2>>s3>>s4>>s5>>s6;

	a[1] = s1[0];
	a[2] = s2[0];
	a[3] = s3[0];
	a[4] = s4[0];
	a[5] = s5[0];
	a[6] = s6[0];
	d[1] = 6;
	d[2] = 4;
	d[3] = 5;
	d[4] = 2;
	d[5] = 3;
	d[6] = 1;
	go(1);
	if (q == 0) printf("Impossible");
	return 0;
}