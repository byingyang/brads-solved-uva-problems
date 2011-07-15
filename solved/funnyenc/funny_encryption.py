from sys import stdin
def binary_encrypt(num):
	count = 0
	while(num):
		count += num & 0x01
		num >>= 1
	return count
	
def hex_encrypt(num):
	count = 0
	for d in num: count += binary_encrypt(int(d))
	return count

for s in stdin.read().split('\n')[1:-1]: print "%s %s" % (binary_encrypt(int(s)), hex_encrypt(s))