#include <stdio.h>

int main() {
    
    int len;
    int num;
    scanf("%d", &len);
    scanf("%d", &num);

    char arr[len];

    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < len; i++) {
        if( arr[i] == num){
            int j = i + 1;
            printf("%d", j);
            return 0;
        }
        else{
            continue;
        }
    }
    printf("no such bamboo");
}