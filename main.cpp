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

void bfsTraverse(struct Node *p){
    if(p==NULL){
        return;
    }
    struct Node *t;
    queue<Node *> list;

    list.push(p);

    while (!list.empty()){
        t=list.front();
        list.pop();
        cout<<t->data<<" ";
        if(t->leftChild!=NULL)
        {
            list.push(t->leftChild);
        }
        if(t->rightChild!=NULL){
            list.push(t->rightChild);
        }

    }

}
int  height(struct Node *p){
    if(p==NULL)return 0;
    int x,y=0;
    struct Node *q=p;
    while(p!=NULL){
        x++;
        p=p->leftChild;
    }
    while(q!=NULL){
        y++;
        q=q->rightChild;
    }
   // cout<<x<<" "<<y<<" ";
    return x>y?x:y;

}
struct Node *Inpre(struct Node *p){
    while (p&&p->rightChild!=NULL){
        p=p->rightChild;
    }
    return p;
}
struct Node *Insucc(struct Node *p){
    while (p&&p->leftChild!=NULL){
        p=p->leftChild;
    }
    return p;
}
struct Node * Delete(struct Node *p,int key){
    struct Node *q;

    if(p==NULL){
        return NULL;
    }
    if(p->rightChild==NULL&&p->leftChild==NULL){

        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }

    if(p->data<key){
        p->rightChild=Delete(p->rightChild,key);
    }
    if(p->data>key){
       p->leftChild= Delete(p->leftChild,key);
    }

    else{
        if(height(p->leftChild)>height(p->rightChild)){
            q=Inpre(p->leftChild);
            p->data=q->data;
            p->leftChild=Delete(p->leftChild,q->data);
        } else{
            q=Insucc(p->rightChild);
            p->data=q->data;
            p->rightChild=Delete(p->rightChild,q->data);
        }

    }

    return p;
}

int main(){
    struct Node * temp;

    Insert(10);

    Insert(5);
    Insert(20);

    Insert(3);
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
    cout<<endl;
    bfsTraverse(root);
   // cout<<endl<<" "<<height(root);
    cout<<endl;

    Delete(root,5);
    bfsTraverse(root);

    return 0;
}