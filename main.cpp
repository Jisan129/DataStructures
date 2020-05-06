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
void addFirst(struct Node *p,int key){
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(Node));
    temp->data=key;
    temp->previous=NULL;
    temp->next=first;
    first->previous=temp;
    first=temp;

}
void addLast(struct Node *p,int key){
    while(p->next){
        p=p->next;
    }
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node ));
    temp->previous=p;
    temp->next=NULL;
    temp->data=key;
    p->next=temp;

}

void InsertAfter(struct Node *p,int index,int key){
    struct Node *temp;
    if(index<0||index>length(p)){
        return;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;}
            temp=(struct Node *)malloc(sizeof(struct Node ));
            temp->data=key;
            temp->next=p->next;
            temp->previous=p;

                p->next = temp;

    }
}

void InsertBefore(struct Node *p,int index,int key){
    struct Node *temp;
    for(int i=0;i<index-2;i++){
        p=p->next;}
    temp=(struct Node *)malloc(sizeof(struct Node ));
    temp->data=key;
    temp->next=p->next;
    temp->previous=p;

    p->next = temp;


}


int  Search(struct Node *p,int key){

 for(int i=0;i<length(p);i++){
     if (p->data==key){
         return i;
     }
     p=p->next;
 }
    return -1;
}
int Delete(struct Node *p,int index){
    struct Node *temp;
    int x;
    if(index==1){

        first=first->next;
        if(first)first->previous=NULL;
        x=p->data;
        free(p);
        return x;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        p->next->previous=p->previous;
        p->previous->next=p->next;
        x=p->data;
        free(p);
        return x;
    }

}

void sort(struct Node *p){
    int c=length(p),number[c];
    for(int i=0;i<c;i++){
        number[i]=p->data;
        p=p->next;
    }
    p=first;

    sort(number,number+c);
    for(int i=0;i<c;i++){
        p->data=number[i];
        p=p->next;
    }
}

int main() {

    int ara[5]={1,2,3,4,5};

    create(ara,5);
    Display(first);

    cout<<"The length is : "<<length(first)<<endl;
    InsertAfter(first,3,13);
    Display(first);
    InsertBefore(first,3,78);
    Display(first);
    addLast(first,39);
    Display(first);

    cout<<"Index is : "<<Search(first,17);
    cout<<endl;
    Delete(first,1);
    Display(first);

    sort(first);
    Display(first);

    return 0;
}
