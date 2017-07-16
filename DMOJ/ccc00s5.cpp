#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;
double coords[100][2];
bool possible[100];

double dist(double x1, double x2, double y){
    return sqrt((x2 - x1)*(x2 - x1) + y*y);
}

int main(){
    int n;
    scanf("%i", &n);
    for(int i = 0; i < n; i++){
        scanf("%lf", &coords[i][0]);
        scanf("%lf", &coords[i][1]);
    }
    for(int i = 0; i < 100001; i++){
        vector<int> aeiou;
        double min_d = 99999;
        for(int j = 0; j < n; j++){
            double d = dist(coords[j][0], i/100.0, coords[j][1]);
            if (d < min_d){
                min_d = d;
                aeiou.clear();
                aeiou.push_back(j);
            }
            else if (d == min_d){
                aeiou.push_back(j);
            }
        }
        for(int z = 0; z < aeiou.size(); z++){
            possible[aeiou[z]] = true;
        }
    }
    for(int i = 0; i < n; i++){
        if (possible[i]){
            printf("The sheep at (%.2lf, %.2lf) might be eaten.\n", coords[i][0], coords[i][1]);
        }
    }
}