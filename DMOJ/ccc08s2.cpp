#include <iostream>
#include <vector>
#include <cmath>

int main() {
    bool done = false;
    int in, p;
    std::vector<int> pennies;
    while(!done){
        scanf("%i", &in);
        if(in == 0)
            done = true;
        else{
            p = 0;
            for(int i = 1; i <= floor(in/sqrt(2)); i++){
				p += floor(sqrt(in*in - i*i)) - i;
            }
            pennies.push_back(4*floor(in/sqrt(2)) + 4*in + 8*p +1);
        }
    }
    for(int i = 0; i < pennies.size(); i++)
        printf("%i\n", pennies[i]);
}