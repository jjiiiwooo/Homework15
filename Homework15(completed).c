#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

int list[MAX_SIZE];
int compareCount = 0; //비교횟수
int moveCount = 0; //이동 횟수 

//정렬 과정 출력
void Print(int list[], int n) {
    for (int i = 0; i < n; i++)
        printf("%3d", list[i]);
    printf("\n");
}

//gap 만큼 떨어진 요소들을 삽입정렬
//정렬의 범위는 first에서 last
inc_insertion_sort(int list[], int first, int last, int gap)
{
    int i, j, key;

    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i]; //현재 삽입될 숫자인 i번째 정수를 key 변수로 복사 

        //현재 정렬된 배열은 i-gap까지이므로 i-gap번째부터 역순으로 조사
        //j 값은 first 이상이어야 하고
        //key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+gap번째로 이동
        for (j = i - gap; j >=first && list[j] > key; j = j - gap) {
            list[j + gap] = list[j]; //gap만큼 오른쪽으로 이동
            moveCount++;
        }

        list[j + gap] = key;
        compareCount++;
    }

}


//쉘 정렬(gap이 변할때마다 정렬 과정 포함)
void shell_sort_print(int list[], int n) {
    int i, gap;

    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if ((gap % 2) == 0) gap++;
        for (i = 0; i < gap; i++) //부분 리스트의 개수는 gap
            inc_insertion_sort(list, i, n - 1, gap);
        Print(list, n);
    }
}

//쉘 정렬
void shell_sort(int list[], int n) {
    int i, gap;

    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if ((gap % 2) == 0) gap++;
        for (i = 0; i < gap; i++) //부분 리스트의 개수는 gap
            inc_insertion_sort(list, i, n - 1, gap);
    }
}

//0~99범위의 랜덤 숫자 생성
void Random(int array[], int n) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100;
        //중복없이
        for (int j = 0; j < i; j++) {
            if (array[i] == array[j])i--;
        }
    }
}

int main(void)
{
    //20개 20회 생성한 난수를 담을 2차원 배열
    int array[MAX_SIZE][MAX_SIZE];
    int n = sizeof(array[0]) / sizeof(array[0][0]);

    for (int i = 0; i < 20; i++) {
        Random(array[i], n);
    }

    printf("Original List\n");
    Random(list, n);
    Print(list, n);
    printf("\n");
    printf("Shell_sort\n");
    shell_sort_print(list, n);
    printf("정렬결과:\n");
    Print(list, n);

    //20회의 쉘 정렬 수행
    for (int i = 0; i < 20; i++) {
        shell_sort(array[i], n);
    }
    printf("Average Move Count: %d\n", moveCount/20);
    printf("Average Compare Count:%d\n", compareCount/20);

}
