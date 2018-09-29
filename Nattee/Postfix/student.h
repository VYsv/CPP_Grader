#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <vector>

using namespace std;

int eval_postfix(vector<pair<int,int> > v) {
  vector<int> num;
  for(int i = 0; i < v.size(); i++){
    if(v[i].first == 1) {
      num.push_back(v[i].second);
    } else if(v[i].first == 0) {
      int oper2 = num.back();
      num.pop_back();
      int oper1 = num.back();
      num.pop_back();
      if(v[i].second == 0) num.push_back(oper1 + oper2);
      if(v[i].second == 1) num.push_back(oper1 - oper2);
      if(v[i].second == 2) num.push_back(oper1 * oper2);
      if(v[i].second == 3) num.push_back(oper1 / oper2);
    }
  }
  return num.back();
}

#endif