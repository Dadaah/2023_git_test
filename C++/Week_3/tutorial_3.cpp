// main.cpp
#include <iostream>

// 함수 선언
int add(int a, int b) {
    // 두 정수를 더하여 결과 반환
    return a + b;
}

int main() {
    // 함수 호출
    int result = add(3, 4);
    std::cout << "Result: " << result << std::endl;

    // 배열
    int numbers[5] = {1, 2, 3, 4, 5};

    // 배열 출력
    std::cout << "Numbers: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
