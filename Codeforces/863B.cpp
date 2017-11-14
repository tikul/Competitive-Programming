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

pii ar[102];
int n;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x;
    for(int i = 0; i < 2*n; i++){
        cin >> x;
        ar[i] = {x,i};
    }
    sort(ar, ar+2*n);
    int lo = 9999999;
    for(int a = 0; a < 2*n; a++){
        for(int b = a+1; b < 2*n; b++){
            int cur = 0;
            int i = 0;
            while(i < 2*n){
                while(ar[i].second == a || ar[i].second == b) ++i;
                if(i >= 2*n) break;
                int j = i+1;
                while(ar[j].second == a || ar[j].second == b) ++j;
                cur += ar[j].first - ar[i].first;
                i = j+1;
            }
            lo = min(cur, lo);
        }
    }
    cout << lo;
}