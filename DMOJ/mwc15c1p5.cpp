#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
string a, b;
vector<int> digpow[10];
bool checked[10];

void powmod10(){
    for(int i = 0; i < 10; i++){
        memset(checked, 0, sizeof(checked));
        int x = i;
        while(!checked[x]){
            digpow[i].push_back(x);
            checked[x] = 1;
            x = (x*i)%10;
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    powmod10();
    cin >> a >> b;
    int v, s1=0, s2=0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] >= 97) v = (a[i]-'a'+1)%10;
        else v = (a[i]-'A'+1)%10;
        s1 = (s1+digpow[v][i%digpow[v].size()])%10;
    }
    if(s1==0) s1=10;
    for(int i = 0; i < b.length(); i++){
        if(b[i] >= 97) v = (b[i]-'a'+1)%10;
        else v = (b[i]-'A'+1)%10;
        s2 = (s2+digpow[v][i%digpow[v].size()])%10;
    }
    if(s2==0) s2=10;
    cout << s1+s2;
}