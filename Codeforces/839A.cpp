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

int n, k, a[105];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int has = 0;
    int i = 0;
    while(has < k && i < n){
        if(a[i] > 8){
            has += 8;
            a[i+1] += a[i]-8;
        }else{
            has += a[i];
        }
        i++;
    }   
    if(has < k){
        cout << -1;
    }else{
        cout << i;
    }
}