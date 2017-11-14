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

int n, m;
set<int> a, b;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        a.insert(x);
    }
    int lo = 12;
    for(int i = 0; i < m; i++){
        cin >> x;
        if(a.count(x)){
            lo = min(lo, x);
        }
        b.insert(x);
    }
    if(lo != 12){
        cout << lo;
    }else{
        int f = *a.begin();
        int s = *b.begin();
        cout << min(f,s) << max(f,s);
    }
}