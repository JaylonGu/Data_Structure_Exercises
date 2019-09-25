#include <iostream>
using namespace std;

template <class Elem>
struct BinNode{
    Elem data;
    BinNode<Elem> *left;
    BinNode<Elem> *right;
    BinNode(Elem x){
        data=x;
        left=right=NULL;
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
        rpreprint(root);
        cout<<endl;
    }

    

    void print(){
        rprint(root,0);
    }

};

int main(){
    BinTree bt(11);

    return 0;
}