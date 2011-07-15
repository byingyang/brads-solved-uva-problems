for x in range(int(raw_input())):
	s = raw_input()
	rev = "a"
	res = "b"
	numIterations = 0
	while(s != s[::-1] or numIterations == 0):
		s = str(int(s) + int(s[::-1]))
		numIterations += 1
	print "%s %s" % (numIterations, s)