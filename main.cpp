#include <bits/stdc++.h>


using namespace std;
struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
}
        *root = NULL;

void CreateTree(int key) {
    struct Node *p;
    p = (struct Node *) malloc(sizeof(struct Node));
    p->data = key;
    p->rchild = p->lchild = NULL;

    root = p;

}

int Height(struct Node *item) {
    struct Node *temp = NULL;
    temp = item;
    int i = 0, j = 0;
    if (item == NULL) {
        return -1;
    }

    while (temp) {
        temp = temp->lchild;
        i++;

    }
    temp = item;
    while (temp) {
        temp = temp->rchild;
        j++;

    }
    return i > j ? i - 1 : j - 1;
}


void InsertNode(int element) {

    struct Node *temp, *p = root, *r = NULL;
    while (p != NULL) {
        r = p;
        if (element > p->data)p = p->rchild;
        else if (element < p->data)p = p->lchild;
    }
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = element;
    temp->lchild = temp->rchild = NULL;

    if (element < r->data)r->lchild = temp;
    else r->rchild = temp;
}

void InOrder(Node *temp) {


    if (temp) {
        InOrder(temp->lchild);
        cout << temp->data << " ";
        InOrder(temp->rchild);
    }

}


struct Node *Search(int i) {

    struct Node *temp = root;
    while (temp) {
        if (temp->data == i) {
            cout << endl << i << " has found";
            return temp;
        } else if (i > temp->data) {
            temp = temp->rchild;

        } else {
            temp = temp->lchild;
        }
    }
    return NULL;
}

struct Node *InSuccessor(struct Node *element) {

    while (element && element->lchild != NULL) {
        element = element->rchild;
    }
    return element;


}

struct Node *InPredecessor(struct Node *p) {

    while (p&&p->rchild!=NULL)p=p->rchild;
    return p;
}

struct Node *Delete(struct Node *node, int element) {
    struct Node *p=node,*q=NULL;

    if(p==NULL) {
        root=NULL;
        return NULL;
    }
    else if(p->lchild==NULL&&p->rchild==NULL){
        if(p==root)root=NULL;
        free(p);
        return NULL;
    }

    if(element<p->data){
        p->lchild=Delete(p->lchild,element);
    }
    else if(element>p->data){
        p->rchild=Delete(p->rchild,element);
    } else{
        if(Height(p->lchild)>Height(p->rchild)){
            q=InPredecessor(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        } else{
            q=InSuccessor(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);

        }
    }
    return p;

}

int main() {

    int key;

    CreateTree(3);


    InsertNode(2);
    InsertNode(4);
    InsertNode(1);
    InsertNode(5);

    InOrder(root);

    Search(10);
    cout << endl;

    cout << Height(root);
    Delete(root, 2);//some problem while giving element 2

    cout <<endl;
    InOrder(root);

    return 0;
}




