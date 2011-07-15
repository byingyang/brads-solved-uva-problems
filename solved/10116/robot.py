rows, cols, firstcol = [int(x) for x in raw_input().split()]
while(rows != 0):
	grid = [raw_input() for i in range(rows)]
	positions = {}
	curpos = [0, firstcol-1]
	nummoves = 0
	loopcount = 0
	operations = {'N': lambda x: [x[0] - 1, x[1]],
				  'S': lambda x: [x[0] + 1, x[1]],
				  'E': lambda x: [x[0], x[1] + 1],
				  'W': lambda x: [x[0], x[1] - 1]}
	while(curpos[0] >= 0 and curpos[0] < rows and curpos[1] >= 0 and curpos[1] < cols):
		key = "%d%d" % (curpos[0], curpos[1])
		if(positions.has_key(key)):
			val = positions[key]
			loopcount = nummoves - val
			nummoves -= loopcount
			break
		else:
			positions[key] = nummoves
			nummoves += 1
		curpos = operations[grid[curpos[0]][curpos[1]]](curpos)
	if(loopcount != 0):
		print "%d step(s) before a loop of %d step(s)" % (nummoves, loopcount)
	else:
		print "%d step(s) to exit" % nummoves
	rows, cols, firstcol = [int(x) for x in raw_input().split()]