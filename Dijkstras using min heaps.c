#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10
 
struct minheap{
    int dist;
    int visited;
    int idx;
    int distforHeapify; 
};
 
void Heapify(struct minheap A[],int n , int i){
    
    int j=2*i+1;
    int temp=i;
    while(j<=n-1){
        if ( j+1 <=n-1 && A[j].distforHeapify > A[j+1].distforHeapify){ 
            j = j+1;
        }
             
        if (A[i].distforHeapify > A[j].distforHeapify){ 
            
            struct minheap temp=A[i];   
            A[i]=A[j]; 
            A[j]=temp;
 
            i = j;
            j = 2 * i + 1;
        } 
        else {
            break;
        }
    }
}
  
void min_Heapify(struct minheap A[],int n){  
    for(int i=(n/2)-1;i>=0;i--){
        Heapify(A,n,i);
    }
}
 
void dijktras(int G[MAX][MAX],int n,int s){
    struct minheap C[n];
    int i,nextnode,count,mindistance;
    for(i=0;i<n;i++){
        C[i].dist=G[s][i];
        C[i].visited=0;
        C[i].idx=i;
        C[i].distforHeapify=G[s][i];
    }
    C[s].dist=0;
    C[s].visited=1;
    C[s].distforHeapify=INFINITY;
    
    count=1;
 
    while(count<n-1){
        int mindistance=INFINITY;
        min_Heapify(C,n);
        
        mindistance=C[0].dist;
        nextnode=C[0].idx;
 
        struct minheap *temp=&C[0]; 
        temp->visited=1;
        temp->distforHeapify=INFINITY;
 
        for(i=0;i<n;i++){
            if(C[i].visited==0){
                if(mindistance+G[nextnode][C[i].idx]<C[i].dist){ 
                    struct minheap *temp1=&C[i];
                    temp1->dist=mindistance+G[nextnode][C[i].idx]; 
                    temp1->distforHeapify=temp1->dist; 
                }
            }
        }
        count++;
    }
    for(i=0;i<n;i++){
        
            printf("Distance of %d = %d\n",C[i].idx,C[i].dist); 
        
    }
}
 
int main(){
    int G[MAX][MAX];
    int i,j,n,s;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter Adjacency matrix: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&G[i][j]);
            if(G[i][j]==0){
                G[i][j]=INFINITY;
            }
            
        }
        printf("\n");
    }
    printf("Enter starting node: \n");
    scanf("%d",&s);
    dijktras(G,n,s);
 
    return 0;
}

/*0 8 5 0 0

8 0 9 1 0

5 9 0 15 10

0 1 15 0 2

0 0 10 2 0*/