#include <stdio.h>
#define maxSize 5
int queue[maxSize];
int frnt=-1;
int rear=-1;
int isFull(){
    if((frnt==rear+1)||(frnt==0&&rear+1==maxSize))
        return 1;
    return 0;
}
int isNull(){
    if(frnt==-1&&rear==-1)
        return 1;
    return 0;
}
void display(){
    int i;
    printf("\nQueue\n");
    for(i=frnt;i!=rear;i=(i+1)%maxSize)
        printf("%d\n",queue[i]);
    printf("%d\n",queue[i]);
}
void enQueue(int item){
    if(isFull())
        printf("Queue is Overflow");
    else{
        if(frnt==-1)
            frnt++;
        rear=(rear+1)%maxSize;
        queue[rear]=item;
       display();
    }
}
void deQueue(){
    if(isNull())
        printf("Queue is Underflow");
    else{
        if(frnt==rear){
             rear=-1;
             frnt=-1;
        }
        else
            frnt=(frnt+1)%maxSize;
        display();
    }
}
void main(){
    int item,dis;
    printf("\tQueue Menu\n");
    printf("1-Enqueue\n2-deQueue\n3-Exit");
    do{
        printf("\nEnter\t");
        scanf("%d",&dis);
        switch (dis){
        case 1:printf("Enter item\t");
                scanf("%d",&item);
                enQueue(item);
            break;
        case 2:deQueue();
                break;
        case 3:break;
        default:printf("Wrong input!!");
                printf("\tQueue Menu\n");
                printf("1-Enqueue\n2-deQueue\n3-Exit");
            break;
        }
    }while(dis!=3);
}