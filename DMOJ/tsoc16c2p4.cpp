#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

bool dp[10005];
vector<int> primes;
int n, m;

void getprimes(){
    for(int i = 2; i <= n; i++){
        int root = sqrt(i);
        bool comp = false;
        for(int j = 2; j <= root && !comp; j++){
            if(i%j==0) comp = true;
        }
        if(!comp) primes.push_back(i);
    }
}

int main(){
    scanf("%i %i", &n, &m);
    getprimes();
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int val;
    for(int i = 0; i < m; i++){
        scanf("%i", &val);
        for(int j = n; j >= 0; j--){
            dp[j] = 0;
            for(int k : primes){
                if(val*k > j) break;
                if(dp[j-val*k]){
                    dp[j] = 1;
                    break;
                }
            }
        }
    }
    for(int k : primes){
        if(dp[k]){
            printf("its primetime");
            return 0;
        }
    }
    printf("not primetime");
}