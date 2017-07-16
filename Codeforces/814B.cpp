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

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int n;
int arr[52][52];

set<int> rows[52];
unordered_set<int> cols[52];

int main(){
    // cin.sync_with_stdio(0);
    // cin.tie(0);
    scanf("%i", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%i", &arr[i][j]);
            rows[i].insert(arr[i][j]);
            cols[j].insert(arr[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            bool good = false;
            int goal = arr[i][j];
            if(goal == 1) continue;
            for(int k : rows[i]){
                if(cols[j].find(goal-k) != cols[j].end()){
                    good = true;
                }
            }
            if(!good){
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes");
}