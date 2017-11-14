#include <algorithm>
#include <stdio.h>
using namespace std;

int main(){
    int N, K;
    scanf("%i %i", &N, &K);
    int res = N%K;
    if(N/K == 0){
        printf("%i", K-res);
    }else{
        printf("%i", min(K-res, res));
    }   
}