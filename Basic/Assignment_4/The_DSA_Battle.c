//this has the logic however condition that b>a is not clarified
#include <stdio.h>
#include<stdbool.h>

int main() {
    int n,a,b;
    
    scanf("%d",&n);
    scanf("%d",&a);
    scanf("%d",&b);

    char ans[n];
    
    ans[0]='K';
    
    
    int count = a/b;
    bool k =true;
    bool o=false;
    
    int current = count-1;
    int i=1;
    
    
    while(i<n){
        if(current<=0){
            k=false;
            o=true;
        }
        if(k){
            ans[i++] = 'K';
            current--;
        }
        if(o){
            ans[i++]='O';
            current = count;
            o=false;
            k=true;
        }
        
    }
    
    for(int i=0;i<n;i++){
        printf("%c",ans[i]);
    }
    

    return 0;
}