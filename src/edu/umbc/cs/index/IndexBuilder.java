package edu.umbc.cs.index;

import java.io.IOException;
import java.util.*;
import java.util.Map.Entry;

import sun.applet.Main;
import edu.umbc.cs.analysis.Analyzer;
import edu.umbc.cs.analysis.CharNGramAnalyzer;
import edu.umbc.cs.analysis.TokenNGramAnalyzer;
import edu.umbc.cs.scoring.DocumentScore;
import edu.umbc.cs.similarity.ChiSquare;
import edu.umbc.cs.similarity.CosineSimilarity;
import edu.umbc.cs.similarity.ISimilarity;
import edu.umbc.cs.similarity.Scap;
import edu.umbc.cs.utils.AuthorIDMapping;
import edu.umbc.cs.utils.Document;

public class IndexBuilder {

	public IndexBuilder() {

	}
	
	private Map<Integer,Document> profile;
	
	/**
	 * Builds set as per authors and returns grouped authors
	 * @param corpus
	 * @return
	 */
	private HashMap<Integer, Set<Document>> buildSet(List<Document> corpus){
		HashMap<Integer, Set<Document>> set = new HashMap<Integer, Set<Document>>();
		for (Document document : corpus) {
			 Set<Document> docs = set.get(document.getAuthorId());
			 if(docs == null){
				 docs = new HashSet<Document>();
				 docs.add(document);
			 }		 
			 docs.add(document);
			 set.put(document.getAuthorId(), docs);
		}
	
		return set;
	}
	
	
	public Map<Integer,Document> buildProfile(List<Document> trainingDataSet){
		Map<Integer, Set<Document>> set = buildSet(trainingDataSet);
		//System.out.println(set);
		Map<Integer,Document> profiles = new HashMap<Integer, Document>();
		for (Entry<Integer, Set<Document>> e : set.entrySet()) {
		
			List<Document> docs = new ArrayList<Document>();
			docs.addAll(e.getValue());
			int vectorSize = docs.get(0).getFeatureVector().length;
			double [] vector = new double[vectorSize];
			int vectorIndex =0;
			for(int i=0;i<vectorSize;i++){
				for(int j=0;j<docs.size();j++){
					double currentValue = docs.get(j).getFeatureVector()[vectorIndex];
					vector[vectorIndex] +=currentValue;
				//	System.out.println(currentValue);
				}
				//System.out.println("next index"+vector[vectorIndex]);
				vector[vectorIndex] = vector[vectorIndex] / docs.size();
				vectorIndex++;
				
			}
			Document d = new Document();
			d.setFeatureVector(vector);
			d.setAuthorId(e.getKey());
			profiles.put(e.getKey(), d );
		}
		return profiles;
	}
	
	
	void getTrainingANDTESTInstance(List<Document> corpus,final List<Document> train,final List<Document> test){
		
		Map<Integer, Set<Document>> set = buildSet(corpus);
		Random r = new Random();
		for (Integer authorId : set.keySet()) {
			List<Document> docs = new ArrayList<Document>();
			docs.addAll(set.get(authorId));
			//List<Document> docs = ;
			int testSize = (int) (docs.size() * 0.2);
			for(int j=0;j<testSize;j++){
				int id = r.nextInt(docs.size());
				test.add(docs.get(id));
				docs.remove(id);
			}
			
			for (Document document : docs) {
				train.add(document);
			}

		}

	}
	
	

	public void buildIndex(String dataDirPath) throws IOException {
		AuthorIDMapping authorMapping = new AuthorIDMapping();
		authorMapping.getLables(dataDirPath);
		List<Document> corpus = DocumentHelper.getDocs(dataDirPath,
				authorMapping);
		int size = 3;
		Analyzer analyzer = new TokenNGramAnalyzer(size);
		DocumentScore score = new DocumentScore();
		for (Document document : corpus) {
			String text = document.getRawText();
			List<String> tokens = analyzer.getTokens(text);
			Map<String, Double> scoredDoc = score.getRawTF(tokens);
			document.setScoredTerms(scoredDoc);
		}

		for (Document document : corpus) {
			document.setFeatureVector(score.getFeatureVector(document.getScoredTerms()));
			
		}
		List<Document> train = new ArrayList<Document>();
		List<Document> test = new ArrayList<Document>();
		getTrainingANDTESTInstance(corpus,train,test);
		
		/*
		for (Document document : train) {
			System.out.println(document);
			for (double d : document.getFeatureVector()) {
				System.out.print(d+"\t");
			}
			System.out.println();
		}*/
		
		profile = buildProfile(train);
	/*	for (Entry<Integer, Document> e : profile.entrySet()) {
			double[] x = e.getValue().getFeatureVector();
			for (double d : x) {
				System.out.print(d+"\t");
			}
			System.out.println();
		}*/
		
		ISimilarity similarityMeasure = new ChiSquare();
		int correct=0;
		int tot=0;
		for (Document document : test) {
			int authId = getAuthId(similarityMeasure,document);
			tot++;
			System.out.println("Expeted: "+document.getAuthorId()+" Actual: "+authId+" FileName: "+document.getDocName());
			if(authId == document.getAuthorId())   correct++; 

			
			
		}
		double p = (double)(((double)correct/(double)tot)*100);
		System.out.println("correct: " +p );
		
	}
	
	
	public int getAuthId(ISimilarity similarityMeasure,Document test){
		double minScore = Double.MAX_VALUE;
		int authId = 0;
		if(profile == null){
			throw new IllegalStateException("No profiles found");
		}else{
			
			for (Entry<Integer, Document> e : profile.entrySet()) {
			//	System.out.println(e.getValue());
				double score = similarityMeasure.getScore(e.getValue(), test);
			//	System.out.println(score);
				if(score < minScore){
					authId = e.getKey();
					minScore = score;
				}
			}
		}
		return authId;
	}
	
	
		
		
	


	public static void main(String[] args) throws IOException {
		IndexBuilder ibx = new IndexBuilder();
		ibx.buildIndex(args[0]);
	}
}
