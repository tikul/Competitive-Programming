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

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    pii occ[60];
    int fi[30], la[30];
    memset(fi, -1, sizeof(fi));
    memset(la, -1, sizeof(la));
    for(int i = 0; i < n; i++){
        int x = s[i]-'A';
        if(fi[x] == -1){
            fi[x] = i;
        }
        la[x] = i;
    }
    int cnt = 0;
    int seen = 0;
    for(int i = 0; i < 26; i++){
        if(fi[i] != -1){
            occ[2*seen] = mp(fi[i], 0);
            occ[2*seen+1] = mp(la[i], 1);
            cnt += 2;
            seen++;
        }
    }
    sort(occ, occ+cnt);
    int open = 0;
    bool pos = false;
    for(int i = 0; i < cnt; i++){
        int x = occ[i].first;
        int y = occ[i].second;
        //cout << x << " " << y << "\n";
        if(y == 0){
            open++;
        }else{
            open--;
        }
        if(open > k){
            pos = true;
        }
    }
    if(pos){
        cout << "YES";
    }else{
        cout << "NO";
    }
}