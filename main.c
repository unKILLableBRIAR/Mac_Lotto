#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int chk_num(int, int*, int);
void sort_num(int[5][6]);

int main(){
    FILE* fp = fopen("lotto.txt", "w");
    if(fp == NULL){
        fprintf(stderr, "Can't make a file!\n");
        return 1;
    }

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

    sort_num(lotto);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++)
            fprintf(fp, "%2d ", lotto[i][j]);
        fprintf(fp, "\n");
    }

    fclose(fp);
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

void sort_num(int arr[5][6]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int flag = arr[i][j];
            for(int k = j + 1; k < 6; k++){
                if(arr[i][k] < flag){
                    int tmp = arr[i][k];
                    arr[i][k] = flag;
                    flag = tmp;
                    arr[i][j] = flag;
                }
            }
        }
    }
}