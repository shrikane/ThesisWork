package edu.umbc.cs.similarity;

public class ChiSquare {

	public static double getScore(double[] input,double[] test){
		if(input.length != test.length ){
			throw new IllegalArgumentException(
					"Both vectors must have same size");
		}else{
			double score =0.0;
			for(int i=0;i<input.length;i++){
				double numarator =  Math.pow(Math.abs(input[i] - test[i]) -0.5, 2)   ;  
				score += numarator/input[i];
			}
			return score;
		}
	}

	
	
	
	public static void main(String[] args) {
		
	}
}
