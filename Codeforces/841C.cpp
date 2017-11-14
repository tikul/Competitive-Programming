#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <unordered_set>
#include <functional>
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

int m, ans[200005];
pii A[200005], B[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    int x;
    for(int i = 0; i < m; i++){
        cin >> x;
        A[i] = mp(x, i);
    }
    for(int i = 0; i < m; i++){
        cin >> x;
        B[i] = mp(x, i);
    }
    sort(A, A+m, greater<pii>());
    sort(B, B+m);
    for(int i = 0; i < m; i++){
        ans[B[i].second] = A[i].first;
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << " ";
    }
}