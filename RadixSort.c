#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
struct node {
    int data;
    struct node *next;
}*head=NULL;
 
struct node *L[10];
 
int getmax(int A[],int n){
    int i=0;
    int max=A[i];
    for(int i=1;i<n;i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    
    return max;
}
 
int count(int x){
    int cnt=0;
    while(x>0){
        cnt++;
        x=x/10;
    }
    return cnt;
}
 
int power(int x,int y){
    int pow=1;
    for (int i = 0; i < y; i++) {
        pow = pow * x;
    }
    return pow;   
}
 
void insert(struct node *ptr,int data){
    struct node *temp=ptr;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    
    
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
}
 
void RadixSort(int A[],int n,int cnt,int place){
    for(int i=0;i<n;i++){
        int x,y;
        y=A[i]/place;
        x=y%10;
            
        if(L[x]==0){
            L[x]=(struct node *)malloc(sizeof(struct node));
            L[x]->data=A[i];
            L[x]->next=NULL;
        }
        else{
            insert(L[x],A[i]);
        }
    }
    
    int k=0;    
    for(int i=0;i<n;i++){
        struct node *ptr=L[i];
        while(ptr!=NULL){
            A[k++]=ptr->data;
            ptr=ptr->next;
            free(L[i]);  
            L[i]=ptr;  
        }
        
    } 
}
 
void Display(int A[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
    
 
int main(){
    int A[]={5,10,250,35,61,68,13,161,423,27,89,64,106};
   
    int n=sizeof(A)/sizeof(int);
     Display(A,n);
    int max,cnt;
    max=getmax(A,n);
    cnt=count(max);
    
    for(int j=0;j<cnt;j++){
        int x=10;
        int place=power(x,j);
        RadixSort(A,n,cnt,place);
    }
    Display(A,n);
    return 0;
}