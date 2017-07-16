#include <iostream>
#include <cstring>

int bit[1026][1026];
int S, a, r1, r2, c1, c2, v;

void update(int i, int j, int x){
    for(; i <= S; i+= i&-i){
        int y = j;
        for(; y <= S; y += y&-y){
            bit[i][y] += x;
        }
    }
}

int query(int i, int j){
    int ret = 0;
    for(; i>0; i-= i&-i){
        int y = j;
        for(; y>0; y -= y&-y){
            ret += bit[i][y];
        }
    }
    return ret;
}

int main(){
    scanf("%i %i", &a, &S);
    memset(bit, 0, sizeof(bit));
    int ans;
    scanf("%i", &a);
    while(a != 3){
        if(a == 1){
            scanf("%i %i %i", &r1, &c1, &v);
            update(r1+1, c1+1, v);
        }else{
            scanf("%i %i %i %i", &r1, &c1, &r2, &c2);
            r1++;r2++;c1++;c2++;
            ans = query(r2, c2) + query(r1-1, c1-1) - query(r1-1, c2) - query(r2, c1-1);
            printf("%i\n", ans);
        }
        scanf("%i", &a);
    }
}