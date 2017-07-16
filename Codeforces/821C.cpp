#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <unordered_set>
#include <set>
#include <unordered_map>

using namespace std;

#define left(i) i << 1
#define right(i) i << 1 | 1
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int a, b;

int main(){
    // cin.sync_with_stdio(0);
    // cin.tie(0);
    scanf("%i %i", &a, &b);
    int c = min(a, b);
    int ans = 1;
    while(c > 0){
        ans *= c;
        c--;
    }
    printf("%i", ans);
}