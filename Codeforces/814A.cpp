#include <iostream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>

typedef long long lli;

using namespace std;

int n, k;
int hitagi[105], kaiki[105];

int main(){
    scanf("%i%i", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%i", &hitagi[i]);
    }
    for(int i = 0; i < k; i++){
        scanf("%i", &kaiki[i]);
    }
    sort(kaiki, kaiki+k);
    bool pos = false;
    int last = 0;
    for(int i = 0; i < n && !pos; i++){
        if(hitagi[i] != 0 && hitagi[i] < last)
            pos = true;
        last = hitagi[i];
    }
    for(int i = 1; i < n && !pos; i++){
        if(hitagi[i]==0 && hitagi[i-1]==0){
            pos = true;
        }else if(hitagi[i]==0){
            int hold = hitagi[i-1];
            if (kaiki[0] < hold)
                pos = true;
        }
    }
    for(int i = 0; i < n-1 && !pos; i++){
        if(hitagi[i]==0){
            int hold = hitagi[i+1];
            if (kaiki[k-1] > hold)
                pos = true;
        }
    }
    printf(pos?"Yes\n":"No\n");
}