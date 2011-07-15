import math


def pentagonal(n):
	return n*(3*n - 1)/2


def _p(n, pent_nums, cache):
	"""
	This is the actual implementation of the partition function
	based on the recurrence relation of p(n)
	"""
	if n == 0:
		return 1
	count = 0
	for i in range(0, len(pent_nums)):
		if pent_nums[i] > n:
			break
		x = n - pent_nums[i]
		# cache hit is more likely
		try:
			c = cache[x]
		except KeyError:
			c = _p(x, pent_nums, cache)
			cache[x] = c
		k = i/2 + 1
		# even: negative sign
		if k % 2 == 0:
			count -= c
		else:
			count += c
	return count


def p(n, pent_nums=None, cache=None):
	"""
	Interface to the partition function p(n)
	This function is responsible for generating the generalized pentagonal
	numbers to be used later and for allocating the cache for memoization
	"""
	if pent_nums is None:
		pent_nums = []
		k = 1
	elif pent_nums:
		last = pent_nums[-1]
		k = int((1 + math.sqrt(1 + 24*last))/6)
		if pentagonal(-k) == last:
			k += 1
		else:
			# remove the last item because it will
			# be re-added later in the while loop
			pent_nums.pop()
	else:
		k = 1
	# generate generalized pentagonal numbers up to n
	while True:
		# positive k
		num = pentagonal(k)
		if num > n:
			break
		pent_nums.append(num)
		# negative k
		num = pentagonal(-k)
		if num > n:
			break
		pent_nums.append(num)
		k += 1
	if cache is None:
		cache = {}
	return _p(n, pent_nums, cache)
