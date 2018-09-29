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

int main() {
    int count;
    vector<string> input;
    vector<vector<string> > dataStore;
    set<string> name; 
    map<string,vector<string> > name_data;   
    cin>>count;
    for(count; count > 0; count--){
        input = input_split<string>();
        name_data[input[0]] = input;
        input.push_back("0");
        dataStore.push_back(input);
    }
    input = input_split<string>();
    for(map<string,vector<string> >::iterator it = name_data.begin(); it != name_data.end(); it++){
        int input_count = 0;
        for(auto x:input){
            for(int i = 1; i < 4; i++){
                if(it->second[i] == x){
                    input_count++;
                    break;
                }
            }
        }
        if(input_count == input.size()){
            name.insert(it->first);
        }
    }
    if(name.size() == 0){
        cout<<"Not Found";
        return 0;
    }
    for(auto x:name){
        for(auto y:name_data[x]){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}