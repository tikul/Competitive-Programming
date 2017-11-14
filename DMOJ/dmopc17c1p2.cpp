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

ll a[100005], m, n;
unordered_map<ll, ll> abc;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    a[0] = 0;
    ll x, res = 0;
    for(int i = 1; i <= n; i++){
        cin >> x;
        a[i] = (a[i-1] + x)%m;
    }
    abc[0] = 1;
    for(int i = 1; i <= n; i++){
        ll t = a[i];
        if(abc.count(t)){
            res += abc[t];
        }else{
            abc[t] = 0;
        }
        ++abc[t];
    }
    // for(int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    cout << res;
}