package edu.umbc.cs.similarity;

import edu.umbc.cs.utils.Document;

public class ChiSquare implements ISimilarity {

	public double getScore(Document input,Document test){
		
		double [] authVector = input.getFeatureVector();
		double [] testVector = test.getFeatureVector();
		adjust(authVector, testVector);
		if(authVector.length != testVector.length ){
			throw new IllegalArgumentException(
					"Both vectors must have same size");
		}else{
			double score =0.0;
			for(int i=0;i<authVector.length;i++){
				double numarator =  Math.pow(Math.abs(authVector[i] - testVector[i] ) , 2)   ;  
			//System.out.println(numarator+","+authVector[i]);
				score += numarator/authVector[i];
			}
			return score;
		}
	}

	void adjust(final double[] vector1,final double[] vector2){
		double sum1 =0;
		double sum2 =0;
		for(int i=0;i<vector1.length;i++){
			sum1 += vector1[i];
			sum2 += vector2[i];
		}
		//System.out.println("sum1 "+sum1+" sum2 "+sum2);
		//System.out.println(sum1* sum2);
		double sum3 = sum2 / sum1;
		for(int i=0;i<vector1.length;i++){
			vector1[i] = (vector1[i]* sum3) * 100;
			//vector2[i] = (vector2[i]* sum3) ;
		}
	}
	
	
	public static void main(String[] args) {
		ChiSquare c = new ChiSquare();
		double[] auth = {10.0,10.0,15.0,20.0,30.0,15.0};
		
		double [] actual = {30.0,14.0,34.0,45.0,57.0,20.0};
		c.adjust(actual,auth);
		Document d1 = new Document();
		d1.setFeatureVector(auth);
		Document d2 = new Document();
		d2.setFeatureVector(actual);
		System.out.println(c.getScore(d1,d2));
	}
}
