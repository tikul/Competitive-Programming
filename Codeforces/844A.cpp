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
int k;
bool seen[27];

int main(){
    // cin.sync_with_stdio(0);
    // cin.tie(0);
    cin >> s >> k;
    if(s.length() < k){
        cout << "impossible";
        return 0;
    }
    memset(seen, 0, sizeof(seen));
    int cnt=0;
    for(int i = 0; i < s.length(); i++){
        if(!seen[s[i]-'a']){
            cnt++;
            seen[s[i]-'a'] = 1;
        }
    }
    if(cnt >= k) cout << "0";
    else{
        cout << k-cnt;
    }
    
}