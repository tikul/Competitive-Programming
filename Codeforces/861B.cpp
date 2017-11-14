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
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int n, m, big[105], small[105];
set<int> good;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(big, 0, sizeof(big));
    memset(small, 0x3f, sizeof(small));
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(a < small[b]){
            small[b] = a;
        }
        if(a > big[b]){
            big[b] = a;
        }
    }
    for(int p = 1; p <= 105; p++){
        bool ok = true;
        for(int i = 1; i <= 100; i++){
            if(big[i] == 0) continue;
            if(small[i] <= (i-1)*p || big[i] > i*p){
                ok = false;
            }
        }
        if(ok){
            good.insert((n-1)/p+1);
        }
    }
    if(good.size() != 1){
        cout << -1;
    }else{
        cout << *good.begin();
    }
}