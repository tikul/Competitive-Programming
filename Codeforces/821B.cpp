#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int m, b;

int main(){
    // cin.sync_with_stdio(0);
    // cin.tie(0);
    scanf("%i %i", &m, &b);
    long long best = 0;
    for(long long y = 0; y <= b; y++){
        long long x = m*(b-y);
        // printf("%i %i\n", x, y);
        best = max(best, 1LL*(1+x)*(1+y)*(x+y));
    }
    long long xint = b*m;
    double qq = m;
    // printf("afdha\n");
    for(long long x = 0; x <= xint; x++){
        long long y = (-x/qq)+b;
        // printf("%i %i\n", x, y);
        best = max(best, 1LL*(1+x)*(1+y)*(x+y));
    }
    cout << best/2;
} 