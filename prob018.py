import sys


def get_weight(data, row, idx):
	weight = data[row][idx]
	edge = idx + 2
	#print data[row][idx]
	for r in range(row + 1, len(data)):
		#print data[r][idx:edge]
		weight += sum(data[r][idx:edge])
		edge += 1
	return weight
	
	
def get_weight_left(data, row, idx):
	weight = data[row][idx]
	print data[row][idx]
	for r in range(row + 1, len(data)):
		edge = (r - row) / 2
		print data[r][idx:edge]
		weight += sum(data[r][idx:edge])
	return weight


def get_weight_right(data, row, idx):
	weight = data[row][idx]
	print data[row][idx]
	for r in range(row + 1, len(data)):
		edge = idx + (r - row) + 1
		s = (r + 2) / 2
		print data[r][s:edge]
		weight += sum(data[r][s:edge])
	return weight


def main(fname):
	data = []
	with open(fname, 'r') as f:
		for line in f:
			data.append(map(int, line.split()))
	path = [data[0][0]]
	i = 0
	for r in range(1, len(data)):
		left = get_weight_left(data, r, i)
		right = get_weight_right(data, r, i + 1)
		
		#if r + 1 < len(data):
		#	left += get_weight(data, r + 1, i)
		#	right += get_weight(data, r + 1, i + 2)
		print data[r][i], left, data[r][i + 1], right

		if right > left:
			i += 1
		#elif right == left:
		#	print 'sabog!'
		path.append(data[r][i])
	print path
	#print len(path)
	return sum(path)
	

if __name__ == '__main__':
	print main(sys.argv[1])
