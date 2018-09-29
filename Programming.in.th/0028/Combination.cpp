#include <iostream>
#include <string>

using namespace std;

void bin(int n,string ans){
    if(n==0){
        cout<<ans<<endl;
    }else{
        bin(n-1,ans + "0");
        bin(n-1,ans + "1");
    }
}

int main() {
    bin(3,"");
}