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

int n, x;
set<int> ni;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 102; i++){
        ni.insert(i);
    }
    cin >> n >> x;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        ni.erase(a);
    }
    int ans = 0;
    a = *(ni.begin());
    while(a != x){
        ans++;
        if(a > x){
            ni.insert(x);
        }else{
            ni.erase(a);
        }
        a = *(ni.begin());
    }
    cout << ans;
}