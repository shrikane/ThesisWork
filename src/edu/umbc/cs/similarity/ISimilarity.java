package edu.umbc.cs.similarity;

import edu.umbc.cs.utils.Document;

public interface ISimilarity {

	public double getScore(Document input,Document test);

}
