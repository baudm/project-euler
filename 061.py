import copy

def triangle(n):
	return n*(n + 1)/2

def square(n):
	return n*n

def pentagon(n):
	return n*(3*n - 1)/2

def hexagon(n):
	return n*(2*n - 1)

def heptagon(n):
	return n*(5*n - 3)/2

def octagon(n):
	return n*(3*n - 2)


def find_cycle(cycle, pool):
	used, chain = zip(*cycle)
	end = chain[-1][2:]
	foo = filter(lambda k: k not in used, pool.keys())
	cycles = []
	for s in foo:
		matches = filter(lambda x: x.startswith(end), pool[s])
		for m in matches:
			cycle_here = copy.copy(cycle)
			cycle_here.append((s, m))
			#print cycle_here
			cycles.append(find_cycle(cycle_here, pool))
	if cycles:
		lengths = map(len, cycles)
		i = lengths.index(max(lengths))
		c = cycles[i]
		if len(c) == 6 and c[0][1].startswith(c[-1][1][2:]):
			print sum(map(int, zip(*c)[1]))
		# longest cycle
		return c
	else:
		return cycle


def main():
	pool = {}
	for func in [triangle, square, pentagon, hexagon, heptagon, octagon]:
		d = map(func, range(19, 142))
		pool[func.__name__] = map(str, filter(lambda x: 1000 <= x <= 9999, d))
	for num in pool['octagon']:
		start = [('octagon', num)]
		c = find_cycle(start, pool)

		#if len(c) == 6: print c, c[0], c[-1]
		#if len(c) == 6 and c[0][1].startswith(c[-1][1][2:]):
		#	print c

if __name__ == '__main__':
	main()
