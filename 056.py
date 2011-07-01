sums = []
for a in range(2, 100):
	for b in range(2, 100):
		s = sum(map(int, str(a**b)))
		sums.append(s)
print max(sums)
