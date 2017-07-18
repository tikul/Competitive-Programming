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
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int n, m, black=0;
int grid[105][105];

int main(){
    // cin.sync_with_stdio(0);
    // cin.tie(0);
    scanf("%i %i", &n, &m);
    char x;
    int u=999, l=999;
    int d = -1, r = -1;
    pii up, dwn, lft, rt;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            scanf(" %c", &x);
            if(x== 'B'){
                black++;
                grid[i][j] = 1;
                if(i < u){
                    u = i;
                    up = mp(i, j);
                }
                if(i > d){
                    d = i;
                    dwn = mp(i,j);
                }
                if(j < l){
                    l = j;
                    lft = mp(i,j);
                }
                if(j > r){
                    r = j;
                    rt = mp(i, j);
                }
            }else{
                grid[i][j] = 0;
            }
        }
    }
    if(d == -1){
        printf("1");
        return 0;
    }
    int h = d-u+1;
    int w = r-l+1;
    int ans=0;
    bool bad = false;
    if(h == w){
        printf("%i", h*w-black);
        return 0;
    }else if(h > w){
        if(h <= m){
            printf("%i", h*h-black);
        }else{
            bad = true;
        }
    }else if(w > h){
        if(w <= n){
            printf("%i", w*w-black);
        }else{
            bad = true;
        }
    }
    if(bad){
        printf("-1");
    }
}