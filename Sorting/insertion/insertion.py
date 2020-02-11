import numpy as np 

arr = np.random.randint(0,100,(10))

i = 0 ;

while (i<10):
    x = arr[i]
    j = i-1
    while(j>=0 and arr[j]>x):
        arr[j+1] = arr[j]
        j = j - 1 
    arr[j+1] = x 
    i = i + 1

print(arr)
