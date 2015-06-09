package edu.umbc.cs.analysis;

import java.util.*;

public abstract class Analyzer {

	
	protected int tokenSize;
	
	protected Analyzer() {
		
	}
	
	protected Analyzer(int size) {
		tokenSize= size;
	}

	public abstract List<String> getTokens(String text);

	public int getTokenSize() {
		return tokenSize;
	}
	public void setTokenSize(int tokenSize) {
		this.tokenSize = tokenSize;
	}

}
