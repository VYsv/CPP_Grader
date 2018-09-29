#include <iostream>
#include <map>
using namespace std;
int main(){
    int input = 0;
    int count = 0;
    int check = 0;
    cin>>input;
    map<int,int> num;
    while(input != -1){
        if(num[input] > 0){
            num[input]++;
        } else {
            num[input] = 1;
        }
        count++;
        cin>>input;
    }
    float half = (float)count/2;
    for(map<int,int>::iterator it = num.begin(); it != num.end(); it++){
        if(it->second > half){
            cout<<it->first<<endl;
            check = 1;
        }
    }
    if(!check){
        cout<<"Not found";
    }
    return 0;
}