#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
#define pii pair<int,int>

pii a[100005];
int n, h[100005], p[100005];

int main(){
    scanf("%i", &n);
    for(int i = 1; i <= n; i++){
        scanf("%i %i", &a[i].first, &a[i].second);
    }
    memset(h, 0, sizeof(h));
    sort(a+1, a+n+1);
    int lis = 0, pprev=-1, fi=1;
    for(int i = 1; i <= n; i++){
        int x = a[i].first, y = a[i].second;
        if(x != pprev){
            for(int j = i-1; j >= fi; j--){
                h[p[j]] = j;
                lis = max(p[j], lis);
            }
            fi = i;
        }
        int lo = 1, hi = lis, temp;
        while(lo <= hi){
            int mid = (lo+hi+1)/2;
            if(a[h[mid]].first < x && a[h[mid]].second < y){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        p[i] = lo;
        pprev = x;
    }
    for(int j = n; j >= fi; j--){
        h[p[j]] = j;
        lis = max(p[j], lis);
    }
    printf("%i", lis);
}