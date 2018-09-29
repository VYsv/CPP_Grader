#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <iterator>

template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  //write your code only here
  if(k > size()) k = size();
  for(int i = 0; i < k;i++){
    res.push_back(mData[i+mFront]);
  }
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  //write your code only here
  this -> mSize = distance(from,to);
  this -> mCap = distance(from,to);
  this -> mFront = 0;
  T *a = new T[mCap];
  int j = 0;
  for(auto i = from;i != to;i++){
    a[j++] = *i;
  }
  this -> mData = a;
}

#endif