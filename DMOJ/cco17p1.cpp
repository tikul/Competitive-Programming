#include <iostream>
#include <cmath>
#include <vector>

int K;

int main(){
    scanf("%i", &K);
    int groupsize = 0;
    int nodes = 0;
    int edges = 0;
    std::vector<int> groups;
    while(K){
        groupsize = (1+sqrt(1+(8*K)))/2;
        groups.push_back(groupsize);
        nodes += groupsize;
        edges += groupsize+1;
        K -= (groupsize)*(groupsize-1)/2;
    }
    printf("%i %i\n", nodes+1, edges);
    int current = 1;
    for(int g : groups){
        for(int i = current; i < current+g; i++){
            printf("%i %i\n", i, i+1);
        }
        printf("%i %i\n", current+g-1, current);
        current += g;
    }
}