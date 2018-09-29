#include <iostream>
#include <sstream>
#include <vector>
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

int main() {
    set<int> data;
    set<int> check;
    vector<int> input;
    input = input_split<int>();
    data.insert(input.begin(),input.end());
    int count = 0;
    int total = 0;
    cin>>total;
    for(auto x:data){
        int find = total - x;
        if(data.count(find) && !check.count(total-x) && x != find){
            count++;
            check.insert(x);
        }
    }
    cout<<count<<endl;
    return 0;
}