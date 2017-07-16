#include <iostream>
#include <algorithm>

int N, A[1000001];

int main(){
    scanf("%i", &N);
    for(int i =0; i < N; i++){
        scanf("%i", &A[i]);
    }
    std::sort(A, A+N);
    int best = 1<<30;
    for(int i = 0; i < N-1; i++){
        if (A[i+1]-A[i] < best){
            best = A[i+1]-A[i];
        }
    }
    printf("%i", best);
}