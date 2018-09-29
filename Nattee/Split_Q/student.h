#ifndef _CP_STUDENT_QUEUE_INCLUDED_
#define _CP_STUDENT_QUEUE_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once
#include <vector>
#include <queue>
#include "queue.h"

template <typename T>
std::vector< CP::queue<T> > CP::queue<T>::split_queue(int k) {
    std::vector<CP::queue<T> > qs(k);
    while(!this->empty()){
        for(int i = 0; i < k; i++){
            qs[i].push(this->front());
            this->pop();
            if(this->empty()) break;
        }
    }
    return qs;
}

#endif