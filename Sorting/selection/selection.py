import numpy as np

arr = np.random.randint(0,100,(10))
for i in range(0,10):
    j = i+1
    while(j<10):
        if arr[i]>arr[j]:
            tem = arr[i]
            arr[i] = arr[j]
            arr[j] = tem 
        j = j + 1

print(arr)