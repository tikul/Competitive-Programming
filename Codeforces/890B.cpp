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

int n, last[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x, best, tbest = 0x3f3f3f3f;
    memset(last, -1, sizeof(last));
    int gap = 0;
    for(int i =0; i < n; i++){
        cin >> x;
        last[x] = i;
    }
    for(int i = 0; i <= 200000; i++){
        if(last[i] != -1 && last[i] < tbest){
            tbest = last[i];
            best = i;
        }
    }
    cout << best;
}