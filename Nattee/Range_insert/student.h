#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  std::vector<T> temp(position,end());
  std::vector<T> ins(first,last);
  int pos = position - begin();
  int siz = last - first;
  ensureCapacity(mSize+siz);
  for(auto x:ins){
    mData[pos] = x;
    pos++;
  }
  for(auto y:temp){
    mData[pos] = y;
    pos++;
  }
  mSize += siz;
}

#endif