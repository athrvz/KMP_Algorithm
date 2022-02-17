import java.util.*;

public class boyer_moore {
	private static void precomputeShifts(String patt, HashMap <Character, Integer> mistmatchTable) {
		int len = patt.length();
		for(int i = 0; i < len; i++) {
			char currChar = patt.charAt(i);
			int shift = Math.max(1, len - 1 - i);
			mistmatchTable.put(currChar, shift);
		}
	}

	private static int doBoyerMoore(String txt, String patt, HashMap <Character, Integer> mistmatchTable) {
		int skips = 0;
		for(int i = 0; i < txt.length() - patt.length(); i += skips) {
			skips = 0;
			for(int j = patt.length() - 1; j >= 0; j--) {
				if(patt.charAt(j) != txt.charAt(i + j)) {
					if(mistmatchTable.get(txt.charAt(i + j)) != null) {
						skips = mistmatchTable.get(txt.charAt(i + j));
						break;
					} else {
						skips = patt.length();
						break;
					}
				}
			}
			if(skips == 0) return i;
		}
		return -1;
	}

	public static void main(String [] args) {
		String text = "ABCABABCABAC";
	    	String pattern = "CAB";
	    	HashMap <Character, Integer> mistmatchTable = new HashMap <> ();
	    	precomputeShifts(pattern, mistmatchTable);
    		System.out.println("pattern found at: " + doBoyerMoore(text, pattern, mistmatchTable));
	}
}
