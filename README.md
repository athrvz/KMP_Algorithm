# Knuth-Morris-Pratt Algorithm (KMP)

It uses a pre-generated table called a prefix table. [Dynamic Prog]
A prefix table will allow us to skip certain comparisons.
Check out the following example
...........................

The key to KMP algorithms lies in the prefix table.
Proper prefix: 
All the characters in a string with one or more cut off the end.
'a', 'ab', 'abc' are all proper prefixes of the string 'abcdefg'

Proper suffix: 
All the characters in a string, with one or more cut off the begining.
'g', 'fg', 'efg', etc. are  proper suffixes of the string 'abcdefg'

Prefix Table:
The values in the prefix table are the length of longest prefix that matches a proper suffix in the same subpattern
eg: subpattern = "aba", the value in table = 1 {only one char can be considered to have prefix == suffix} 
eg: subpattern = "abcab", table value = 2


# KMP Prefix Table psuedocode
KMP_prefixTable(string p):
	n = len(p)
	prefTable[1] = 0 # 1 based indexing
	i = 0
	for j in range(2, n + 1):
		while i > 0 and p[i + 1] != p[j]:
			i = prefTable[i]
	if p[i + 1] = p[j]:
		i++
	prefTable[j] = i
	return prefTable

# Time Complexities: 	
Worst: O(n + m) 
	m is len(pattern)
	n is len(text)
Best: O(n + m)
	m is complexity of precomputation of prefix table
	n is complexity of matching
