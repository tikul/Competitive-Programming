#include <stdio.h>
#include <cstring>

int w, d, v, keys[11], goal[11], big=0;
bool reached[11], seen[6][5000001];

int solve(int val, int cur){
    if(cur >= w){
        for(int i = 0; i < v; i++){
            if(val == goal[i]) reached[i] = true;
        }
    }else{
        if(seen[cur][val]) return 0;
        seen[cur][val] = true;
        for(int i = 0; i < d; i++){
            solve(val*keys[i], cur+1);
            solve(val+keys[i], cur+1);
        }
    }
}

int main(){
    memset(reached, 0, sizeof(reached));
    memset(seen, 0, sizeof(seen));
    scanf("%i%i", &w, &d);
    for(int i = 0; i < d; i++){
        scanf("%i", keys+i);
    }
    scanf("%i", &v);
    for(int i = 0; i < v; i++){
        scanf("%i", goal+i);
        if(goal[i]>big) big = goal[i];
    }
    for(int i = 0; i < d; i++){
        solve(keys[i], 0);
    }
    for(int i = 0; i < v; i++){
        if(i) printf("\n");
        printf(reached[i]?"Y":"N");
    }
}