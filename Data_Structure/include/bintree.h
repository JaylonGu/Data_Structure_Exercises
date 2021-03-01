#ifndef bintree_h
#define bintree_h

#include <iostream>
#include <stack>
using namespace std;

template <class Elem>
struct BinNode{
    Elem data;
    int h;
    BinNode<Elem> *left;
    BinNode<Elem> *right;
    BinNode(Elem x){
        data=x;
        left=right=NULL;
        h=0;
    }
};

template<class Elem>
class BinTree{
protected:
    BinNode<Elem>* root;

    void rpreprint(BinNode<Elem> *r){
        if(!r) return;
        cout<<r->data<<" ";
        rpreprint(r->left);
        rpreprint(r->right);
    }

    void ipreprint(BinNode<Elem> *r){
        stack< BinNode<Elem>* > st;
        while(r){
            cout<<r->data<<" ";
            st.push(r);
            r=r->left;
            while(r==NULL || !st.empty()){
                r=st.top();
                st.pop();
                r=r->right;
            }
        }
    }

    void rinprint(BinNode<Elem> *r){
        if(!r) return;
        rinprint(r->left);
        cout<<r->data<<" ";
        rinprint(r->right);
    }

    void iinprint(BinNode<Elem> *r){
        stack< BinNode<Elem>* > st;
        while(r){
            st.push(r);
            r=r->left;
            while(r==NULL || !st.empty()){
                r=st.top();
                st.pop();
                cout<<r->data<<" ";
                r=r->right;
            }
        }
    }

    BinNode<Elem>* rfindX(Elem x, BinNode<Elem> *r){
        if(!r) return NULL;
        if(r->data==x) return r;
        BinNode<Elem> *found;
        found=rfoundX(x,r->left);
        return found ? found : rfindX(x,r->right);
    }

    void rprint(BinNode<Elem> *r, int depth){
        for(int i=0;i<depth;i++) cout<<"  ";
        if(!r) {
            cout<<"[/]"<<endl;
        }else{
            cout<<r->data<<endl;
            rprint(r->left,depth+1);
            rprint(r->right,depth+1);
        }
    }

public:
    BinTree(){
        root=NULL;
    }
    BinTree(Elem r){
        root=new BinNode<Elem>(r);
    }
    ~BinTree(){
        delete root;
    }

    BinNode<Elem>* findX(Elem x){
        return rfindX(x,root);
    }

    bool insert(Elem p, int LorR,Elem x){
        BinNode<Elem> *found;
        found=findX(p);
        if(!found) return false;
        if(LorR==0){
            if(found->left) return false;
            found->left=new BinNode<Elem>(x);
        }else{
            if(found->right) return false;
            found->right=new BinNode<Elem>(x);
        }
        return true;
    }

    void preprint(){
        // rpreprint(root);
        ipreprint(root);
        cout<<endl;
    }



    void inprint(){
        rinprint(root);
        cout<<endl;
    }

    void print(){
        rprint(root,0);
    }

};

#endif