// using a one sided binary tree, with start_next on right node and end_current on left node
//first sorting all starts and carrying their ends wit them then some algo 
// check diagrams
#include <stdio.h>

int main() {
    
    int n;
    
    scanf("%d",&n);
    
    int a[2*n];
    
    for(int i=0;i<n;i++){
        scanf("%d",&a[2*i]);
        scanf("%d",&a[2*i+1]);
    }
    
    int p = n-1;
    
    while(p>0){
        if(a[2*p]<a[2*(p-1)]){
            
            int temp = a[2*p];
            a[2*p] = a[2*(p-1)];
            a[2*(p-1)] = temp;
        
            temp = a[2*p+1];
            a[2*p+1] = a[2*p -1];
            a[2*p -1] = temp;
        }
        p--;
    }
    
    int start =0;
    int end =1;
    while(end<=(2*n)-1){
        int q=0;
        
        while(end<2*n-1 && start<2*n-2 && a[end]>=a[start+2]){
            q++;
            start+=2;
            end+=2;
        }
        start-=(2*q);
        printf("%d %d \n",a[start],a[end]);
        start+=2*q;
        start+=2;
        end+=2;
    }
    

    return 0;
}