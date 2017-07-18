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
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int n, arr[105], wat[105];

int main(){
    // cin.sync_with_stdio(0);
    // cin.tie(0);
    scanf("%i", &n);
    int x;
    for(int i = 0; i < n; i++){
        scanf("%i", &wat[i]);
        if(i > 0){
            arr[i] = wat[i]-wat[i-1];
        }
    }
    bool bad = false;
    int pt=-1;
    for(int i = 1; i < n; i++){
        if(arr[i] == 0){
            pt = i;
            break;
        }
    }
    if(pt == -1){
        int h = 1;
        while(h < n && arr[h] > 0){
            h++;
        }
        for(int i = h; i < n; i++){
            if(arr[i] > 0){
                bad = true;
            }
        }
    }else{
        int end=pt;
        for(int i = pt; i < n; i++){
            if(arr[i] == 0){
                end = i;
            }else{
                break;
            }
        }
        for(int i = 1; i < pt; i++){
            if(arr[i] <= 0){
                bad = true;
                break;
            }
        }
        for(int i = end+1; i < n; i++){
            if(arr[i] >= 0){
                bad = true;
                break;
            }
        }
    }
    if(!bad){
        printf("YES");
    }else{
        printf("NO");
    }
}