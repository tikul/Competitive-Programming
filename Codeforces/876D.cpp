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
int ds[300005];

int find(int x){
    if(ds[x]==x) return x;
    return ds[x] = find(ds[x]);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) ds[i] = i;
    ds[1] = 1;
    cout << "1\n";
    int x;
    for(int i = 1; i <= n; i++){
        cin >> x;
        ds[x] = ds[x-1];
        int hi = find(n);
        cout << i - (n-hi) + 1 << "\n";
    }
}