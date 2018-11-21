#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
    node* nLess = NULL;
    node* nMore = NULL;
    node* p = mRoot;
    node* MAX = find_max_node(mRoot);
    node* MIN = find_min_node(mRoot);
    mRoot = NULL;
    CP::map_bst<KeyT,MappedT,CompareT> result;
    if(val>MAX->data.first){
        mRoot=p;
    }
    else if(val<=MIN->data.first){
        result.mRoot=p;
    }
    else{
        while(p!=NULL){
            int c = compare(p->data.first,val);
            if(c<0){
                child_link(nLess,val)=p;
                p->parent=nLess;
                nLess=p;
                p=p->right;
            }
            else{
                result.child_link(nMore,val)=p;
                p->parent=nMore;
                nMore=p;
                p=p->left;
            }

        }

        nMore->left=NULL;
        nLess->right=NULL;
    }
    //your code here
    return result;
}

#endif