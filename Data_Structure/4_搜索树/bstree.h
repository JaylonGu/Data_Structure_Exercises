#ifndef bstree_h
#define bstree_h

#include <iostream>
#include "bintree.h"
using namespace std;

template<class Elem>
class BSTree : public BinTree<Elem>{
protected:
    BinNode<Elem>* rfindMax(BinNode<Elem>* r){
        if(r->right==NULL) return r;
        return rfindMax(r->right);  // 尾递归
    }

    virtual BinNode<Elem>* rinsert(Elem x, BinNode<Elem>* r){
        if(r==NULL){
            r=new BinNode<Elem>(x);
            if(!r) throw -1;
        }else if(x<r->data){
            r->left=rinsert(x,r->left);
        }else if(x>r->data){
            r->right=rinsert(x,r->right);
        }else throw -2;
        return r;
    }

    BinNode<Elem>* rremove(Elem x, BinNode<Elem>* r){
        BinNode<Elem>* tmp;
        if(!r) throw -1;
        else if(x<r->data){
            r->left=remove(x,r->left);
        }
        else if(x>r->data){
            r->right=remove(x,r->right);
        }else{
            if(r->left && r->right){
                tmp=rfindMax(r->left);
                r->data=tmp->data;
                r->left=remove(tmp->data,r->left);
            }else{
                tmp=r;
                r=r->left ? r->left : r->right;
                delete tmp;
            }
        }
        return r;
    }


public:
    BSTree(){
        this->root=NULL;
    }

    BinNode<Elem>* findMax(){
        // return rfindMax(this->root);
        if(!this->root) return NULL;
        BinNode<Elem>* max=this->root;
        while(max->right){
            max=max->right;
        }
        return max;
    }

    BinNode<Elem>* findMin(){
        if(!this->root) return NULL;
        BinNode<Elem>* min=this->root;
        while(max->left){
            max=max->left;
        }
        return min;
    }

    BinNode<Elem>* findX(Elem x){
        BinNode<Elem> *tmp=this->root;
        while(tmp && x!=tmp->data){
            if(x<tmp->data) tmp=tmp->left;
            else tmp=tmp->right;
        }
        return tmp;
    }

    bool insert(Elem x){
        try{
            this->root = rinsert(x, this->root);
            return true; 
        }
        catch(int e){
            return false;
        }
    }

    bool remove(Elem x){
        try{
            this->root=rremove(x,this->root);
            return true;
        }
        catch(int e){
            return false;
        }
    }

};

#endif