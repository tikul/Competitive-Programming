#include <stdio.h>
#include <unordered_set>

using namespace std;

int n, k, f[100005];
int count[1000005];

int main(){
    scanf("%i %i", &n, &k);
    for(int i = 0; i < n; i++) scanf("%i", f+i);
    int l = -1;
    int r = 0;
    int dis = 1;
    long long ans = 0;
    count[f[0]] = 1;
    while(l < n-1){
        l++;
        while(dis < k && r < n-1){
            r++;
            if(count[f[r]]==0){
                dis++;
            }
            count[f[r]]++;
            //printf("%i\n", dis);
        }
        if(dis==k){
            ans += n-r;
            //printf("%i %i %i\n", l, r, ans);
        }
        if(count[f[l]]==1){
            //printf("L: %i\n", l);
            dis--;
        }else{
            //printf("L: %i count: %i\n", l, count[f[l]]);
        }
        count[f[l]]--;
        //printf("-------\n");
    }
    printf("%lli", ans);
}