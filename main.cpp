//implementing Stack using linked list
//create,push,pop,peak,empty,full,print

#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}*top = NULL;

void Push(int element){
    struct Node *q;
    q=(struct Node * )malloc(sizeof(struct Node));
    if(q==NULL){
        cout<<"Stack is Empty";
    } else{
        //q=(struct Node *)malloc()
        q->data=element;
        q->next=top;
        top=q;
    }
}

int pop(){
    struct Node *q;
    q=top;
    top=top->next;
    int x=q->data;
    //q=q->next;

    free(q);
    return x;
}

void Display(){
    struct Node *q;
    q=(struct Node *)malloc(sizeof(struct Node));
    q=top;
    while (q!=NULL){
        cout<<q->data<<" ";
        q=q->next;
    }
    cout<<endl;
}

int main(){
    Push(10);
    Push(20);
    Push(30);
    Display();
    pop();
    Display();
}