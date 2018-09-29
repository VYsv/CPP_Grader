#include <iostream>
#include <sstream>
#include <vector>
#include <map>

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

int main() {
    map<int,int> count;
    vector<int> input;
    input = input_split<int>();
    for(auto x:input){
        if(count.count(x)){
            count[x] = 0;
        } else {
            count[x] = 1;
        }
    }
    for(map<int,int>::iterator it = count.begin(); it != count.end(); it++){
        if(it->second == 1){
            cout<<it->first;
            return 0;
        }
    }
    cout<<"NONE";
    return 0;
}