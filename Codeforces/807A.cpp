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

int n, a[1005], b[1005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    bool changed = false;
    bool lohi = false;
    int lo = 0x3f3f3f3f;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        if(a[i] != b[i]){
            changed = true;
        }
        if(a[i] > lo){
            lohi = true;
        }
        lo = min(lo, a[i]);
    }
    if(changed){
        cout << "rated";
    }else if(!changed && lohi){
        cout << "unrated";
    }else{
        cout << "maybe";
    }
}