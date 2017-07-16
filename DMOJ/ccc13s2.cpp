#include <iostream>

int main() {
    int w, n, current_weight{0};
    int bridges[1000001];
    scanf("%i", &w);
    scanf("%i", &n);
    int t = n;
    bool ignore = false;
    for(int i = 0; i < n; i++){
        scanf("%i", &bridges[i]);
        if(!ignore){
            if(i < 4)
                current_weight += bridges[i];
            else
                current_weight += bridges[i] - bridges[i-4];
            if(current_weight > w){
                t = i;
                ignore = true;
            }    
        }
    }
    printf("%i", t);
}