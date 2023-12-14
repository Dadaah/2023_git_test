#include <stdio.h>
#include "test.h"

int main() {
    double length, width;
    printf("직사각형 두 변의 길이 입력: ");
    scanf_s("%lf %lf", &length, &width);

    double happy = calculate(length, width);
    printf("직사각형 둘레: %.2f", happy);

    return 0;
}