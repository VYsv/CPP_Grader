#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  CP::list<T> result;
  if(it != end() && pos >= 0 && pos <= mSize){
    while(it != end() && mSize != 0){
      mSize--;
      result.push_back(*it);
      it++;
    }
    list_iterator lit = list_iterator(mHeader);
    if(pos > 0){
      for(size_t i = 0; i < mSize; i++){
      lit.ptr = lit.ptr->next;
      }
    }
    lit.ptr->next = mHeader;
    mHeader->prev = lit.ptr;
    }
  return result;
}

#endif