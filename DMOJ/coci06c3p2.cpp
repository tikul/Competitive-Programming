#include <iostream>
#include <cmath>
#include <string>

using namespace std;
int main() {
    string letters = "ABCDEFGHIJKLMNO";
    string n, line;
    int scatter = 0;
    for(int i = 0; i < 4; i++){
        getline(cin, line);
        n += line;
    }
    for(int i = 0; i < 16; i++){
        if (n[i] != letters[i] && n[i] != '.'){
            bool found = false;
            int j = 0;
            while(!found && j < 16){
                if(letters[j] == n[i])
                    found = true;
                else
                    j++;
            }
            scatter += abs(i/4 - j/4) + abs(i % 4 - j % 4);
        }
    }
    cout << scatter;
    return 0;
    
}