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

int n, m, j;
vector<pii> mud;
set<int> dry;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> j;
    if(j==n+1){
        cout << 0;
        return 0;
    }
    int p, t;
    for(int i = 0; i < m; i++){
        cin >> p >> t;
        mud.pb({t,p});
    }
    sort(mud.begin(), mud.end());
    int cur = 0;
    for(int i = 0; i < m; i++){
        t = mud[i].first;
        p = mud[i].second;
        dry.insert(p);
        bool changed = true;
        while(changed){
            changed = false;
            if(p > cur && p-cur <= j){
                changed = true;
                cur = p;
                if(n+1-p <= j){
                    cout << t;
                    return 0;
                }
                auto far = dry.upper_bound(p);
                p = *far;
            }
        }
    }
    cout << -1;
}