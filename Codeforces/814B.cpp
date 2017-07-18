#include <iostream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cstring>

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>

typedef long long lli;

using namespace std;

int n, f[1002], s[1002];
int inds1[1003], inds2[1003];
bool avail[1003];

int missing(int spot){
    int ret = n*(n+1)/2;
    for(int i = 1; i <= n; i++)
        ret -= f[i];
    return ret + f[spot];
}

int main(){
    memset(inds1, -1, sizeof(inds1));
    memset(inds2, -1, sizeof(inds2));
    scanf("%i", &n);
    int ff, sf;
    int fs, ss;
    for(int i = 1; i <= n; i++){
        scanf("%i", &f[i]);
        if(inds1[f[i]] != -1){
            ff = inds1[f[i]];
            sf = i;
        }
        inds1[f[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        scanf("%i", &s[i]);
        if(inds2[s[i]] != -1){
            fs = inds2[s[i]];
            ss = i;
        }
        inds2[s[i]] = i;
    }
    if(ff == fs || ff == ss){
        f[sf] = s[sf];
        f[ff] = missing(ff);
        
    }else if(sf == fs || sf == ss){
        f[ff] = s[ff];  
        f[sf] = missing(sf);
    }else{
        f[ff] = s[ff];
        f[sf] = s[sf];
    }
    for(int i = 1; i <= n; i++){
        if(i != 1) printf(" ");
        printf("%i", f[i]);
    }
}