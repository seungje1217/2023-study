#include <iostream>
#include <string>

using namespace std;

int main() {
    // 정수 입력 받기
    cout << "정수를 입력하세요: ";
    int intValue;
    cin >> intValue;
    cout << "입력한 정수: " << intValue << endl;

    // 실수 입력 받기
    cout << "실수를 입력하세요: ";
    double doubleValue;
    cin >> doubleValue;
    cout << "입력한 실수: " << doubleValue << endl;

    // 개행문자(Enter) 처리
    cin.ignore();

    // 문자열 입력 받기
    cout << "문자열을 입력하세요: ";
    string stringValue;
    getline(cin, stringValue);
    cout << "입력한 문자열: " << stringValue << endl;

    return 0;
}
