#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it,size_t pos) {
  //write your code here
  CP::list<T> result;
  if(pos < mSize) {
      result.mHeader->prev = mHeader->prev;
      mHeader->prev->next = result.mHeader;

      mHeader->prev = it.ptr->prev;
      it.ptr->prev->next = mHeader;

      result.mHeader->next = it.ptr;
      it.ptr->prev = result.mHeader;

      result.mSize = mSize - pos;
      mSize = pos;
    }
  return result;
}

#endif