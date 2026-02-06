def remove_duplicates():
    # Read input
    try:
        n = int(input())
        if n == 0:
            return
        
        arr = list(map(int, input().split()))
    except EOFError:
        return

    # If the array has elements, the first one is always unique
    unique_elements = [arr[0]]

    # Single pass to find unique values
    for i in range(1, n):
        if arr[i] != arr[i - 1]:
            unique_elements.append(arr[i])

    # Print the result space-separated
    print(*(unique_elements))

if __name__ == "__main__":
    remove_duplicates()
