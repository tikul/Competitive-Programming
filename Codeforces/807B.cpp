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
#define sL(i) i << 1
#define sR(i) i << 1 | 1
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>, int> ppi;

int p, x, y;

bool winshirt(int d){
    int a = (d/50)%475;
    for(int i = 0; i < 25; i++){
        a = (a*96+42)%475;
        if(26+a==p) return true;
    }
    return false;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> p >> x >> y;
    int s1=0, s2=0;
    int o = x;
    while(o >= y){
        if(!winshirt(o)){
            o -= 50;
        }else{
            cout << 0;
            return 0;
        }
    }
    while(x < y){
        s1++;
        s2++;
        x += 100;
    }
    int z = x - 50;
    while(!winshirt(x)){
        x += 100;
        s1++;
    }
    if(z < y){
        s2++;
        z += 100;
    }
    while(!winshirt(z) && s2 < s1){
        z += 100;
        s2++;
    }
    cout << min(s1, s2);
}