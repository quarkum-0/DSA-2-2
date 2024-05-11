// sum of k smallest elements with O(nlogk)
#include <stdio.h>
#include<stdlib.h>


void Heapify(int* a, int i, int n){//heapifying index i element(making sure a[i] satisfies minHeap property)
    
    int left =2*i +1;
    int right = 2*i +2;
    
    int min = i;// min will be the index of the minimum element
    
    if(left<n && a[left]<a[min]){
        min = left;
    }
    
    if(right<n && a[right]<a[min]){
        min = right;
    }
    if(i!=min){//if minimum index isnt i, swap elements of a[i] and a[min] so that minimum element is at i (parent)
        int temp  = a[i];
        a[i] = a[min];
        a[min] = temp;
        Heapify(a,min,n);
    }
    
    
}


void buildMinHeap(int* a, int n){
   
    for(int i=0;i<n/2;i++){//n/2 cuz leaf nodes are already heaps which satisfy
        Heapify(a,i,n);
    }
   
}


int sumK(int* a, int n, int k){
    
    buildMinHeap(a,n);// a min heap is built
    
    int sum =0;
    
    while(k>0){
        sum+=a[0]; //a[0] will have minimum element of heap cuz of minHeap property
        int temp = a[n-1];
        a[n-1] = a[0];
        a[0] = temp;
        n--;
        
        k--;
        
        Heapify(a,0,n);
    }
    return sum;
    
}


int main() {
    
    int n,k;
    
    scanf("%d",&n);
    scanf("%d",&k);

    int a[n];

    for(int i = 0; i<n; i++){
        scanf("%d",&a[i]);
    }
    
    int sum = sumK(a,n,k);
    
    printf("%d",sum);
    
    
    return 0;
}