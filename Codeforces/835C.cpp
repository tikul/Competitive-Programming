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

int ps[11][105][105];
int a[11][105][105];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(ps, 0, sizeof(ps));
    memset(a, 0, sizeof(a));
    int n, q, c;
    cin >> n >> q >> c;
    int x, y, s;
    for(int i = 0; i < n; i++){
        cin >> x >> y >> s;
        a[s][x][y]++;
    }
    for(int i = 0; i <= c; i++){
        for(int j = 1; j <= 100; j++){ //r
            for(int k = 1; k <= 100; k++){ // c
                ps[i][j][k] = ps[i][j-1][k] + ps[i][j][k-1] + a[i][j][k] - ps[i][j-1][k-1];
            }
        }
    }
    int t, x1, y1, x2, y2;
    while(q--){
        cin >> t >> x1 >> y1 >> x2 >> y2;
        long long res = 0;
        for(int i = 0; i <= c; i++){
            int amt = ps[i][x2][y2] + ps[i][x1-1][y1-1] - ps[i][x2][y1-1] - ps[i][x1-1][y2];
            res += amt*( (i+t) % (c+1) );
        }
        cout << res << "\n";
    }
}