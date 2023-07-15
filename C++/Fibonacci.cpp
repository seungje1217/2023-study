#include <iostream>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num;
    std::cout << "피보나치 수열의 항 번호를 입력하세요: ";
    std::cin >> num;

    std::cout << "피보나치 수열의 " << num << "번째 항은 " << fibonacci(num) << "입니다." << std::endl;

    return 0;
}
