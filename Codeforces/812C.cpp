#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pli pair<long long, int>
#define ppi pair<pair<int,int>, int>
#define inf 1<<30
typedef long long lli;

using namespace std;

int n, s;
pli arr[100003];
lli ans =0;
int main(){
    cin >> n >> s;
    int lo = 0, hi = n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    int best = 0;
    lli bprice = 0;
    int prevk = 0;
    while(lo <= hi){
        int k = (lo+hi)/2;
        for(int i = 0; i < n; i++){
            arr[i].first += (1LL * arr[i].second*(k-prevk));
        }
        sort(arr, arr+n);
        lli tot = 0;
        for(int i = 0; i < k; i++){
            tot += arr[i].first;
        }
        if(tot > s){
            hi = k-1;
        }else{
            if(k > best){
                best = k;
                bprice = tot;
            }
            lo = k+1;
        }
        prevk = k;
    }
    cout << best << " " << bprice << "\n";
}