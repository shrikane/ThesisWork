package edu.umbc.cs.analysis;

import java.util.ArrayList;
import java.util.List;

public class CharNGramAnalyzer extends Analyzer {

	public CharNGramAnalyzer() {
		// TODO Auto-generated constructor stub
	}

	public CharNGramAnalyzer(int size) {
		super(size);
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
		final List<String> ret = new ArrayList<String>();
		final int maxStartIndex = text.length() - tokenSize + 1;
		for (int i = 0; i < maxStartIndex; i++)
			ret.add(text.substring(i, i + tokenSize));
		return ret;
	}

}
