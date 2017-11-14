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

int n;
vector<int> v;

int sumdig(int x){
    int res = 0;
    while(x){
        res += x%10;
        x/=10;
    }
    return res;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int cnt = 0;
    for(int i = n-81; i <= n-1; i++){
        if(sumdig(i)==n-i){
            ++cnt;
            v.pb(i);
        }
    }
    cout << cnt << "\n";
    for(int x : v){
        cout << x << "\n";
    }
}