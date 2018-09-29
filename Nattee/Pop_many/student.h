#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  //write your code here
  if(K > this->size()) K = this->size();
  while(K != 0){
    this->pop();
    K--;
  }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  //write your code here
  std::stack<T> result,temp;
  if(K > this->size()) K = this->size();
  while(K != 0){
    temp.push(this->top());
    this->pop();
    K--;
  }
  while(!temp.empty()){
    result.push(temp.top());
    temp.pop();
  }
  return result;
  //don't forget to return an std::stack
}

#endif