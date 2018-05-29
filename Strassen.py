class matrix(object):
	def _init_(self, rows):
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
	C = matrix()
	C._init_(n)
	if n == 1:
		C.m[0][0] = A.m[0][0] * B.m[0][0]
	else:
		C.m[0][0] = Matrix_multiply_recursive(A.m[0][0], B.m[0][0]) + Matrix_multiply(A.m[0][1], B.m[1][0])
		C.m[0][1] = Matrix_multiply_recursive(A.m[0][0], B.m[0][1]) + Matrix_multiply(A.m[0][1], B.m[1][1])
		C.m[1][0] = Matrix_multiply_recursive(A.m[1][0], B.m[0][0]) + Matrix_multiply(A.m[1][1], B.m[1][0])
		C.m[1][1] = Matrix_multiply_recursive(A.m[1][0], B.m[0][1]) + Matrix_multiply(A.m[1][1], B.m[1][1])
	return C


A = matrix()
A._init_(2)
B = matrix()
B._init_(2)
A.m[0][0] = 1
A.m[0][1] = 2
A.m[1][0] = 2
A.m[1][1] = 1
B.m[0][0] = 3
B.m[0][1] = 1
B.m[1][0] = 1
B.m[1][1] = 3
C = Matrix_multiply_recursive(A,B)
print(C.m)