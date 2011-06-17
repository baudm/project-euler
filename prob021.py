import math


def d(n):
	s = 1
	for i in range(2, int(math.sqrt(n)) + 1):
		if n % i == 0:
			# Add factor
			s += i
			# and its mirror if it's not the same
			if i != n / i:
				s += n / i
	return s


def main():
	data = {}
	amicables = []
	# Generate
	for n in range(1, 10000):
		data[n] = d(n)
	# Filter
	for k, v in data.iteritems():
		if k != v and k == data.get(v):
			amicables.append(k)

	return sum(amicables)


if __name__ == '__main__':
	print main()
