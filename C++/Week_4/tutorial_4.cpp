// main.cpp
#include <iostream>

int main() {
    // 포인터와 동적 할당
    int* dynamicNumber = new int; // 동적으로 정수형 변수 할당
    *dynamicNumber = 7;

    std::cout << "Dynamic Number: " << *dynamicNumber << std::endl;

    delete dynamicNumber; // 메모리 해제

    return 0;
}

