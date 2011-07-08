
def accumulate(data, x, y):
	try:
		bottom = data[y + 1][x]
	except IndexError:
		bottom = None
	try:
		right = data[y][x + 1]
	except IndexError:
		right = None
	# Choose right
	if bottom is None or (right is not None and right < bottom):
		data[y][x] += right
	else:
		data[y][x] += bottom


def main():
	data = []
	with open('matrix.txt', 'r') as f:
		for line in f:
			data.append(map(int, line.split(',')))
	# Bottom triangle
	#    /|
	#   / |
	#  /  |
	# ----+
	for d in range(len(data) - 2, -1, -1):
		y = len(data) - 1
		for x in range(d, len(data)):
			accumulate(data, x, y)
			y -= 1
	# Upper triangle
	# +----
	# |  /
	# | /
	# |/
	for d in range(len(data) - 2, -1, -1):
		x = 0
		for y in range(d, -1, -1):
			accumulate(data, x, y)
			x += 1

	print data[0][0]


if __name__ == '__main__':
	main()
