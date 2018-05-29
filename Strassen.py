class matrix(object):
	def _init_(rows):
		self.m = [[0 for i  in range(0, rows)] for i in range(0, rows)]
		self.rows = rows


#原始矩阵乘法
def Matrix_multiply(A, B):
	n = A.rows
	C = matrix(n)
	for i in range(0, n):
		for j in range(0, n):
			for k in range(0, n):
				c[i][j] += A[i][k] * B[k][j]
	return C


#矩阵分治乘法
def Matrix_multiply_recursive(A, B):
	n = A.rows
	C = matrix(n)
	if n == 1:
		C[1][1] = A[1][1] * B[1][1]
	else:
		C[1][1] = Matrix_multiply_recursive(A[1][1], B[1][1]) + Matrix_multiply(A[1][2], B[2][1])
		C[1][2] = Matrix_multiply_recursive(A[1][1], B[1][2]) + Matrix_multiply(A[1][2], B[2][2])
		C[2][1] = Matrix_multiply_recursive(A[2][1], B[1][1]) + Matrix_multiply(A[2][2], B[2][1])
		C[2][2] = Matrix_multiply_recursive(A[2][1], B[1][2]) + Matrix_multiply(A[2][2], B[2][2])
	return C