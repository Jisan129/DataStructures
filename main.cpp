#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *leftChild;
    struct Node *rightChild;

}*root=NULL;

void Insert(int key){
    struct Node *t=root;
    struct Node *r=NULL,*p;

    if(root==NULL){
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=key;
        p->leftChild=p->rightChild=NULL;
        root=p;
        return;
    }

    while (t!=NULL){
        r=t;
        if(t->data<key){
            t=t->rightChild;
        } else{
            t=t->leftChild;
        }

    }
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->leftChild=p->rightChild=NULL;

    if(key>r->data){
        r->rightChild=p;
    } else{
        r->leftChild=p;
    }

}
void Inorder(struct Node *p){
    if(p==NULL)return;
    Inorder(p->leftChild);
    cout<<p->data << " ";
    Inorder(p->rightChild);

}
struct Node * search(int key){
    struct Node *p=root;
    while (p!=NULL){
       if (p->data==key){
            return p;
        }
        else if(p->data<key){
            p=p->rightChild;
        } else if(p->data>key){
            p=p->leftChild;
        }
    }
    return NULL;

}

struct Node *Max (){
    struct Node *p=root;
    while (p->rightChild!=NULL){
        p=p->rightChild;
    }
    return p;

}

struct Node *Min(){
    struct Node *p=root;
    while (p->leftChild!=NULL){
        p=p->leftChild;
    }
    return p;
}

int main(){
    struct Node * temp;

    Insert(10);
    Insert(2);
    Insert(5);
    Insert(20);
    Insert(1);

    Inorder(root);
    cout<<endl;

    temp=search(5);
    if(temp!=NULL){
        cout<<"Key found : "<<temp->data;
    } else{
        cout<<"No key found";
    }

    temp=Max();
    cout<<endl<<"Max is : "<<temp->data;



    temp=Min();
    cout<<endl<<"Min is : "<<temp->data;



    return 0;
}