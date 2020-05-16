//implementing Circular queue

#include <bits/stdc++.h>
using namespace std;
int size=6;

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Queue *q,int x){
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int *)malloc(q->size*sizeof(int));

}
void enque( struct Queue *q,int x){

    if((q->rear+1)%q->size==q->front){
        cout<<"The Queue is Full"<<endl;
    } else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
int Deque(struct Queue *q){
    int x=-1;
    if(q->rear==q->front){
        cout<<"The Queue is empty";
    } else{
         q->front=(q->front+1)%q->size;
         x=q->Q[q->front];
    }
    //cout<<endl;
    return x;
}

void printQueue(struct Queue *q){
    for(int i=q->front+1;i!=(q->rear+1)%q->size;i=(i+1)%q->size){
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
    enque(&q,40);
    enque(&q,50);
    enque(&q,100);
    printQueue(&q);

    cout<<Deque(&q)<<endl;

    printQueue(&q);

}