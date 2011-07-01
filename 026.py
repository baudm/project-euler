import math


def is_prime(num):
	if num == 1:
		return False

	s = int(math.sqrt(num))
	if (num % 2 == 0 and 2 <= s) or (num % 3 == 0 and 3 <= s):
		return False

	for p in range(5, s + 1, 6):
		if num % p == 0 or num % (p + 2) == 0:
			return False

	return True


def order(a, n):
	"""order of a mod n"""
	k = 1
	while a**k % n != 1:
		#print a, n, k
		k += 1
	return k


def main():
	longest = 1
	n = 0
	# Only consider the set of prime numbers
	for d in range(11, 1000, 6) + range(7, 1000, 6):
		if not is_prime(d):
			continue
		l = order(10, d)
		if l > longest:
			longest = l
			n = d
	print n


if __name__ == '__main__':
	main()
