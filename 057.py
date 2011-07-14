def main():
	"""
	One can generate the next expansion of sqrt(2) using the terms from the
	current expansion and the previous expansion. That is,

	N(k+1) = 2*N(k) + N(k-1)
	D(k+1) = 2*D(k) + D(k-1)
	"""
	curr_num = 3
	prev_num = 1
	curr_den = 2
	prev_den = 1
	count = 0

	for i in range(2, 1001):
		# compute numerator
		tmp = 2*curr_num + prev_num
		prev_num = curr_num
		curr_num = tmp
		# compute denominator
		tmp = 2*curr_den + prev_den
		prev_den = curr_den
		curr_den = tmp
		if (len(str(curr_num)) > len(str(curr_den))):
			count += 1
	print count


if __name__ == '__main__':
	main()
