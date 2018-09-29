#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>

using namespace std;

template <class T>
vector<T> input_split() {
    cin >> ws;
    string line;
    getline(cin, line);
    stringstream ss(line);
    T buf;
    vector<T> tokens;
    while (ss >> buf)
        tokens.push_back(buf);
    return tokens;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> atemp;
    atemp = input_split<int>();
    set<int> a(atemp.begin(),atemp.end());
    vector<int> b;
    b = input_split<int>();
    vector<string> result;
    for(auto x:b){
        int count = 0;
        for(auto y:a){
            int find = x-y;
            if(a.count(find)){
                count++;
            }
        }
        if(count > 0){
            result.push_back("YES");
        } else result.push_back("NO");
    }
    for(auto x:result){
        cout<<x<<endl;
    }
    return 0;
}