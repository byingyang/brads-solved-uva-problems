import sys

lines = sys.stdin.readlines()
for line in lines:
	arr = [int(x) for x in line.split()]
	colors = ['B', 'G', 'C']
	bins = [dict((colors[i % 3], arr[i]) for i in range((x-3), x)) for x in range(3, 12, 3)]
	final = {}
	for possibility in ['BGC', 'BCG', 'GBC', 'GCB', 'CGB', 'CBG']:
		final[possibility] = sum([sum([bins[i][x] for x in possibility if x != possibility[i]]) for i in range(3)])
	value = min(final.values())
	keys = [pair[0] for pair in final.items() if pair[1] == value]
	keys.sort()
	key = keys[0]
	print "%s %d" % (key, value)
