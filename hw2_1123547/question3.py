#Nazbii
#1123547
#24.11.28

import heapq

# Function to merge k sorted arrays using a priority queue
def mergeK(arr):
    res = []
    h = []

    # Insert the first element of each array into the min-heap
    for i in range(len(arr)):
        heapq.heappush(h, (arr[i][0], i, 0))

    # Merge all arrays
    while h:
        val, ap, vp = heapq.heappop(h)
        res.append(val)

        if vp + 1 < len(arr[ap]):
            heapq.heappush(h, (arr[ap][vp + 1], ap, vp + 1))

    return res


# Input
try:
    k = int(input("Enter the number of arrays: ").strip())  # Reading the number of arrays (without text)
    if k <= 0:
        raise ValueError("Number of arrays must be greater than 0.")
except ValueError:
    print("Invalid input. Please enter a valid positive integer.")
    exit()

arr = []
for _ in range(k):
    try:
        array = list(map(int, input().split()))  # Silent input for array
        arr.append(array)
    except ValueError:
        print("Invalid input. Please enter integers separated by spaces.")
        exit()

# Output the merged array
print("Merged Array:", mergeK(arr))


