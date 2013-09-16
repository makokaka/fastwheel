import sys
import bisect

maxn = sys.stdin.readline().strip()
nums = sys.stdin.readline().strip().split(',')

int_nums = [int(e) for e in nums]
sort_nums = sorted(int_nums)

def find_less(l, n):
	idx = bisect.bisect_left(l, n)
	if l[idx] > n:
		return idx - 1
	return idx

def find_nogreat(l, n):
	return bisect.bisect_right(l, n)

last_equal = True
buf = []
for k, i in enumerate(maxn):
	if last_equal:
		idx = find_less(sort_nums, int(i))
	else:
		idx = -1

	num = sort_nums[idx]
	if last_equal and k == len(maxn) - 1 and num == int(i):
		num = sort_nums[idx - 1]
	
	buf.append(num)
	if num != int(i):
		last_equal = False
print ''.join([str(e) for e in buf])