# Knuth-Morris-Pratt Algorithm (KMP) <br>

It uses a pre-generated table called a prefix table. [Dynamic Prog]<br>
A prefix table will allow us to skip certain comparisons.<br>
Check out the following example<br>

![img2](https://user-images.githubusercontent.com/71068960/153889904-30113a31-585b-4460-9289-01b47b33839e.png)


The key to KMP algorithms lies in the prefix table.<br>
<strong> Proper prefix </strong>: <br>
All the characters in a string with one or more cut off the end.<br>
'a', 'ab', 'abc' are all proper prefixes of the string 'abcdefg'<br>

<strong> Proper suffix </strong> : <br>
All the characters in a string, with one or more cut off the begining.<br>
'g', 'fg', 'efg', etc. are  proper suffixes of the string 'abcdefg'<br>

<strong> Prefix Table </strong> :<br>
The values in the prefix table are the length of longest prefix that matches a proper suffix in the same subpattern<br>
eg: subpattern = "aba", the value in table = 1 {only one char can be considered to have prefix == suffix} <br>
eg: subpattern = "abcab", table value = 2 <br>
![img1](https://user-images.githubusercontent.com/71068960/153889929-dd5c6489-e28f-4b26-be60-da2f8fd51125.gif)


# KMP Prefix Table psuedocode <br>
```
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
```
# Time Complexities: 	
<strong> Worst </strong> : O(n + m) <br> 
&emsp;	m is len(pattern) <br> 
&emsp;	n is len(text) <br> 
<strong> Best </strong> : O(n + m) <br> 
&emsp;	m is complexity of precomputation of prefix table <br> 
&emsp;	n is complexity of matching <br> 
