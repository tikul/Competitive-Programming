#include <stdio.h>
#include <algorithm>

int n, m, l, r, x, arr[10002];

int main(){
    scanf("%i %i", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%i", &arr[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%i %i %i", &l, &r, &x);
        int cnt = 0;
        for(int j = l; j <= r; j++){
            if(arr[j] < arr[x])cnt++;
        }
        if(cnt+l==x){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}