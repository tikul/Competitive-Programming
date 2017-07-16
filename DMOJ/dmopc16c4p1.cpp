#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;
int main() {
    long long n, j;
    unordered_set<long long> powers;
    for(int i = 0; i < 64; i++){
        powers.insert(pow(2,i));
    }
    scanf("%lld", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &j);
        if (powers.find(j) != powers.end())
            printf("T\n");
        else
            printf("F\n");
    }
}