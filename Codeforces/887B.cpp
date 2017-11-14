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
#include <map>
using namespace std;
#define sL(i) i << 1
#define sR(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int n;
set<int> v[3];
int taken[3] = {0};
int cnts[11] = {0};

bool canmake(int tkn = 0){
    int good = true;
    for(int i = 0; i < 10; i++){
        if(cnts[i] > 0) good = false;
    }
    if(good) return good;
    if(tkn >= n) return false;
    for(int i = 0; i < n; i++){
        if(!taken[i]){
            taken[i] = 1;
            for(int j = 0; j < 10; j++){
                if(cnts[j] > 0 && v[i].count(j)){
                    --cnts[j];
                    bool r = canmake(tkn+1);
                    if(r) return r;
                    ++cnts[j];
                }
            }
            taken[i] = 0;
        }
    }
    return false;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            cin >> x;
            v[i].insert(x);
        }
    }
    bool any = false;
    int i = 1;
    while(1){
        int j = i;
        for(int x = 0; x < 10; x++) cnts[x] = 0;
        for(int x = 0; x < n; x++) taken[x] = 0;
        while(j){
            ++cnts[j%10];
            j /= 10;
        }
        if(!canmake()) break;
        i++;
        any = true;
    }
    cout << (any?i-1:0);
}