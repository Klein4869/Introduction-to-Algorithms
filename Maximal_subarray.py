def find_max_crossing_subarray(A, low, high, mid):
	left_sum = float('-inf')
	sum = 0
	for i in xrange(mid,low-1):
		sum += A[i]
		if left_sum < sum:
			left_sum = sum
			max_left = i
	right_sum = float('-inf')
	sum = 0
	for i in xrange(mid+1, high+1):
		sum += A[i]
		if right_sum < sum:
			right_sum = sum
			max_right = i

	return max_left, max_right, left_sum+right_sum


def find_max_subarray(A, low, high):
	if low == high:
		return(low, high, A[low])
	mid = int((low+high)/2)
	left_low, left_high = find_max_subarray(A, low, mid)
	right_low, right_high = find_max_subarray(A, mid+1, high)
	cross_low, cross_high, cross_sum = find_max_crossing_subarray(A, low, high, mid)

	if left_sum >= right_sum and left_sum >= cross_sum:
		return left_low, left_high, left_sum
	elif right_sum >= left_sum and right_sum >= cross_sum:
		return right_low, right_high, right_sum
	else:
		return cross_low, cross_high, cross_sum