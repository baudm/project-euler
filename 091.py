import itertools


def get_length_squared(point1, point2):
	x_diff = point1[0] - point2[0]
	y_diff = point1[1] - point2[1]
	return x_diff*x_diff + y_diff*y_diff


def main():
	ORIGIN = (0, 0)
	# Generate all points from 0 <= x,y <= 50
	points = list(itertools.product(range(51), range(51)))
	# Remove the origin from the set of points because it'll be added later
	# (All right triangles to be counted have one vertex at the origin)
	points.remove(ORIGIN)
	count = 0
	# For all line segments that can be formed using the set of points
	# generated earlier...
	for segment in itertools.combinations(points, 2):
		# add another point, the origin, so it'll form a triangle
		triangle = segment + (ORIGIN, )
		lengths = []
		# then calculate the length squared of each side.
		for side in itertools.combinations(triangle, 2):
			lengths.append(get_length_squared(*side))
		lengths.sort()
		# This is a right triangle if a^2 + b^2 == c^2
		if lengths[0] + lengths[1] == lengths[2]:
			count += 1
	print count


if __name__ == '__main__':
	main()
