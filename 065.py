def coeff_gen():
	"""
	Infinite iterator of coefficients:
	1,2,1, 1,4,1, 1,6,1 , ... , 1,2k,1, ...
	"""
	coeffs = [1, 2, 1]
	while True:
		for c in coeffs:
			yield c
		coeffs[1] += 2


def main():
	"""
	One can generate the next expansion of e using the terms from the
	current expansion and the previous expansion. That is,

	N(k+1) = C*N(k) + N(k-1)
	D(k+1) = C*D(k) + D(k-1)

	where C is an element of the set [1,2,1, 1,4,1, 1,6,1 , ... , 1,2k,1, ...]
	"""
	curr_num = 2
	prev_num = 1
	count = 1
	coeffs = coeff_gen()
	for c in coeffs:
		# compute numerator
		tmp = c*curr_num + prev_num
		prev_num = curr_num
		curr_num = tmp
		count += 1
		if count == 100:
			break
	print sum(map(int, str(curr_num)))


if __name__ == '__main__':
	main()
