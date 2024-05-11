#include <stdio.h>

int main() {
    
    int len;
    int num = 7;
    scanf("%d", &len);

    char arr[len-1];

    for (int i = 0; i < len-1; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < len-1; i++) {
        if( arr[i] == num){
            printf("%d", i);
            return 0;
        }
        else{
            continue;
        }
    }
    printf("-1");
}