import operator
print str(sum(map(operator.pow, range(1, 1001), range(1, 1001))))[-10:]
