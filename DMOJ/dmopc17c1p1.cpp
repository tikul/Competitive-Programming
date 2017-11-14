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

int rows[1005], cols[1005];
int r, c, q;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    char x;
    memset(rows, 0, sizeof rows);
    memset(cols, 0, sizeof cols);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> x;
            if(x=='X'){
                rows[i+1] = 1;
                cols[j+1] = 1;
            }
        }
    }
    cin >> q;
    bool can = false;
    while(q--){
        int x, y;
        cin >> x >> y;
        can = false;
        if(rows[y] || cols[x]){
            cout << "Y\n";
        }else{
            cout << "N\n";
        }
    }
}