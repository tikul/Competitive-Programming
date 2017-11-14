#include <iostream>
using namespace std;

int a[100005], b[100005];
int na, nb, k, m;

int main(){
    cin >> na >> nb >> k >> m;
    for(int i = 0; i < na; i++) cin >> a[i];
    for(int i = 0; i < nb; i++) cin >> b[i];
    if(a[k-1] < b[nb-m]){
        cout << "YES";
    }else{
        cout << "NO";
    }
}