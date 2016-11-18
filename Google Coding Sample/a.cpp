#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;
string solution(string &S, int K) {
    int n = S.size();
    int dashes = 0;
    string result = "";
    for (int i = 0; i < n; i++){
        if (S[i] == '-'){
            dashes++;
        }
        else{
            if (S[i] >= 'a' && S[i] <= 'z'){
                S[i] = S[i]-'a'+'A';   
            }
        }
    }
    int ch = n-dashes;
    int first = ch%K;
    int j = 0;
    for (int i = 0; i < first; i++){
    	while (j < n && S[j] == '-') j++;
    	if (j < n){
    		result += S[j];
    		j++;
    	}
    }
    while (j < n){
    	if (result.size() != 0){
    		result += '-';
    	}
    	for (int i = 0; i < K; i++){
	    	while (j < n && S[j] == '-') j++;
	    	if (j < n) {
	    		result += S[j];
	    		j++;
	    	}
    	}
    }
    return result;
}

int main(){
	ios_base::sync_with_stdio(0);
	freopen("a.in", "r", stdin);
    string s = "dsandsanjkdnaskjdnasjkdnjkasndjkasndjknsakjdnasjkndasjkndjkasndjkasnjkndjskand";
	cout << solution(s, 56) << endl;
	return 0;
}