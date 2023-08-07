import java.util.Scanner;

public class calculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double num1, num2;
        char operator;
        
        System.out.print("첫 번째 숫자를 입력하세요: ");
        num1 = scanner.nextDouble();
        
        System.out.print("두 번째 숫자를 입력하세요: ");
        num2 = scanner.nextDouble();
        
        System.out.print("사칙연산 기호(+, -, *, /) 중 하나를 입력하세요: ");
        operator = scanner.next().charAt(0);
        
        double result = 0;
        switch (operator) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0)
                    result = num1 / num2;
                else
                    System.out.println("0으로 나눌 수 없습니다.");
                break;
            default:
                System.out.println("잘못된 연산자를 입력했습니다.");
                return;
        }
        
        System.out.println("결과: " + result);
    }
}
