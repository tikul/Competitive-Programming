#include <iostream>
#include <algorithm>
#include <cstring>
#define mod 1000000007
int n, c;
using namespace std;

int main(){
    scanf("%i %i", &n, &c);
    long long pre[2][10007];
    for(int i = 1; i <= 10001; i++)
        pre[0][i] = 1;
    for(int x = 2; x <= n; x++){
        for(int i = 0; i <= 10000; i++){
            pre[1][i+1] = pre[1][i] + (pre[0][i+1] - pre[0][max(0, i+1-x)]) % mod;
        }
        memcpy(pre[0], pre[1], sizeof(pre[1]));
    }
    printf("%i", (pre[0][c+1]-pre[0][c]) %mod);
}