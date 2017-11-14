#include <stdio.h>
#include <algorithm>
#include <vector>
#define mod 1000000007
using namespace std;

int n;
vector<int> a;

int main(){
    scanf("%i", &n);
    int ones = 0, twos=0;
    int small = 0;
    int x;
    for(int i = 0; i < n; i++){
        scanf("%i", &x);
        if(x==1) ones++;
        else{
            small += x;
            if(x==2)twos++;
            else a.push_back(x);
        }
    }
    printf("%i\n", max(1, small));
    long long res = 1;
    int c = min(ones, twos);
    for(int i = 0; i < c; i++){
        a.push_back(3);
    }
    ones -= c;
    twos -= c;
    if(ones){
        int t = ones/3;
        for(int i = 0; i < t; i++){
            a.push_back(3);
        }
        if(ones % 3 == 2){
            a.push_back(2);
        }
    }else if(twos){
        for(int i = 0; i < twos; i++){
            a.push_back(2);
        }
    }
    sort(a.begin(), a.end());
    if(ones % 3 == 1 && n != 1){
        a[0]++;
    }
    for(int x : a){
        res = (res*x)%mod;
    }
    printf("%lli", res);
}