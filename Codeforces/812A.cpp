#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ppi pair<pair<int,int>, int>
#define inf 1<<30
typedef long long lli;

using namespace std;

int arr[4][4];

int main(){
    for(int i = 0; i < 4; i++){
        for(int j =0; j < 4; j++){
            scanf("%i", &arr[i][j]);
        }
    }
    bool poss = false;
    for(int i = 0; i < 4 && !poss; i++){
        bool ped = arr[i][3];
        if(ped){
            if(arr[i][0] || arr[i][1] || arr[i][2]) poss = true;
            if(arr[(i+1)%4][0]) poss = true;
            if(arr[(i+2)%4][1]) poss = true;
            if(arr[(i+3)%4][2]) poss = true;
        }
    }
    printf(poss?"YES\n":"NO\n");
}