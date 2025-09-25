#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// �ȽϺ��������� qsort
int compare(const void* a, const void* b) {
    const int* int_a = (const int*)a;
    const int* int_b = (const int*)b;

    return (*int_a > *int_b) - (*int_a < *int_b);
}

int main() {
    long long N = 0, k, x;

    printf("���������ֵĸ�����");
    // ʹ�� %lld ��ȡ long long ���͵� N
    scanf("%lld", &N);

    int* arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("�ڴ����ʧ��\n");
        return 1;
    }

    for (long long i = 0; i < N; i++) {
        scanf("%d", &x);
        arr[i] = x;
    }

    // ʹ�� qsort �������������
    qsort(arr, N, sizeof(int), compare);

    printf("�����������ҳ��ĵ� x С������");
    // ʹ�� %lld ��ȡ long long ���͵� k
    scanf("%lld", &k);

    // ʹ�� %d ��� int ���͵�����Ԫ��
    printf("%d �ǵ� %lld С����\n", arr[k - 1], k);

    // �ͷŶ�̬������ڴ�
    free(arr);

    return 0;
}