#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a[4];
int n;

int main(){
    scanf("%i", &n);
    int x;
    for(int i = 0; i < n; i++){
        scanf("%i", &x);
        a[x%3].push_back(x);
    }
    int zero = a[0].size();
    int one = a[1].size();
    int two = a[2].size();
    if(zero > one + two + 1){
        printf("impossible");
        return 0;
    }
    if(zero == 0 && one > 0 && two > 0){
        printf("impossible");
        return 0;
    }
    if(one + two <= zero){
        int i = 1, ind=0;
        for(int x : a[0]){
            printf("%i ", x);
            if(i ==2 && ind >= two) return 0;
            if(i==1 && ind >= one){
                i++;
                ind = 0;
            }
            printf("%i ", a[i][ind]);
            ind++;
        }
        return 0;
    }
    int qq = max(0, zero - 1);
    int gg = max(min(1, one), one - qq);
    int i = 0, j = 0, k = 0;
    while(i < gg){
        printf("%i ", a[1][i]);
        i++;
    }
    while(i < one && j < zero){
        printf("%i %i ", a[0][j], a[1][i]);
        i++; j++;
    }
    while(k < two && j < zero){
        printf("%i %i ", a[0][j], a[2][k]);
        k++; j++;
    }
    while(k < two){
        printf("%i ", a[2][k]);
        k++;
    }
}