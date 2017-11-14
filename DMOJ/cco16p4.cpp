#include <stdio.h>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

int n, g;
bool a[10002][10][10], temp[10][10];
unordered_map<int, int> vals;

bool flip(int x){
    for(int i = 0; i+1 < n; i++){
        for(int j = 0; j+1 < n; j++){
            if(a[x][i][j] != a[x-1][i][j]){
                a[x][i][j] = !a[x][i][j];
                a[x][i+1][j] = !a[x][i+1][j];
                a[x][i][j+1] = !a[x][i][j+1];
                a[x][i+1][j+1] = !a[x][i+1][j+1];
            }
        }
    }
}

int main(){
    scanf("%i %i", &n, &g);
    char c;
    for(int x = 0; x < g; x++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf(" %c", &c);
                a[x][i][j] = c=='R'?1:0;
            }
        }
        if(x) flip(x);
        int val = 0;
        for(int i = 0; i < n; i++){
            val |= a[x][n-1][i] << i;
        }
        for(int i = 0; i < n-1; i++){
            val |= a[x][i][n-1] << (i+n);
        }
        if(vals.find(val) == vals.end()){
            vals[val] = 1;
        }else{
            vals[val]++;
        }

    }
    int tot = 0;
    for(auto it = vals.begin(); it != vals.end(); it++){
        int v = it->second;
        tot += v*(v-1)/2;
    }
    printf("%i", tot);
}