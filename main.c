#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int chk_num(int, int*, int);

int main(){
    srand((unsigned)time(NULL)); //시드를 현재시간으로 설정

    int lotto[5][6]; //6개의 로또번호를 5개 담을 수 있는 배열

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            if(j == 0)
                lotto[i][j] = rand() % 45 + 1;
            else{
                while(1){
                    int n = rand() % 45 + 1;
                    if(chk_num(n, lotto[i], j) == 1){
                        lotto[i][j] = n;
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++)
            printf("%2d ", lotto[i][j]);
        printf("\n");
    }

    return 0;
}

int chk_num(int n, int* arr, int cnt){
    int flag = 0;
    for(int i = 0; i < cnt; i++){
        if(arr[i] == n)
            flag++;
    }
    if(flag == 0)
        return 1;
    else
        return 0;
}