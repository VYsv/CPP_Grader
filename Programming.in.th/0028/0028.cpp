#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<string> team;
    int scoreData[4][4],calculate[4][4];
    int result[4][4] = {0};
    for(int i = 0; i<4; i++){
        string input;
        cin>>input;
        team.push_back(input);
    }
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            cin>>scoreData[i][j];
            result[i][2] += scoreData[i][j];
        }
        result[i][3] = i;
    }
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            calculate[i][j] = scoreData[i][j] - scoreData[j][i];
            if(calculate[i][j] > 0){
                result[i][0] += 3;
            } else if (calculate[i][j] == 0 && i != j){
                result[i][0] += 1;
            }
            result[i][1] += calculate[i][j];
        }
    }
    for(int i = 0; i<4; i++){
        for(int j = i; j<4; j++){
            if(result[i][0] < result[j][0]){
                swap(result[i], result[j]);
            } else if(result[i][0] == result[j][0]){
                if(result[i][1] < result[j][1]){
                    swap(result[i], result[j]);
                } else if(result[i][1] == result[j][1]){
                    if(result[i][2] < result[j][2]){
                        swap(result[i], result[j]);
                    }
                }
            }
        }
    }
    for(int i = 0; i<4; i++){
        cout<<team[result[i][3]]<<" "<<result[i][0]<<endl;
    }
    return 0;
}