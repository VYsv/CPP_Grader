#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
    if(mSize == 0){
      return;
    } else {
      bool check = true;
      while(check){
        check = false;
        list_iterator it = list_iterator(mHeader->next);
        while(it.ptr != mHeader){
          if(it.ptr->data == value){
            it.ptr->prev->next = it.ptr->next;
            it.ptr->next->prev = it.ptr->prev;
            delete it.ptr;
            check = true;
            mSize--;
          }
          it.ptr = it.ptr->next;
        }
      }
    }
}

#endif