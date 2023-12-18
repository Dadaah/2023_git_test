// main.cpp
#include <iostream>
#include <fstream>

int main() {
    // 파일 입출력
    std::ofstream outputFile("output.txt"); // 출력 파일 생성

    if (outputFile.is_open()) {
        outputFile << "Hello, File I/O!" << std::endl;
        outputFile.close(); // 파일 닫기
    } else {
        std::cout << "Unable to open file." << std::endl;
    }

    return 0;
}
