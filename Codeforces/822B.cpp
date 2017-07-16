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

int v1, v2, o2, a ,b, n;

int main(){
    // cin.sync_with_stdio(0);
    // cin.tie(0);
    scanf("%i %i %i", &n, &a, &b);
    v1 = a;
    v2 = b;
    int x, rej=0;
    for(int i = 0; i < n; i++){
        scanf("%i", &x);
        if(x == 1){
            if(v1 > 0){
                v1--;
            }else if(v2 > 0){
                v2--;
                o2++;
            }else if(o2 > 0){
                o2--;
            }else{
                rej++;
            }
        }else{
            if(v2 > 0){
                v2--;
            }else{
                rej += 2;
            }
        }
    }
    printf("%i", rej);
}