#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[100005], n, x;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n==1){
        cout << 0;
        return 0;
    }
    sort(a, a+n);
    int v1 = a[n-1] - a[1];
    if(x >= a[n-1]) v1 += x-a[n-1];
    else if(x <= a[1]) v1 += a[1]-x;
    else v1 += min(a[n-1]-x, x-a[1]);
    int v2 = a[n-2] - a[0];
    if(x >= a[n-2]) v2 += x-a[n-2];
    else if(x <= a[0]) v2 += a[0]-x;
    else v2 += min(a[n-2]-x, x-a[0]);
    cout << min(v1, v2);
}