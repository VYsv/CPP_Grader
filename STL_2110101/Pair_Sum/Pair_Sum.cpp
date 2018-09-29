#include <iostream>
#include <sstream>
#include <vector>

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
    vector<int> input;
    input = input_split<int>();
    int count = 0;
    int total = 0;
    cin>>total;
    for(int i = 0; i < input.size(); i++){
        for(int j = i+1; j < input.size(); j++){
            if(input[i]+input[j] == total){
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}