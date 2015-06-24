package edu.umbc.cs.similarity;

import java.util.Set;

import edu.umbc.cs.utils.Document;

public class Scap implements ISimilarity {

	public Scap() {
		// TODO Auto-generated constructor stub
	}

	@Override
	public double getScore(Document input, Document test) {
		System.out.println(input.getScoredTerms());
		Set<String> inputSet = input.getScoredTerms().keySet();
		Set<String> testSet = test.getScoredTerms().keySet();
		inputSet.retainAll(testSet);
		return inputSet.size();
	}

}
