#include <iostream>

int main() {
    // 2주차 튜토리얼 - 조건문과 반복문

    // 1. if 조건문
    int x = 10;

    if (x > 0) {
        std::cout << "x is positive." << std::endl;
    } else if (x < 0) {
        std::cout << "x is negative." << std::endl;
    } else {
        std::cout << "x is zero." << std::endl;
    }

    // 2. switch 조건문
    char grade = 'B';

    switch (grade) {
        case 'A':
            std::cout << "Excellent!" << std::endl;
            break;
        case 'B':
            std::cout << "Good job!" << std::endl;
            break;
        case 'C':
            std::cout << "Satisfactory." << std::endl;
            break;
        default:
            std::cout << "Need improvement." << std::endl;
    }

    // 3. for 반복문
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Iteration " << i << std::endl;
    }

    // 4. while 반복문
    int count = 3;
    while (count > 0) {
        std::cout << "Countdown: " << count << std::endl;
        --count;
    }

    // 5. do-while 반복문
    int number;
    do {
        std::cout << "Enter a positive number: ";
        std::cin >> number;
    } while (number <= 0);

    std::cout << "You entered: " << number << std::endl;

    return 0;
}
