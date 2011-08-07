import itertools


def get_sum_distribution(values, pieces):
	dice = []
	for i in range(pieces):
		dice.append(values)
	sums = []
	for outcome in itertools.product(*dice):
		sums.append(sum(outcome))
	distinct = set(sums)
	freq = itertools.imap(sums.count, distinct)
	return dict(itertools.izip(distinct, freq))


def main():
	# 1 to 4, 9 pieces
	pyramid = get_sum_distribution(range(1, 5), 9)
	# 1 to 6, 6 pieces
	cube = get_sum_distribution(range(1, 7), 6)
	denominator = sum(pyramid.values()) * sum(cube.values())
	numerator = 0
	for p_total in pyramid:
		for c_total in cube:
			if c_total >= p_total:
				break
			numerator += cube[c_total] * pyramid[p_total]
	print '{0:.7f}'.format(numerator/float(denominator))


if __name__ == '__main__':
	main()
