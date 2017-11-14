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
int a[55][55];
long long cnt=0;

int main(){
    // cin.sync_with_stdio(0);
    // cin.tie(0);
    cin >> n >> m;
    cnt += n*m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        int bcnt = 0, wcnt = 0;
        for(int j = 0; j < m; j++){
            if(a[i][j]) bcnt++;
            else wcnt++;
        }
        cnt += (1LL<<bcnt) - bcnt - 1;
        cnt += (1LL<<wcnt) - wcnt - 1;
    }

    for(int j = 0; j < m; j++){
        int bcnt = 0, wcnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i][j]) bcnt++;
            else wcnt++;
        }
        cnt += (1LL<<bcnt) - bcnt - 1;
        cnt += (1LL<<wcnt) - wcnt - 1;
    }
    cout << cnt;


}