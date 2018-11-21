#ifndef __STUDENT_H_
#define __STUDENT_H_

void shift(int k) {
	// TODO: Add your code here
	bool left = true;
	if(k < 0) {
		k = -k;
		left = false;
	}
	int cycle = k % mSize;
	
	list_iterator it = list_iterator(mHeader->next);
	
	mHeader->next->prev = mHeader->prev;
	mHeader->prev->next = mHeader->next;

	for(int i = 0; i < cycle; i++){
		if(left){
			it.ptr = it.ptr->next;
		} else{
			it.ptr = it.ptr->prev;
		}
	}

	mHeader->next = it.ptr;
	mHeader->prev = it.ptr->prev;
	it.ptr->prev->next = mHeader;
	it.ptr->prev = mHeader;
}
#endif