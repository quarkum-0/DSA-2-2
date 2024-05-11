#include <stdio.h>

int main() {
    
    int len;
    scanf("%d", &len);

    char arr[len];

    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    int max = 0;

    for (int i = 0; i < len; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        else {
            continue;
        }
    }

    for(int i = 0; i < len; i++) {
        if( arr[i] == max){
            int j = i + 1;
            printf("%d", j);
            return 0;
        }
        else{
            continue;
        }
    }
}