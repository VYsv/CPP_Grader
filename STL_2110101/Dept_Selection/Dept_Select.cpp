#include <iostream>
#include <sstream>
#include <string>
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

int main(){
    int count;
    map<string,int> dept;
    map<float,vector<string>,greater<float> > select;
    vector<string> input;
    map<string,string> order;
    cin>>count;
    for(int i = 0; i<count; i++){
        input = input_split<string>();
        dept[input[0]] = stoi(input[1]);
        input.clear();
    }
    cin>>count;
    for(int i = 0; i<count; i++){
        input = input_split<string>();
        select[stof(input[1])].push_back(input[0]);
        select[stof(input[1])].push_back(input[2]);
        select[stof(input[1])].push_back(input[3]);
        select[stof(input[1])].push_back(input[4]);
        select[stof(input[1])].push_back(input[5]);
        input.clear();
    }
    for(map<float,vector<string> >::iterator it = select.begin(); it != select.end(); it++){
        for(int i=1; i<5; i++){
            if(dept[it->second[i]] > 0){
                order[it->second[0]] = it->second[i];
                dept[it->second[i]]--;
                break;
            }
        }
    }
    for(auto x:order){
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
} 