#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> first,second,result;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        first.push_back(temp);
    }
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        second.push_back(temp);
    }
    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    vector<int>::iterator it2 = second.begin();
    vector<int>::iterator it = first.begin();
    while(it != first.end() && it2 != second.end()){
        if(*it > *it2) it2++;
        else if(*it2 > *it) it++;
        else if(*it2 == *it){
            if(result.size() == 0) result.push_back(*it);
            else if(result[result.size() - 1] != *it) result.push_back(*it);
            it++;
        }
    }
    for(auto x:result) cout << x << " ";
    return 0;
}