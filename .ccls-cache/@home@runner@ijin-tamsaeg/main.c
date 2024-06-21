#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

void sort(int list[], int n) {

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (list[i] > list[j]) {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

int find_last(int list[], int n, int key) {

    int low = 0; 
    int high = n - 1;
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (key == list[mid]) {
            result = mid;
            low = mid + 1;
        } else if (key > list[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main(void) {

    int list[] = {2, 3, 5, 6, 7, 2, 10, 14, 2, 4};
    int n = sizeof(list) / sizeof(int);

    int key;
    printf("원하는 값을 입력하시오 : ");
    scanf("%d", &key);
                                                 // 배열 정렬
    sort(list, n);                              

    int last = find_last(list, n, key);         // 마지막 발생 위치 찾기

    printf("정렬된 배열: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    printf("마지막 발생 위치: %d\n", last);

    return 0;
}