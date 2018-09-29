#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

void all_values(int size,string str,vector<pair<int,int> > &fruits,int& min){
    int product = 1,sum = 0;
    int diff;
    int check = 0;
    if(size > 0){
        all_values(size-1,str+"0",fruits,min);
        all_values(size-1,str+"1",fruits,min);
    }else{
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '1'){
                product *= fruits[i].first;
                sum += fruits[i].second;
                check++;
            }
        }
        if(check != 0){
            diff = abs(product - sum);
            if(diff < min){
                min = diff;
            }
        }
    }
}
int main(){
    int num = 0;
    int sour,bit;
    int min;
    vector<pair<int,int> > fruits;
    cin>>num;
    for(int i = 0; i < num; i++){
        cin>>sour>>bit;
        fruits.push_back(make_pair(sour,bit));
    }
    min = abs(fruits[0].first - fruits[0].second);
    all_values(num,"",fruits,min);
    cout<<min;
}