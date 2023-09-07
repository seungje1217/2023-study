# A+B-8
def main():
    n = int(input())

    a = []
    b = []
    sum = []

    for i in range(n):
        input_values = input().split()
        a_i, b_i = map(int, input_values)
        a.append(a_i)
        b.append(b_i)
        sum_i = a_i + b_i
        sum.append(sum_i)

    for i in range(n):
        print(f"Case #{i + 1}: {a[i]} + {b[i]} = {sum[i]}")

if __name__ == "__main__":
    main()
