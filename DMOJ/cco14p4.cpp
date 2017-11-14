#include <stdio.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#define pii pair<int, int>
#define INF 0x3f3f3f3f
using namespace std;
int n, p;
vector<pii> xy;

int main(){
    scanf("%i %i", &n, &p);
    int a, b;
    int cur = 0;
    int vis = 1;
    for(int i = 1; i <= n; i++){
        scanf("%i %i", &a, &b);
        if(i == p) cur = a;
        else if(a >= b) xy.push_back({b, a-b});
    }
    sort(xy.begin(), xy.end());
    for(int i = 0; i < xy.size(); i++){
        a = xy[i].first, b = xy[i].second;
        if(cur < a) break;
        ++vis;
        cur += b;
    }
    printf("%i\n%i", cur, vis);
}