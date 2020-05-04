#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//Implementing linked List
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
    while (p != NULL) {
        if (p->data == key) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
void insert(struct Node *p,int index,int key){
    struct Node *temp;


    if(index<0 || index > CountElement(p))
        return;
    temp =(struct Node *)malloc(sizeof(Node));
    temp->data=key;

    if (index==0){

        temp->next=first;
        first=temp;
    } else{
        for(int i=0;i<index-1;i++){
            p=p->next;
            temp->next=p->next;
            p->next=temp;
        }
    }
}
void InsertSortedList(struct Node *p,int key){
    struct Node *temp,*q=NULL;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=key;
    temp->next=NULL;
    if(first==NULL){
        first=temp;
    } else {
        while (p && p->data < key) {
            q = p;
            p = p->next;
        }
        if (p == first) {
            temp->next = first;
            first = temp;

        } else{
            temp->next=q->next;
            q->next=temp;
        }
    }

}
int Delete(struct Node *p,int index ){
    struct Node *q;
    int x=-1,i;
    if(index<1 || index>CountElement(p)){
        return -1;
    }
    if(index==1){
        x=first->data;
        q=first;
       first=first->next;
       free(q);
       return x;

    }
    else{
        for(i=0;i<index-1;i++){
            q=p;

            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}
void RemoveDuplicate(struct Node *p){
    struct Node *q=p->next;
    while (q){
        if(q->data!=p->data){
            p=q;
            q=q->next;
        } else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}
void ReverseLinkedList(struct Node *p){
    struct Node *q;
    q=(struct Node *)malloc(sizeof(Node));
    int i=0,array[100];
    q=p;
    while (q){
       array[i]=q->data;
       i++;
       q=q->next;
    }
    q=p;
    i--;
    while(q){
        q->data=array[i];
        q=q->next;
        i--;
    }

}

int main() {
    int list[]={1,3,5,6,7,19};
    struct Node *c;
    createLinkdedlist(list,6);

    printList(first);

    cout<<endl<<"The sum is : "<<sumList(first);

    cout<<endl<<"The elements are :"<<CountElement(first);

    //cout<<endl<<"The Max element is : "<<maxSearch(first);



    c=lsearch(first,17);
    if(c!=NULL){
        cout<<endl<<"Key found "<<c->data;
    } else{
        cout<<endl<<"No key Found"<<endl;
    }
   // insert(first,2,7);
   // printList(first);
   cout<<endl;
    //InsertSortedList(first,5);
    printList(first);
    //cout<<endl<<"The value which is deleted "<<Delete(first,3)<<endl;
    //printList(first);

    RemoveDuplicate(first);
    cout<<endl;
    printList(first);
    cout<<endl;
    ReverseLinkedList(first);
    printList(first);


    return 0;
}
