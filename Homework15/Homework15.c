#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 19

int list[MAX_SIZE];
int array[MAX_SIZE][MAX_SIZE];
int n;

//정렬 과정 출력 
void Print(int list[], int n) {
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%3d", list[i]);
	}
	printf("\n");
}

//gap 만큼 떨어진 요소들을 삽입 정렬
inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}


//쉘 정렬
void shell_sort(int list[], int n)
{
	int i, gap;
	int MoveCount = 0;
	int CompareCount = 0;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++) {
			inc_insertion_sort(list, i, n - 1, gap);
			Print(array, n);
			MoveCount++;
		}
		CompareCount++;
	}
}



int main(void)
{
	int i, j;
	int average_compareCount = 0;
	int average_MoveCount = 0;

	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 1; i < n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100; // 난수 발생 범위 0~99
	printf("Original List\n");
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

	printf("Shell Sort\n");


	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			array[i][j] = rand() % 100;
		}
	}

	//쉘 정렬 20회 수행
	for (i = 0; i < n; i++) {
		shell_sort(array[i], n);
		printf("\n");
	}



}