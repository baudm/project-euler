import operator

VALUES = dict(zip('23456789TJQKA', range(2, 15)))

# --------- Helper Functions ---------

def _count_values(values):
	distinct = set(values)
	counts = map(values.count, distinct)
	return dict(zip(distinct, counts))

def get_values(hand, groups_of=1):
	g = operator.itemgetter(0)
	values = map(VALUES.get, map(g, hand))
	counts = _count_values(values)
	return filter(lambda v: counts[v] == groups_of, counts)


# ------------------ Tests ------------------

def highest_card(values):
	ret = max(values)
	values.remove(ret)
	return ret

def one_pair(hand):
	pairs = get_values(hand, 2)
	return pairs[0] if len(pairs) == 1 else 0

def two_pairs(hand):
	pairs = get_values(hand, 2)
	return max(pairs) if len(pairs) == 2 else 0

def three_of_a_kind(hand):
	triple = get_values(hand, 3)
	return triple[0] if triple else 0

def straight(hand):
	values = get_values(hand)
	if len(values) != 5:
		return 0
	values.sort()
	if values[0] + 4 == values[4]:
		return values[4]
	else:
		return 0

def flush(hand):
	g = operator.itemgetter(1)
	suites = set(map(g, hand))
	return 1 if len(suites) == 1 else 0

def full_house(hand):
	pair = get_values(hand, 2)
	triple = get_values(hand, 3)
	if pair and triple:
		return triple[0]
	else:
		return 0

def four_of_a_kind(hand):
	four = get_values(hand, 4)
	return four[0] if four else 0

def straight_flush(hand):
	if not flush(hand):
		return 0
	return straight(hand)

def royal_flush(hand):
	# ace is the highest card in a royal flush
	return 1 if straight_flush(hand) == VALUES['A'] else 0


def main():
	tests = (
		royal_flush, straight_flush, four_of_a_kind,
		full_house, flush, straight,
		three_of_a_kind, two_pairs, one_pair
	)
	wins = 0
	with open('poker.txt', 'r') as f:
		for line in f:
			cards = line.split()
			player1 = cards[:5]
			player2 = cards[5:]
			for test in tests:
				score1 = test(player1)
				score2 = test(player2)
				if score1 or score2:
					break
			if score1 > score2:
				wins += 1
			# Test for highest card
			elif score1 == score2:
				p1 = get_values(player1)
				p2 = get_values(player2)
				while score1 == score2:
					score1 = highest_card(p1)
					score2 = highest_card(p2)
				if score1 > score2:
					wins += 1
	print wins


if __name__ == '__main__':
	main()
