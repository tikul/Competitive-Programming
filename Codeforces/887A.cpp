#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <unordered_set>
#include <set>
#include <unordered_map>
using namespace std;
#define sL(i) i << 1
#define sR(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

string s;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int cnt = 0;
    int seen = false;
    for(int i = 0; i < s.length(); i++){
        if(s[i]=='0'){
            if(!seen) continue;
            ++cnt;
        }else{
            seen = true;
        }
    }
    if(cnt >= 6){
        cout << "yes";
    }else{
        cout << "no";
    }
}