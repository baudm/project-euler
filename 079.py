
def swap(vector, i, j):
	tmp = vector[i]
	vector[i] = vector[j]
	vector[j] = tmp


def main():
	passcode = []
	with open('keylog.txt', 'r') as f:
		for line in f:
			triple = tuple(map(int, line.strip()))
			# Integrate new data, i.e. current line, to the passcode data
			prev = []
			for digit in triple:
				if digit not in passcode:
					prev.append(digit)
				elif prev:
					i = passcode.index(digit)
					passcode.insert(i, prev.pop(0))
			passcode.extend(prev)
			# Sort the passcode data according to the ordering of elements of the triple
			# Basically, swap the passcode digits so that the positions are ascending.
			pos = map(passcode.index, triple)
			for i in range(0, 2):
				if pos[i] > pos[i + 1]:
					# Swap the passcode digits themselves
					swap(passcode, pos[i], pos[i + 1])
					# Then swap their indices in the positions list
					swap(pos, i, i + 1)
	print ''.join(map(str, passcode))


if __name__ == '__main__':
	main()
