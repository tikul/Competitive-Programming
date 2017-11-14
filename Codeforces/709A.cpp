#include <iostream>
using namespace std;
int n,b, d, a[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> b >> d;
    int emptied = 0;
    int tot = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] > b) continue;
        if(tot+a[i]<=d){
            tot += a[i];
        }else{
            tot = 0;
            emptied++;
        }
    }
    cout << emptied;
}