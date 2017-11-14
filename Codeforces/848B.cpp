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

#define MAXN 100000
int n, w, h;
vector<pii> hori[2*MAXN+3];
vector<pii> vert[2*MAXN+3];
pii ans[MAXN+3];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> n >> w >> h;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        if(a==1){
            vert[b-c+MAXN].pb({b, i});
        }else{
            hori[b-c+MAXN].pb({b, i});
        }
    }
    for(int i = -MAXN; i <= MAXN; i++){
        int j = i+MAXN;
        int sz1 = hori[j].size();
        int sz2 = vert[j].size();
        if(sz1 && sz2){
            sort(hori[j].begin(), hori[j].end());
            sort(vert[j].begin(), vert[j].end());
            if(sz2 <= sz1){
                int k = sz1-1;
                for(int l = 0; l < sz2; l++, k--){
                    ans[hori[j][k].second] = {vert[j][l].first, h};
                }
                for(int l = sz1-1; k >= 0; k--, l--){
                    ans[hori[j][k].second] = {w, hori[j][l].first};
                }
                for(int l = sz2-1, m = 0; l >= 0; l--, m++){
                    ans[vert[j][l].second] = {w, hori[j][m].first};
                }
            }else{
                for(int k = sz1-1, l = 0; k >= 0; l++, k--){
                    ans[hori[j][k].second] = {vert[j][l].first, h};
                }
                for(int l = sz2 - 1, k = 0; k < sz1; k++, l--){
                    ans[vert[j][l].second] = {w, hori[j][k].first};
                }
                for(int m = sz1, l = 0; m < sz2; l++, m++){
                    ans[vert[j][l].second] = {vert[j][m].first, h};
                }
            }
        }else if(sz1){
            for(pii x : hori[j]){
                ans[x.second] = {w, x.first};
            }
        }else if(sz2){
            for(pii x : vert[j]){
                ans[x.second] = {x.first, h};
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}