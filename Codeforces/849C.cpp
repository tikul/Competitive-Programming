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
#include <cmath>
using namespace std;
#define sL(i) i << 1
#define sR(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int k;
string ans = "";

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    if(k==0){
        cout << "a";
        return 0;
    }
    int i = 0;
    while(k){
        int res = (1 + sqrt(1+8*k))/2;
        k -= (res)*(res-1)/2;
        for(int j = 0; j < res; j++){
            ans += 'a'+i;
        }
        i++;
    }
    cout << ans;
}