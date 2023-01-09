#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 99999
int n=5;
int k=3;

struct node{
    int val;
    int arrno;
};
void heapify(struct node *heap,int p){
    int left=2*p;
    int right=2*p +1;
    int small=p;
    if(left<k && heap[p].val>heap[left].val)
        small=left;
    if(right<k && heap[small].val>heap[right].val){
        small=right;
    }
    if(small !=p){
       struct node temp=heap[p];
       heap[p]=heap[small];
       heap[small]=temp;
       heapify(heap,small);
    }
}
void merge_k(int arr[k][n]){
    struct node *heap=(struct node*)calloc(k,sizeof(struct node));
    int *arrpos=(int *)calloc(k,sizeof(int));
    int result[k*n];

    for(int i=0;i<k;i++){
        heap[i].val=arr[i][0];
        heap[i].arrno=i;
        arrpos[i]=1;
    }
    for(int i=k-1;i>=0;i--){
        heapify(heap,i);
    }
    int pos;
    int q=0;
    while(heap[0].val != INT_MAX){
        result[q]=heap[0].val;
        int r=heap[0].arrno;
        q++;
        pos=arrpos[heap[0].arrno];
        if(pos>=n){
            heap[0].val=INT_MAX;
            heap[0].arrno=r;
        }
        else{
            heap[0].val=arr[r][pos];
            heap[0].arrno=r;
        }
        heapify(heap,0);
        arrpos[r]++;


    }
    for(int i=0;i<k*n;i++){
        printf("%d ",result[i]);
    }
}
int main(){
    int arr[3][5]={{0,1,4,6,7},{2,8,12,13,105},{0,3,6,9,14}};
    merge_k(arr);

    return 0;
}
