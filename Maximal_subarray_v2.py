#动态规划版本
def find_max_subarray(A, low, high):
	temp = 0
	max_sum = float('-inf')
	for i in range(low, high+1):
		if temp < 0:
			temp = A[i]
		else:
			temp += A[i]
		if temp > max_sum:
			max_sum = temp

	print(max_sum)

A = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
find_max_subarray(A, 0, 15)