#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  auto it = this->begin();
  int i = 0;
  while(i < pos.size()){
    this->erase(it+pos[i]-i);
    i++;
  }
}

#endif