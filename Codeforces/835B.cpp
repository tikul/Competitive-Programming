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
    int k, counts[10];
    memset(counts, 0, sizeof(counts));
    string n;
    cin >> k >> n;
    int len = n.length();
    int sum = 0;
    for(int i = 0; i < len; i++){
        counts[n[i]-'0']++;
        sum += n[i]-'0';
    }
    if(sum >= k){
        cout << "0";
        return 0;
    }
    int cnt = 0;
    for(int i = 0; i < 10 && sum < k; i++){
        while(counts[i] && sum < k){
            sum += 9-i;
            counts[9]++;
            counts[i]--;
            cnt++;
        }   
    }
    cout << cnt;

}