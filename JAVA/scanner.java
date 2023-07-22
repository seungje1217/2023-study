import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 정수 입력 받기
        System.out.print("정수를 입력하세요: ");
        int intValue = scanner.nextInt();
        System.out.println("입력한 정수: " + intValue);

        // 실수 입력 받기
        System.out.print("실수를 입력하세요: ");
        double doubleValue = scanner.nextDouble();
        System.out.println("입력한 실수: " + doubleValue);

        // 문자열 입력 받기
        System.out.print("문자열을 입력하세요: ");
        String stringValue = scanner.next();
        System.out.println("입력한 문자열: " + stringValue);

        // 입력 스트림 닫기
        scanner.close();
    }
}
