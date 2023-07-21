public class Stack {
    private int maxSize;  // 스택의 최대 크기
    private int[] array;  // 스택을 저장할 배열
    private int top;      // 스택의 가장 위를 가리키는 포인터

    // 스택 생성자
    public Stack(int maxSize) {
        this.maxSize = maxSize;
        this.array = new int[maxSize];
        this.top = -1;  // 스택이 비어있음을 표시하는 값으로 -1을 사용합니다.
    }

    // 스택이 비어있는지 확인
    public boolean isEmpty() {
        return (top == -1);
    }

    // 스택이 가득 찼는지 확인
    public boolean isFull() {
        return (top == maxSize - 1);
    }

    // 스택에 데이터 추가 (Push)
    public void push(int data) {
        if (isFull()) {
            System.out.println("스택이 가득 차 있습니다. 데이터를 추가할 수 없습니다.");
        } else {
            array[++top] = data;
        }
    }

    // 스택에서 데이터 제거 및 반환 (Pop)
    public int pop() {
        if (isEmpty()) {
            System.out.println("스택이 비어있습니다. 데이터를 가져올 수 없습니다.");
            return -1;  // 이 경우에는 -1을 반환하여 에러를 표시하겠습니다.
        } else {
            return array[top--];
        }
    }

    // 스택의 맨 위 데이터 확인 (Peek)
    public int peek() {
        if (isEmpty()) {
            System.out.println("스택이 비어있습니다. 데이터를 확인할 수 없습니다.");
            return -1;  // 이 경우에는 -1을 반환하여 에러를 표시하겠습니다.
        } else {
            return array[top];
        }
    }

    // 스택의 현재 크기 반환
    public int size() {
        return top + 1;
    }

    // 스택의 모든 데이터 출력 (최상위 데이터부터 순서대로)
    public void printStack() {
        if (isEmpty()) {
            System.out.println("스택이 비어있습니다.");
            return;
        }

        System.out.print("스택의 내용: ");
        for (int i = top; i >= 0; i--) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Stack stack = new Stack(5);

        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.printStack(); // 출력: 스택의 내용: 30 20 10

        int poppedValue = stack.pop();
        System.out.println("Pop된 값: " + poppedValue); // 출력: Pop된 값: 30

        stack.printStack(); // 출력: 스택의 내용: 20 10

        int peekedValue = stack.peek();
        System.out.println("Peek된 값: " + peekedValue); // 출력: Peek된 값: 20

        System.out.println("스택의 크기: " + stack.size()); // 출력: 스택의 크기: 2
    }
}
