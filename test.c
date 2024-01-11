#include <stdio.h>

int main(){
    int arr[10] = {67,34,234,654,634,94,2,4,46,77};
    int cnt = 0;
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
        cnt++;
    }

    printf("\n");

    for(int i = 0; i < 9; i++){
        int flag = arr[i];
        for(int j = i + 1; j < 10; j++){
            if(arr[j] < flag){
                int tmp = arr[j];
                arr[j] = flag;
                flag = tmp;
                arr[i] = flag;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}