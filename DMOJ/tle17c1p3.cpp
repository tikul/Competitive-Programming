#include <stdio.h>

int N, T, on=0;
char temp[100005];
bool grid[100005];

int main(){
    scanf("%i%i", &N, &T);
    scanf("%s", temp);
    for(int i = 0; i < N; i++){
        grid[i+1] = (temp[i] == '|');
        on += grid[i+1];
    }
    int x;
    while(T--){
        scanf("%i", &x);
        if(grid[x]) --on;
        else ++on;
        grid[x] ^= 1;
        if(grid[1]) printf("1\n");
        else printf("%i\n", N+2*on);
    }   
}