void replace(const T& x, list<T>& y) {
  CP::list<T> temp;
  for(auto it = begin(); it != end(); it++){
    if(*it == x){
      for(auto data:y) temp.push_back(data);
    }
    else temp.push_back(*it);
  }
  *this = temp;
}
