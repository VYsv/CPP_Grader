#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    map<string,int> words;
    vector<string> temp; 
    string str;
    int numbers = 0;
    cin>>numbers;
    for(int i = 0; i < numbers; i++){
        cin>>str;
        temp.push_back(str);
    }
    for(auto x:temp){
        if(words[x] >= 1){
            words[x]++;
        }else{
            words[x] = 1;
        }
    }
    for(auto x:words){
        if(x.second > 1){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    return 0;
}