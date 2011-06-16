

# From: http://code.activestate.com/recipes/577542-pascals-triangle/
def pascals_triangle(n):
    x=[[1]]
    for i in range(n-1):
        x.append(list(map(sum,zip([0]+x[-1],x[-1]+[0]))))
    # HACK: only last row is needed
    return x.pop()


def get_num_routes(n):
	# Get the corresponding Pascal's triangle row number
	row_num = 2*n + 1
	row = pascals_triangle(row_num)
	# Return the middle term
	return row[len(row)/2]


if __name__ == '__main__':
	# n = 20 for 20x20 grid
	print get_num_routes(20)
