#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 比较函数，用于 qsort
int compare(const void* a, const void* b) {
    const int* int_a = (const int*)a;
    const int* int_b = (const int*)b;

    return (*int_a > *int_b) - (*int_a < *int_b);
}

int main() {
    long long N = 0, k, x;

    printf("请输入数字的个数：");
    // 使用 %lld 读取 long long 类型的 N
    scanf("%lld", &N);

    int* arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    for (long long i = 0; i < N; i++) {
        scanf("%d", &x);
        arr[i] = x;
    }

    // 使用 qsort 对数组进行排序
    qsort(arr, N, sizeof(int), compare);

    printf("请输入你想找出的第 x 小的数：");
    // 使用 %lld 读取 long long 类型的 k
    scanf("%lld", &k);

    // 使用 %d 输出 int 类型的数组元素
    printf("%d 是第 %lld 小的数\n", arr[k - 1], k);

    // 释放动态分配的内存
    free(arr);

    return 0;
}