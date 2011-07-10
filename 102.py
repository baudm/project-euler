
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

	def get_perpendicular_slope(self):
		if self.slope is None:
			m = 0
		elif self.slope:
			m = -1/self.slope
		else:
			m = None
		return m

	def get_intersection(self, m, point):
		if self.slope != m:
			if self.slope is not None and m is not None:
				b = point[1] - m*point[0]
				x = (b - self.y_intercept)/(self.slope - m)
				y = self.slope*x + self.y_intercept
			elif self.slope is None:
				x = self.endpoints[0][0]
				y = point[1]
			else:
				x = point[0]
				y = self.slope*x + self.y_intercept
		else:
			x = y = None
		return x, y

	def contains_point(self, point):
		x_bounds = [self.endpoints[0][0], self.endpoints[1][0]]
		y_bounds = [self.endpoints[0][1], self.endpoints[1][1]]
		x_bounds.sort()
		y_bounds.sort()
		x, y = point
		return (x_bounds[0] <= x <= x_bounds[1]) and (y_bounds[0] <= y <= y_bounds[1])


def swap(lower, upper):
	if lower > upper:
		tmp = lower
		lower = upper
		upper = tmp
	return lower, upper


class Line(object):
	
	def __init__(self, slope, intercept):
		self.slope = slope
		self.y_intercept = intercept
	
	def intersects(self, line_segment):
		if line_segment.slope is not None:
			x = (self.y_intercept - line_segment.y_intercept)/(line_segment.slope - self.slope)
			y = self.slope*x + self.y_intercept
			x_lower, y_lower = line_segment.point1
			x_upper, y_upper = line_segment.point2
			# Make sure that the lower and upper limits are correct
			x_lower, x_upper = swap(x_lower, x_upper)
			y_lower, y_upper = swap(y_lower, y_upper)
			return (x_lower <= x <= x_upper) and (y_lower <= y <= y_upper)
		else:
			pass
			


def get_perpendicular_line(slope, point):
	# The slope of the perpendicular line is the
	# negative reciprocal of the slope
	x, y = point
	if slope is not None:
		m = -1/slope
	else:
		m = 0
	b = y - m*x
	return Line(m, b)


def main():
	count = 0
	with open('triangles.txt', 'r') as f:
		for line in f:
			Ax, Ay, Bx, By, Cx, Cy = map(int, line.split(','))
			AB = LineSegment((Ax, Ay), (Bx, By))
			AC = LineSegment((Ax, Ay), (Cx, Cy))
			BC = LineSegment((Bx, By), (Cx, Cy))
			# get the slope of all lines perpedicular to AB
			p_slope = AB.get_perpendicular_slope()
			# Get the intersection of AB and the perpedicular line to AB passing through (0, 0)
			# Let's call this line AB'
			x1, y1 = AB.get_intersection(p_slope, (0, 0))
			x2, y2 = AC.get_intersection(p_slope, (0, 0))
			# If AC and AB' do not intersect, try BC
			if x2 is None:
				x2, y2 = BC.get_intersection(p_slope, (0, 0))
			# Get the line segment of AB' within the triangle
			segment = LineSegment((x1, y1), (x2, y2))
			if segment.contains_point((0, 0)):
				print Ax, Ay, Bx, By, Cx, Cy
				count += 1
	print count
	
if __name__ == '__main__':
	main()
