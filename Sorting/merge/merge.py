import numpy as np

num = np.zeros(100000)
temp = np.zeros(100000)

def mergesort(lo,hi):
    if lo==hi:
        return

    mid = int((lo+hi) / 2)
    mergesort(lo,mid)
    mergesort(mid+1,hi)

    i = lo
    j = mid+1
    for k in range(lo,hi+1):
        if i==mid+1:
            temp[k] = num[j]
            j = j+1
        elif j==hi+1:
            temp[k] = num[i]
            i = i+1
            pass
        elif num[i]<num[j]:
            temp[k] = num[i]
            i = i+1
        else:
            temp[k] = num[j]
            j = j+1
    
    for k in range(lo,hi+1):
        num[k] = temp[k]
    
    print(temp[lo:hi+1])


if __name__ == '__main__':
    np.random.seed(101)
    arr = np.random.randint(0,100,10)
    num = np.concatenate((arr, num), axis=0)
    mergesort(0,9)
    print()
    print('After Sorting')
    print(num[:10])
    

