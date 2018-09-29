#include <sstream>
#include <iostream>
#include <string>
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
    int count;
    cin>>count;
    set<string> winner,loser;
    for (count; count > 0; count--){
        vector<string> input;
        input = input_split<string>();
        winner.insert(input[0]);
        loser.insert(input[1]);
    }
    for(auto x:loser) {
        winner.erase(x);
    }
    cout<<"[";
    count = winner.size();
    for(auto y:winner) {
        cout<<"'"<<y<<"'";
        if(count > 1){
            cout<<", ";
            count--;
        }
    }
    cout<<"]\n";
}