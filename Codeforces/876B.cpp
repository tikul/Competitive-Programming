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


int n, k, m, a[100005], cnt[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ++cnt[a[i]%m];
    }
    for(int i = 0; i < m; i++){
        if(cnt[i]>=k){
            cout << "Yes\n";
            for(int j = 0; j < n && k; j++){
                if(a[j]%m==i){
                    --k;
                    cout << a[j] << " ";
                }
            }
            return 0;
        }
    }
    cout << "No";
}