#include <stdio.h>
#include "test.h"

int main() {
    double length, width;
    printf("���簢�� �� ���� ���� �Է�: ");
    scanf_s("%lf %lf", &length, &width);

    double happy = calculate(length, width);
    printf("���簢�� �ѷ�: %.2f", happy);

    return 0;
}