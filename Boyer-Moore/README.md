# Boyer-Moore Search 
1. Construct a "bad match table" [preprocessing]
2. This table never has elements smaller than 1
3. Keep comparing the pattern to the text starting from the rightmost char in the pattern
4. When mismatch occurs we have to shift the pattern to the right corresponding to the value in the bad match table <br>
	<strong> Why to do so? </strong> <br> 
Because we can skip several char unlike brute-force search

![boyerMooreStringSearch-2](https://user-images.githubusercontent.com/71068960/154730650-5a3cb0ff-2c6c-402c-84bd-0a5293272e6e.gif)

<strong> Bad Match Table </strong>
1. Make a table of characters 
2. Table does not contain repetative characters
3. formula : max(1, len(pattern) - actualIndex - 1)
4. We iterate over the pattern and compute the values to the bad match table
