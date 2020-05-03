#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void createLinkdedlist(int pInt[],int number) {

    struct Node *temp,*last;
    first=(struct Node *)malloc(sizeof(Node));
    first->data=pInt[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<number;i++){
        temp=(struct Node *)malloc(sizeof(Node));
        temp->data=pInt[i];
        temp->next=NULL;

        last->next=temp;
       last=temp;

    }

}

void printList(struct Node *pNode) {
    while (pNode!=NULL){
        cout<<pNode->data<<" ";
        pNode=pNode->next;
    }

}

int sumList(struct Node *p){
    int sum=0;

     while (p!=NULL){
         sum+=p->data;
         p=p->next;
     }
     return sum;
}

int CountElement(struct Node *p){
    int count=0;
    while (p){
        count++;
        p=p->next;
    }
    return count;
}

int maxSearch(struct Node *p){
    int max=INT32_MIN;
    //cout<<max;
    while (p){
        //cout<<p->data;
        if(p->data>max){
            max=p->data;
            p=p->next;
        }
       p=p->next;
    }
    return max;

}
struct Node *lsearch(struct Node *p,int key) {
    while (p!=NULL) {
        if (p->data == key) {
            return p;
        }
        p=p->next;
    }
    return NULL;
}
struct Node *Rsearch(struct Node *p,int key){
    if(p==NULL){
        return NULL;
    }
    else if(p->data==key){
        return p;
    }
    return Rsearch(p->next,key);
}
void insert(struct Node *p,int index,int key){
    struct Node *temp;

    temp =(struct Node *)malloc(sizeof(Node));
    temp->data=key;

    if(index<0 || index > CountElement(p))
        return;

    else if (index==0){

        temp->next=p;
        p=temp;
    } else {
        
    }
}

//linked List
int main() {
    int list[]={1,3,4,50,8,19};

    createLinkdedlist(list,6);

    printList(first);

    cout<<endl<<"The sum is : "<<sumList(first);

    cout<<endl<<"The elements are :"<<CountElement(first);

    cout<<endl<<"The Max element is : "<<maxSearch(first);

    struct Node *c;

    c=lsearch(first,17);
    if(c!=NULL){
        cout<<endl<<"Key found "<<c->data;
    } else{
        cout<<endl<<"No key Found";
    }

    return 0;
}
