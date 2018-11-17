#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <set>

template <typename T>
void CP::vector<T>::uniq() {
  CP::vector<T> temp;
  std::set<T> pool;
  for(int i = 0; i < size(); i++){
    if(pool.count(mData[i]) == 0){
      pool.insert(mData[i]);
      temp.push_back(mData[i]);
    }
  }
  *this = temp;
}

#endif