#include <stdio.h>

int t;
unsigned long long x, y;

int main(){
    scanf("%i", &t);
    while(t--){
        int ans = 0;
        scanf("%lli", &x);
        y = x;
        while(x > 0){
            ans++;
            if(x%2==0){
                x /= 2;
            }else{
                if((x&2) && x!=3) x++;
                else x--;
            }
        }
        printf("%i\n", ans);
    }
}