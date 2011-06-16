import sys


def main(fname):
	data = []
	with open(fname, 'r') as f:
		for line in f:
			data.append(map(int, line.split()))

	for r in range(len(data) - 2, -1, -1):
		for i in range(len(data[r])):
			left = data[r + 1][i]
			right = data[r + 1][i + 1]
			if left > right:
				data[r][i] += left
			else:
				data[r][i] += right
	return data[0][0]


if __name__ == '__main__':
	print main(sys.argv[1])
