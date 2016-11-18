#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#define INF 100000000
using namespace std;
char cnt[2][13];

int main(){
    ios_base::sync_with_stdio(0);
    freopen("a.in","r",stdin);
    string s;
    cin >> s;
    int n = 27;
    int o1, o3;
    for(int i = 0; i < 27; i++){
        for(int j = i + 1; j < 27; j++){
            if(s[i] == s[j]){
                o1 = i;
                o3 = j;
                if(j == i+1){
                    cout << "Impossible";
                    return 0;
                }
            }
        }
    }
    int index = 0;
    for(int i = o1+1; i < (o3+o1+1)/2; i++){
        cnt[0][index] = s[o1+(o3+o1+1)/2 - i];
        index++;
    }
    int index2 = 0;
    for(int i = (o1 + o3 + 1)/2; i < o3; i++){
        cnt[1][index2] = s[i];
        index2++;
    }
    cnt[0][index] = s[o1];
    index++;
    int state2 = o1-1;
    while(index < 13 && state2 >= 0){
        cnt[0][index] = s[state2];
        state2--;
        index++;
    }
    int state4 = o3+1;
    while(index2 < 13 && state4 < 27){
        cnt[1][index2] = s[state4];
        state4 ++;
        index2 ++;
    }
    if(index == 13){
        int lol = 12;
        while(state2<o1 && index2<13){
            cnt[1][lol] = s[state2];
            lol--;
            state2++;
        }
    }
    else{
        int lol = 12;
        while(state4 < 27){
            cnt[0][lol] = s[state4];
            lol--;
            state4++;
        }
    }
    for(int i = 0; i<2; i++){
        for(int j = 0; j<13; j++){
            cout << cnt[i][j];
        }
        cout << endl;
    }
    return 0;
}