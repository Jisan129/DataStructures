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

    if(element<r->data)r->lchild=temp;
    else r->rchild=temp;
}

void InOrder(Node *temp) {


    if(temp){
        InOrder(temp->lchild);
        cout << temp->data<<" ";
        InOrder(temp->rchild);
    }

}

int main() {

    int key;

    CreateTree(1);

    for (int i = 2; i <= 5; i++) {
        InsertNode(i);
    }

    InOrder(root);


    return 0;
}