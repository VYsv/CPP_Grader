#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int,float> subject;
    map<int,int> subject_count;
    map<string,float> teacher_score;
    map<string,float> teacher_count;
    for(int i = 0; i < n; i++){
        int id,score;
        string teacher;
        cin >> id >> teacher >> score;
        if(!subject.count(id)) {
            subject[id] = score;
            subject_count[id] = 1;
        }
        else{
            subject[id] += score;
            subject_count[id]++;
        }
        if(!teacher_score.count(teacher)){
            teacher_score[teacher] = score;
            teacher_count[teacher] = 1;
        }
        else{
            teacher_score[teacher] += score;
            teacher_count[teacher]++;
        }
    }
    for(auto x:subject){
        cout << x.first << " ";
        printf("%.2f",x.second/subject_count[x.first]); 
        cout << endl;
    }
    for(auto y:teacher_score){
        cout << y.first << " ";
        printf("%.2f",y.second/teacher_count[y.first]);
        cout << endl;
    }
    return 0;
}