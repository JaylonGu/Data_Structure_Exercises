#include <iostream>
#include "bintree.h"
#include "bstree.h"
using namespace std;

template<class Elem>
class AVLTree : public BSTree<Elem>{
protected:
    int height(BinNode<Elem> *r){
        if(!r) return -1;
        return r->h;
    }

    BinNode<Elem>* LLrotate(BinNode<Elem>* r){
        BinNode<Elem>* child;
        child=r->left;
        r->left=child->right;
        child->right=r;
        r->h=max(height(r->left),height(r->right))+1;
        child->h=max(height(child->left),height(child->right))+1;
        return child;
    }

    BinNode<Elem>* RRrotate(BinNode<Elem>* r){
        BinNode<Elem>* child;
        child=r->right;
        r->right=child->left;
        child->left=r;
        r->h=max(height(r->left),height(r->right))+1;
        child->h=max(height(child->left),height(child->right))+1;
        return child;
    }

    BinNode<Elem>* LRrotate(BinNode<Elem>* r){
        r->left=RRrotate(r->left);
        return LLrotate(r);
    }

    BinNode<Elem>* RLrotate(BinNode<Elem>* r){
        r->right=LLrotate(r->right);
        return RRrotate(r);
    }

    BinNode<Elem>* rinsert(Elem x, BinNode<Elem>* r){
        if(r==NULL){
            r=new BinNode<Elem>(x);
            if(!r) throw -1;
        }else if(x<r->data){
            r->left=rinsert(x,r->left);
            if(height(r->left)-height(r->right)==2){
                if(x < r->left->data)
                    r=LLrotate(r);
                else
                    r=LRrotate(r);
            }
        }else if(x>r->data){
            r->right=rinsert(x,r->right);
            if(height(r->right)-height(r->left)==2){
                if(x>r->right->data)
                    r=RRrotate(r);
                else
                    r=RLrotate(r);
            }
        }else throw -2;
        r->h = max(height(r->left), height(r->right))+1;
        return r;
    }
public:
    AVLTree(){
        this->root=NULL;
    }
    
};

int main(){

    return 0;
}