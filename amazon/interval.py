#  1. input:
#[6,27] [5,7] [21,34] [13,25]
#output:
#[6,7] [13,27]

import sys
s = sys.stdin.readline().strip().split()
intvs = []
for strinterval in s:
	try:
		intv = eval(strinterval)
		intvs.append(intv)
	except Exception, e:
		print 'invalid'
		sys.exit(1)

a = intvs[0]

def union_intv(l):
	sort_l = sorted(l, key=lambda e: e[0])
	#print sort_l
	buf = []
	for intv in sort_l:
		m, n = intv
		if buf:
			i, j = buf[-1]
			if i < m < j:
				right = max(n, j)
				left  = i
				buf[-1] = [left, right]
			else:
				buf.append([m, n])
		else:
			buf.append(intv)
	return buf

b = union_intv(intvs[1:])
#print b

def intersect_intv(a, b):
	buf = []
	m, n = a
	for intv in b:
		i, j = intv
		if j < m:
			continue
		elif i <= m <= j:
			left, right = m, min(n, j)
			buf.append([left, right])
		elif m < i:
			if n < i:
				continue
			else:
				left, right = i, min(j, n)
				buf.append([left, right])
	#print buf
	buf = [str(e).replace(' ', '') for e in buf]
	return ' '.join(buf)

sys.stdout.write(intersect_intv(a, b))
