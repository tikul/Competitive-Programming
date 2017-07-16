#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;
int main() {
    int b, f, c, d, e, t;
    scanf("%i", &b);
    list<vector<int>> batches;
    int total = 0;
    for(int i = 0; i < b; i++){
        scanf("%i %i %i", &c, &d, &e);
        batches.push_back({c,d,e});
        total += e;
    }
    scanf("%i", &f);
    set<int> tc;
    for(int i = 0; i < f; i++){
        scanf("%i", &t);
        tc.insert(t);
    }
    for(auto j = batches.begin(); j != batches.end(); j++){
        auto it = tc.lower_bound((*j)[0]);
        if (it != tc.end() && (*it) <= (*j)[1])
            total -= (*j)[2];
    }
    printf("%i", total);
}