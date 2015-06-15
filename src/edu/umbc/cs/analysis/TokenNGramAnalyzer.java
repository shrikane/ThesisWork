package edu.umbc.cs.analysis;

import java.util.ArrayList;
import java.util.List;

public class TokenNGramAnalyzer extends Analyzer {

	public TokenNGramAnalyzer() {
		// TODO Auto-generated constructor stub
	}

	private String getList(int startIndex, int endIndex, String[] input) {
		StringBuffer bf = new StringBuffer();
		for (int i = startIndex; i < endIndex; i++)
			bf.append(input[i]);
		return bf.toString();
	}

	@Override
	public List<String> getTokens(String text) {
		if (tokenSize == 0) {
			throw new IllegalArgumentException(
					"N-Gram size need to be greater than 0 use setter method to set");
		}
		if (text == null) {
			throw new NullPointerException("Input can't be null");
		}
		List<String> nGramTokens = new ArrayList<String>();
		String[] tokens = text.split("(?=[\\s+;])");
		int maxStartIndex = tokens.length - tokenSize + 1;
		for (int i = 0; i < maxStartIndex; i++)
			nGramTokens.add(getList(i, i + tokenSize, tokens));
		return nGramTokens;
	}

}
