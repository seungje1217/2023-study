def add(a, b):
    return a + b

def subtract(a, b):
    return a - b

def multiply(a, b):
    return a * b

def divide(a, b):
    if b != 0:
        return a / b
    else:
        print("0으로 나눌 수 없습니다.")
        return None

def main():
    print("사칙연산을 수행할 숫자 두 개를 입력하세요:")
    num1 = float(input("첫 번째 숫자 입력: "))
    num2 = float(input("두 번째 숫자 입력: "))
    
    print("사칙연산 기호(+, -, *, /) 중 하나를 입력하세요:")
    operator = input()

    if operator == '+':
        result = add(num1, num2)
    elif operator == '-':
        result = subtract(num1, num2)
    elif operator == '*':
        result = multiply(num1, num2)
    elif operator == '/':
        result = divide(num1, num2)
    else:
        print("잘못된 연산자를 입력했습니다.")
        return

    print("결과:", result)

if __name__ == "__main__":
    main()
