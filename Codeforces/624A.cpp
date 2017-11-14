#include <iostream>
#include <iomanip>
using namespace std;

int d, L, v1, v2;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> d >> L >> v1 >> v2;
    cout << fixed;
    cout << setprecision(8);
    cout << (double) (L-d) / (double) (v1+v2);
}