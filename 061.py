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
	figures = filter(lambda k: k not in used, pool.keys())
	cycles = []
	for f in figures:
		matches = filter(lambda x: x.startswith(end), pool[f])
		for m in matches:
			cycle_here = copy.copy(cycle)
			cycle_here.append((f, m))
			cycles.append(find_cycle(cycle_here, pool))
	if cycles:
		for c in cycles:
			if len(c) == 6 and c[0][1].startswith(c[-1][1][2:]):
				return c
		return cycle
	else:
		return cycle


def main():
	pool = {}
	for func in [triangle, square, pentagon, hexagon, heptagon, octagon]:
		d = map(func, range(19, 142))
		pool[func.__name__] = map(str, filter(lambda x: 1000 <= x <= 9999, d))
	for num in pool['octagon']:
		start = [('octagon', num)]
		cycle = find_cycle(start, pool)
		if len(cycle) == 6:
			print sum(map(int, zip(*cycle)[1]))


if __name__ == '__main__':
	main()
