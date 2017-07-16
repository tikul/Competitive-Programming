#include <iostream>

int N, l, r, layers[200011];

int main(){
    scanf("%i", &N);
    l = 100002;
    r = 100003;
    char t;
    for(int i = 1; i <= N; i++){
        scanf(" %c", &t);
        if (t == '1')
            layers[r++] = i;
        else
            layers[l--] = i;
    }
    for(int i = r-1; i > l; i--)
        printf("%i\n", layers[i]);
}