import numpy as np

arr = np.random.randint(0,100,(10))

for i in range(10):
    for j in range(9):
        if arr[j]>arr[j+1]:
            tem = arr[j]
            arr[j] = arr[j+1]
            arr[j+1] = tem

print(arr)