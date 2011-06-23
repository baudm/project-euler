
def factorial(n):
	prod = 1
	while n > 1:
		prod *= n
		n -= 1
	return prod


def C(n, k):
	return factorial(n) / (factorial(k) * factorial(n - k))


def get_num_routes(n):
	# Get the corresponding Pascal's triangle row number
	row_num = 2*n
	return C(row_num - 1, row_num / 2)

if __name__ == '__main__':
	# n = 20 for 20x20 grid
	print get_num_routes(20)
