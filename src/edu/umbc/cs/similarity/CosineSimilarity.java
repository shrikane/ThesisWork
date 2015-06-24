package edu.umbc.cs.similarity;

import edu.umbc.cs.utils.Document;

public class CosineSimilarity implements ISimilarity {

	public CosineSimilarity() {
		// TODO Auto-generated constructor stub
	}

	
	private double dotProduct(double[] vector1, double[] vector2){
		double dotProductValue=0.0;
		for(int i=0;i < vector1.length;i++){
			dotProductValue += vector1[i] * vector2[i];
		}
		return dotProductValue;
	}
	
	
	@Override
	public double getScore(Document input, Document test) {
		double [] authVector = input.getFeatureVector();
		double [] testVector = test.getFeatureVector();
		return  (dotProduct(authVector, testVector)) / (Math.sqrt(dotProduct(authVector, authVector)));
	}

}
