# Boyer-Moore Search 
1. Construct a "bad match table" [preprocessing]
2. This table never has elements smaller than 1
3. Keep comparing the pattern to the text starting from the rightmost char in the pattern
4. When mismatch occurs we have to shift the pattern to the right corresponding to the value in the bad match table
	** Why to do so? ** 
Because we can skip several char unlike brute-force search

** Bad Match Table **
1. Make a table of characters 
2. Table does not contain repetative characters
3. formula : max(1, len(pattern) - actualIndex - 1)
4. We iterate over the pattern and compute the values to the bad match table