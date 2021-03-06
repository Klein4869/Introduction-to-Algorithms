def merge(A, p, q, r):  # p为数组1开始， q+1为数组2开始， 合并部分
    n_1 = q - p + 1  # 数组1的元素个数
    n_2 = r - q  # 数组2元素个数
    L = list()
    R = list()

    for i in range(0, n_1):
        L.append(A[p+i])
    for j in range(0, n_2):
        R.append(A[q+1+j])

    L.append(float('inf'))  # 哨兵牌
    R.append(float('inf'))

    i = 0
    j = 0

    for k in range(p, r+1):  # 将较小牌放入输出堆
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

    return A


def merge_sort(A, p, r):  # 算法部分
    if p < r:
        q = int((p+r)/2)
        merge_sort(A, p, q)
        merge_sort(A, q+1, r)
        A = merge(A, p, q, r)
    return A


A = [1, 11, 0, 29, 0, 2, 20, 70, 8, 10]
print(A)
A = merge_sort(A, 0, 9)
print(A)