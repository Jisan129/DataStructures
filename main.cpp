//implementing queue

#include <bits/stdc++.h>
using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));

}
void enque(  struct Queue *q,int x){

    if(q->rear==q->size-1){
        cout<<"The Queue is Full"<<endl;
    } else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int Deque(struct Queue *q){
    int x=-1;
    if(q->rear==q->front){
        cout<<"The Queue is empty";
    } else{
         q->front++;
         x=q->Q[q->front];
    }
    //cout<<endl;
    return x;
}

void printQueue(struct Queue *q){
    for(int i=q->front+1;i<=q->rear;i++){
        cout<<q->Q[i]<<" ";
    }
    cout<<endl;
}
int main(){
    struct Queue q;
    Create(&q,5);
    enque(&q,10);
    enque(&q,20);
    enque(&q,30);
    printQueue(&q);

    cout<<Deque(&q)<<endl;

    printQueue(&q);

}