#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
    if(mSize == 0){
      return;
    } else {
      node *ptr = mHeader->next;
      for(int i = 0; i < mSize; i++){
        std::cout << "Hi ";
        std::cout << ptr->data << " ";
        if(ptr->data == value){
          std::cout << "3 ";
          if(ptr->next == NULL){
            std::cout << "4 ";
            ptr->prev = NULL;
          } else {
            std::cout << "5 ";
            ptr->prev = ptr->next;
          }
          mSize--;
        }
        ptr = ptr->next;
      }
    }
}

#endif
