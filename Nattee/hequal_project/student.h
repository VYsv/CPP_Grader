#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <set>

template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::operator==(const CP::priority_queue<T,Comp> &other) const {
  //write your code here
  std::set<T> tmp;
  size_t count = 0;
  if(mSize == other.mSize) {
    for(int i = 0; i < mSize; i++){
      tmp.insert(mData[i]);
    }
    count = tmp.size();
    for(int i = 0; i < mSize; i++){
      tmp.insert(other.mData[i]);
    }
    if(tmp.size() > count){
      return false;
    }
    if(mData[0] == other.mData[0]) return true;
  }
  return false;
}
#endif