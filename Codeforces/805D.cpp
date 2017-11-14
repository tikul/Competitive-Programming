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
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

string s;
ll ans = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    ll cnt = 0;
    for(int i = s.length()-1; i >= 0; i--){
        if(s[i]=='a'){
            ans = (ans+cnt)%MOD;
            cnt = (2*cnt)%MOD;
        }else{
            cnt++;
        }
    }
    cout << ans;
}