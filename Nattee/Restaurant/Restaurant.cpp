#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

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

class Compare{
    public:
    bool operator()(pair<int,int>p1,pair<int,int>p2){
        return p1.first > p2.first;
    }
};

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> t = input_split<int>();
    priority_queue<pair<int,int>,vector<pair<int,int> >,Compare> order;
    for(int i = 0; i < n; i++){
        order.push(make_pair(t[i],i));
    }
    for(int i = 0; i < m; i++){
        if(i < n){
            printf("%d\n",0);
        }
        else {
            printf("%d\n",order.top().first);
            pair<int,int> temp_pair = order.top();
            order.pop();
            temp_pair.first += t[temp_pair.second];
            order.push(temp_pair);
        }
    }
    return 0;
}