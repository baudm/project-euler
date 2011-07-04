import itertools

with open('cipher1.txt', 'r') as f:
	ciphertext = f.readline().split(',')
	ciphertext = map(int, ciphertext)

# Statistical distribution of the 4 most common letters in the English language
# source: http://www.data-compression.com/english.html
distrib = {'e': 0.1041442, 't': 0.0729357, 'a': 0.0651738, 'o': 0.0596302}

min_diff = 1.0
plaintext = None

for key in itertools.permutations(range(ord('a'), ord('z') + 1), 3):
	# Decode the ciphertext using the current key
	decoded = []
	for i in range(0, len(ciphertext)):
		d = ciphertext[i] ^ key[i % len(key)]
		decoded.append(d)

	# Compare the distribution of the letters to the actual letter distribution
	# in the English language.
	diffs = []
	for k, v in distrib.iteritems():
		count = decoded.count(ord(k)) + decoded.count(ord(k.upper()))
		percentage = float(count) / len(decoded)
		diff = abs(v - percentage) / v
		diffs.append(diff)
	ave_diff = sum(diffs) / len(diffs)

	# The key which produces the minimum difference must be the best key
	if ave_diff < min_diff:
		min_diff = ave_diff
		plaintext = decoded

print sum(plaintext)
