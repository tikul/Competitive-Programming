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
#include <map>
using namespace std;
#define sL(i) i << 1
#define sR(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int n, k, a[100005];
map<int, int> cnt;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ++cnt[a[i]];
    }
    if(k==1){
        auto it = cnt.begin();
        cout << it->first;
    }else if(k > 2){
        auto it = cnt.rbegin();
        cout << it->first;
    }else{
        int lo = 0x3f3f3f3f;
        int obest = -0x3f3f3f3f;
        for(int i = 0; i < n-1; i++){
            lo = min(lo, a[i]);
            if(--cnt[a[i]]==0) cnt.erase(a[i]);
            auto it = cnt.begin();
            int tbest = max(it->first, lo);
            obest = max(obest, tbest);
        }
        cout << obest;
    }

}