
#include <stdio.h>
#include <limits.h>
int input[11]= {30,20,10,40,25,73,16,26,33,50,31};
int it=0;
int output[11];
int ot=-1;
int heapn;
int listn=0;
int ht;
int hl;
int le;
int n=4;
int lt=-1;
int buffer[4];
void heapify(int i,int n){
    int small=i;
    int left=2*i;
    int right=2*i+1;
    if(left<n && left>=ht &&  buffer[small]>buffer[left]){
        small =left;
    }
    if(right<n && right>=ht &&  buffer[small]>buffer[right]){
        small =right;
    }
    if(small !=i){
        int temp=buffer[i];
        buffer[i]=buffer[small];
        buffer[small]=temp;
        heapify(small,heapn);
    }
}
void print(){
    printf("buffer is\n");
    for(int i=0;i<4;i++){
        printf("%d ",buffer[i]);
    }
    printf("\n");
}
void fullheapify(){
    for(int i=heapn;i>=ht;i--){
        heapify(i,heapn);
    }
}
int del(){
    int k=buffer[0];
    buffer[0]=buffer[heapn-1];
    heapn--;
    fullheapify();
    hl=heapn-1;
    return k;
}
int main() {
    for(int i=0;i<4;i++){
        buffer[i]=input[i];
        it++;
    }
    heapn=4;
    ht=0;
    hl=4-1;
    print();
    fullheapify();
    print();
    do{
        do{ 
            int k;
            k=del();
            ot++;
            output[ot]=k;
            
            if(input[it]>k){
                hl++;
                buffer[heapn]=input[it];
                heapn++;
                heapify(heapn-1,heapn);
                it++;
                printf("%d\n",heapn);
                printf("it is from 1\n");
                
                print();
            }
            else{
                

                hl=heapn-1;
                listn++;
                lt=hl+1;
                buffer[lt]=input[it];
                it++;
                 printf("%d\n",heapn);
                printf("it is from 2\n");
                print();
            }
            
        }while(heapn>0);
        heapn=4;
        fullheapify();
        printf("it is from 4\n");
        print();
        hl=4;
        lt=-1;
        listn=0;
    }while(it<11);
    for(int i=0;i<11;i++){
        printf("%d ",output[i]);
    }
    return 0;
}