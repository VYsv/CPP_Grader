#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
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
    int num;
    string choose;
    cin>>num;
    map<string,int> count;
    vector<vector<string> > data;
    set<string> rec;
    for(int i = 0; i < num; i++){
        vector<string> input;
        input = input_split<string>();
        data.push_back(input);
    }
    cin>>choose;
    int max = 0;
    bool check = false;
    for(auto x:data){
        if(find(x.begin(),x.end(),choose) != x.end()){
            set<string> repeat;
            repeat.clear();
            check = true;
            for(auto y:x){
                if(y != choose && !repeat.count(y)){
                    if(count.count(y)){
                        count[y]++;
                    } else {
                        count[y] = 1;
                    }
                    if(count[y] > max){
                        max = count[y];
                    }
                    repeat.insert(y);
                }
            }
        }
    }
    if(max == 0 && check == true){
        cout<<"No suggested event";
        return 0;
    }
    if(!check){
        cout<<"Not Found";
        return 0;
    }
    for(auto &x:count){
        if(x.second == max){
            rec.insert(x.first);
        }
    }
    for(auto x:rec){
        cout<<x<<endl;
        cout<<max;
        return 0;
    }
}