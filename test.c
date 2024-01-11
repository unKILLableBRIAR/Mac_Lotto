#include <stdio.h>

int main(){
    int arr[10] = {67,34,234,654,634,34,2,4,46,77};
    int cnt = 0;
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
        cnt++;
    }

    printf("\n%d\n",cnt);

    return 0;
}