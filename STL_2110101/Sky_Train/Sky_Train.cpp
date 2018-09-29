#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

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
template <class T>
void print(vector<T> v) {
    cout << "[";
    for (auto it=v.begin(); it!=v.end();) {
        cout << *it;
        if (++it != v.end()) cout << ", ";
    }
    cout << "]\n";
}
int main(){
    map<string,set<string> > BTSmap;
    set<string> pass,temp;
    vector<string> input = input_split<string>();
    while(input.size() == 2){
        BTSmap[input[0]].insert(input[1]);
        BTSmap[input[1]].insert(input[0]);
        input.clear();
        input = input_split<string>();
    }
    for(auto x:BTSmap[input[0]]){
        pass.insert(x);
        temp.insert(x);
    }
    for(auto x:temp){
        for(auto y:BTSmap[x]){
            pass.insert(y);
        }
    }
    pass.insert(input[0]);
    for(auto x:pass){
        cout<<x<<endl;
    }
    return 0;
}