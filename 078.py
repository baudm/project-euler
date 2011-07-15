import euler

n = 61
pent_nums = []
cache = {}

while True:
	if euler.p(n, pent_nums, cache) % 1000000 == 0:
		break
	n += 1

print n
