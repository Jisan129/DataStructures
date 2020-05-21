//implementing Stack

#include <bits/stdc++.h>
using namespace std;
struct Stack {
    int size;
    int top;
    int *array;
};
void Create(struct Stack *q ){
     cout<<"Print size:";
     cin>>q->size;
     q->top=-1;
     q->array=(int *)malloc(q->size*sizeof(int ));
}
void PushStack(struct Stack *st,int element){
    if(st->top>=st->size-1){
        cout<<"Stack is Full"<<endl;
    } else {
        st->top++;
        st->array[st->top] = element;
    }

}
void PopStack(struct Stack *st){
    if(st->top==-1){
        cout<<"No elements to delete";
        return;
    }
    int p=st->array[st->top--];
    cout<<p<<" is Removed"<<endl;

}
void printStack(struct Stack *st){
    for(int i=st->top;i>=0;i--){
    cout<<st->array[i]<<" ";}
}
void Is_empty(struct Stack *q){
    if(q->top==-1){
        cout<<"Stack is Empty";
    }
    else{
        cout<<"this is not empty";
    }
}
int peek(struct Stack *st){
    return st->array[st->top];
}
int main(){

    struct Stack q;
    Create( &q);
    PushStack(&q,4);
    PushStack(&q,5);
    PushStack(&q,6);
    PushStack(&q,7);
    PushStack(&q,8);
    cout<< " The peek is "<<peek(&q);
    printStack(&q);
    PopStack(&q);
    printStack(&q);

    cout<< " The peek is "<<peek(&q);


}