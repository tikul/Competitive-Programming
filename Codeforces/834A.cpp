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

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    char start, end;
    int fi, se, n;
    int conv[4] = {118, 60, 94, 62};
    cin >> start >> end;
    for(int i = 0; i < 4; i++){
        if(start == conv[i]){
            fi = i;
        }
        if(end == conv[i]){
            se = i;
        }
    }
    cin >> n;
    n %= 4;
    if(n % 2 == 0){
        cout << "undefined";
    }else{
        if( (fi+n)%4 == se){
            cout << "cw";
        }else{
            cout << "ccw";
        }
    }
    //cout << "\n" << fi << " " << se;
}