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

#define left(i) i << 1
#define right(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int k, n, dif[2005], hit[2005];
unordered_map<int, int> occ;
vector<int> levels;

int main(){
    // cin.sync_with_stdio(0);
    // cin.tie(0);
    scanf("%i %i", &k, &n);
    int x, run=0;
    for(int i = 1; i <= k; i++){
        scanf("%i", &x);
        run += x;
        if(occ.find(run) != occ.end()){
            occ[run]++;
        }else{
            occ[run] = 1;
            levels.pb(run);
        }
    }
    for(int i = 0; i < n; i++){
        scanf("%i", &hit[i]);
    }
    sort(hit, hit+n);
    for(int i = 0; i < n-1; i++){
        dif[i] = hit[i+1]-hit[i];
    }
    sort(levels.begin(), levels.end());
    int cnt =0;
    int sz = levels.size();
    for(int i = 0; i < sz; i++){
        bool bad = false;
        int cur = i, prev=i;
        for(int j = 0; j < n-1; j++){
            while(levels[cur]-levels[prev] < dif[j] && cur < sz-1){
                cur++;
            }
            if(levels[cur]-levels[prev] == dif[j]){
                prev = cur;
            }else{
                bad = true;
            }
        }
        if(!bad) cnt++;
    }
    printf("%i", cnt);
}