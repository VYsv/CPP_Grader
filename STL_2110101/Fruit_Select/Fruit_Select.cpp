#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

template <class T>
vector<T> input_split(string line) {
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
    int countFruit = 0;
    string filename;
    cin>>filename;
    string bestFruit;
    int max = 0;
    vector<string> input;
    vector<string> order;
    map<string,vector<string> > select;
    fstream data(filename);
    for(string line ;getline(data,line); ){
        input = input_split<string>(line);
        if(!select.count(input[0])){
            countFruit++;
        }
        select[input[0]].push_back(input[1]);
        if(!(find(order.begin(), order.end(), input[0]) != order.end())){
            order.push_back(input[0]);
        }
    }
    cout<<"[";
    for(auto x:order){
        if(select[x].size() > max){
            max = select[x].size();
            bestFruit = x;
        }
        cout<<"['"<<x<<"', ";
        cout<<"[";
        int count = select[x].size();
        for(auto y:select[x]){
            cout<<"'"<<y<<"'";
            count--;
            if(count > 0){
                cout<<", ";
            }
        }
        cout<<"]]";
        countFruit--;
        if(countFruit != 0){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
    cout<<"The most favorite fruit is "<<bestFruit<<endl;
}