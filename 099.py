import math

with open('base_exp.txt', 'r') as f:
	max_base, max_exp = map(int, f.readline().split(','))
	max_line_num = 1
	line_num = 1
	for line in f:
		line_num += 1
		base, exp = map(int, line.split(','))
		# Get the exponent of base^exp if base is expressed in terms of max_base
		# i.e. base^exp == max_base^comp_exp
		comp_exp = exp * math.log(base, max_base)
		# Now that the two numbers are expressed in the same base,
		# only their exponents need to be compared.
		if comp_exp > max_exp:
			max_exp = exp
			max_base = base
			max_line_num = line_num

print max_line_num
