#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int num,max;
    cin >> num;
    map<string,int> count;
    for(int i = 0; i < num; i++){
        string name;
        cin >> name;
        if(count.find(name) == count.end()){
            count[name] = 1;
        }
        else count[name]++;
        if(count[name] > max) max = count[name];
    }
    string name;
    for(map<string,int>::iterator x = count.begin(); x != count.end(); x++){
        if(x->second == max){
            name = x->first;
        }
    }
    cout << name << " " << max << endl;
}