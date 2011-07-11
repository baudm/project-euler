
class LineSegment(object):

	def __init__(self, point1, point2):
		self.endpoints = [point1, point2]
		x1, y1 = point1
		x2, y2 = point2
		try:
			self.slope = (y2 - y1)/float(x2 - x1)
		except ZeroDivisionError:
			self.slope = None # Technically, this is infinity
			self.y_intercept = None
		else:
			self.y_intercept = y1 - self.slope*x1

	def intersects_zero_ray(self):
		"""
		Tests if LineSegment intersects the ray from (0, 0) to (+inf, 0)
		Basically, this is for the ray casting algorithm
		"""
		x_bounds = [self.endpoints[0][0], self.endpoints[1][0]]
		x_bounds.sort()
		y_bounds = [self.endpoints[0][1], self.endpoints[1][1]]
		y_bounds.sort()
		# If the y-values of the line segment do not include 0, or if both the
		# x bounds are less than zero, then there's no intersection
		if (not y_bounds[0] <= 0 <= y_bounds[1]) or (x_bounds[0] < 0 and x_bounds[1] < 0):
			return False
		if self.slope is not None:
			try:
				x = -self.y_intercept/self.slope
			except ZeroDivisionError:
				return False
			return (0 <= x <= x_bounds[1])
		# Vertical line
		elif self.endpoints[0][0] < 0:
			return False


def main():
	count = 0
	with open('triangles.txt', 'r') as f:
		for line in f:
			Ax, Ay, Bx, By, Cx, Cy = map(int, line.split(','))
			triangle = [
				LineSegment((Ax, Ay), (Bx, By)),
				LineSegment((Ax, Ay), (Cx, Cy)),
				LineSegment((Bx, By), (Cx, Cy))
			]
			crossings = 0
			for segment in triangle:
				if segment.intersects_zero_ray():
					crossings += 1
			if crossings % 2 == 1:
				count += 1
	print count


if __name__ == '__main__':
	main()
