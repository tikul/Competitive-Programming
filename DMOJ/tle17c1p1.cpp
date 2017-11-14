#include <stdio.h>

char s[105];
int n;

int main(){
    scanf("%s%n", s, &n);
    bool a_start = false;
    for(int i = n-1; i >= 0; i--){
        if(s[i] <= 'm'){
            s[i] = 'a';
            break;
        }
        s[i] = 'a';
        if(i && s[i-1] != 'z'){
            ++s[i-1];
            break;
        }
        if(!i) a_start = true;
    }
    if(a_start){
        printf("a");
    }
    printf("%s", s);
}