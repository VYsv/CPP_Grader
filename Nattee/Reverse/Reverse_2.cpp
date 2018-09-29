#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int> &v,vector<int>::iterator a,vector<int>::iterator b) {
    vector<int> temp;
    int count = 0;
    for(vector<int>::iterator it = b-1; it >= a; it--){
        temp.push_back(*it);
    }
    for(vector<int>::iterator it = a; it < b; it++){
        *it = temp[count];
        count++;
    }
}
int main() {
    //read input
    int n,a,b;
    cin >> n;
    vector<int> v;
    for (int i = 0;i < n;i++) {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
    //call function
    reverse(v,v.begin()+a,v.begin()+b+1);
    //display content of the vector
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}