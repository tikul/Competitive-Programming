#include <stdio.h>

int a, b;

int main(){
    scanf("%i %i", &a, &b);
    int count = 1;
    while(1){
        if(a - count < 0){
            printf("Vladik");
            break;
        }
        a -= count;
        count++;
        if(b - count < 0){
            printf("Valera");
            break;
        }
        b -= count;
        count++;
    }
}