#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//Implementing linked List
struct Node{
    int data;
    struct Node *next;
    struct Node *previous;
}*first=NULL;


void create(int ara[],int element){
    struct Node *temp,*last;

        first=(struct Node *)malloc(sizeof(struct Node));
        first->data=ara[0];
        first->next=first->previous=NULL;
        last=first;

        for(int i=1;i<element;i++){
            temp=(struct Node *)malloc(sizeof(struct Node));
            temp->data=ara[i];
            temp->next=last->next;
            temp->previous=last;
            last->next=temp; //previous next is current
            last=temp;
        }

}

void Display(struct Node *p) {

    while (p) {
        cout << p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int length(struct Node *p){
    int sum=0;

    while (p){
        p=p->next;
        sum++;
    }
    return sum;
}

void Insert(struct Node *p,int index,int key){
    struct Node *temp;
    if(index<0||index>length(p)){
        return;
    }
    if(index==0){
        temp=(struct Node *)malloc(sizeof(Node));
        temp->data=key;
        temp->previous=NULL;
        temp->next=first;
        first->previous=temp;
        first=temp;
    } else{
        for(int i=0;i<index-1;i++){
            p=p->next;}
            temp=(struct Node *)malloc(sizeof(struct Node ));
            temp->data=key;
            temp->next=p->next;
            temp->previous=p;

            p->next=temp;

    }
}

int main() {

    int ara[5]={1,2,3,4,5};

    create(ara,5);
    Display(first);

    cout<<"The length is : "<<length(first)<<endl;
    Insert(first,3,11);
    Display(first);



    return 0;
}
