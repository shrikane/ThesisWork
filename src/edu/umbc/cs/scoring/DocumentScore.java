package edu.umbc.cs.scoring;

import java.util.*;
import java.util.Map.Entry;

public class DocumentScore {
	
	private Map<String,Double> dict ;

	public Map<String, Double> getDict() {
		return dict;
	}

	public DocumentScore() {
		dict = new HashMap<String,Double>();
	}
	
	
	public double[] getFeatureVector(Map<String,Double> data){
		double[] vector = new double[dict.size()];
		int vectorIndex =0;
			for (String term : dict.keySet()) {
				Double score = data.get(term);
				if(score == null){
					vector[vectorIndex++] = 0.01;
				}else{
					vector[vectorIndex++] = score+0.01;
				}
			}
		
		return vector;
	}
	
	
	
	public Map<String,Double> getRawTF(List<String> data){
		Map<String,Double> docTF = new HashMap<String,Double>();
		for (String string : data) {
			docTF = addTodict(string,docTF);
			dict = addTodict(string,dict);
		}
		return docTF;
	}
	
	public Map<String,Double> getNormalizedTF(List<String> data){
		Map<String,Double> docTF = getRawTF( data);
		Map<String,Double> normalizedTF = new HashMap<String,Double>();
		for (Entry<String, Double> e : docTF.entrySet()) {
			normalizedTF.put(e.getKey(), e.getValue()/docTF.size());
		}
		return normalizedTF;
	}

	private Map<String, Double> addTodict(String string,Map<String,Double> data) {
		if(data.containsKey(string)){
			double freq = data.get(string);
			data.put(string, freq+1);
		}else{
			data.put(string, 1.0);
		}
		return data;
	}
	
	
	public List<Map<String, Double>> getTFIDF(List<List<String>> coupus){
		List<Map<String, Double>>  tf = new ArrayList<Map<String, Double>>();
		for (List<String> doc : coupus) {
			Map<String,Double> normalizedTF = getRawTF(doc);
			tf.add(normalizedTF);
		}
		List<Map<String, Double>>  tfIdf = new ArrayList<Map<String, Double>>();
		for (Map<String, Double> map : tf) {
			Map<String,Double> normalizedTFIDF = new HashMap<String,Double>();
			for (Entry<String, Double> e : map.entrySet()) {
				double val = e.getValue() *( Math.log(dict.size()/dict.get(e.getKey()))/Math.log(2))-1;
				//System.out.println(e.getKey()+","+val+","+e.getValue());
				normalizedTFIDF.put(e.getKey(), val);	
			}
			tfIdf.add(normalizedTFIDF);
		}	
		return tfIdf;
	}
	
	/*
	public static void main(String[] args) {
		List<String> p = Arrays.asList("new", "york", "times");
		List<String> p1 = Arrays.asList("new", "york", "post");
		List<String> p2 = Arrays.asList("los", "angeles", "times");
		List<List<String>> coupus = new ArrayList<List<String>>();
		coupus.add(p);
		coupus.add(p1);
		coupus.add(p2);
		
		DocumentScore d= new DocumentScore();
		List<Map<String, Double>> docTF =d.getTFIDF(coupus);
		for (Map<String, Double> map : docTF) {
			System.out.println(map);
		}
		
	}*/

}
