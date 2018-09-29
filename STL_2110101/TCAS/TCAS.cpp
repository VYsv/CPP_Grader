#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
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

int main() {
    vector<string> input;
    map<string,vector<string> > choices;
    map<string,int> max_admitted;
    map<string,vector<string> > sorted_applicants;
    vector<string> unassigned;
    map<string,vector<string> > admitted;
    int num_applicant;
    int num_choice;
    cin >> num_applicant;
    for(int i = 0; i < num_applicant; i++){
        input = input_split<string>();
        for(int j = 1; j < input.size(); j++){
            choices[input[0]].push_back(input[j]);
        }
        unassigned.push_back(input[0]);
    }
    cin >> num_choice;
    for(int i = 0; i < num_choice; i++){
        input = input_split<string>();
        max_admitted[input[0]] = stoi(input[1]);
        for(int j = 2; j < input.size(); j++){
            sorted_applicants[input[0]].push_back(input[j]);
        }
        admitted[input[0]].clear();
    }
    while(unassigned.size() > 0){
        int last = unassigned.size()-1;
        string sid = unassigned[last];
        unassigned.pop_back();
        if(choices[sid].size() > 0){
            string pid = choices[sid][0];
            choices[sid].erase(choices[sid].begin());
            admitted[pid].push_back(sid);
            if(admitted[pid].size() > max_admitted[pid]){
                for(int i = sorted_applicants[pid].size()-1; i >= 0; i--){
                    if(find(admitted[pid].begin(),admitted[pid].end(),sorted_applicants[pid][i]) != admitted[pid].end()){
                        unassigned.push_back(sorted_applicants[pid][i]);
                        admitted[pid].erase(find(admitted[pid].begin(),admitted[pid].end(),sorted_applicants[pid][i]));
                        break;
                    }
                }
            }
        }    
    }
    for(auto &x:admitted){
        sort(x.second.begin(),x.second.end());
        cout<<x.first<<" ";
        for(auto y:x.second){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}