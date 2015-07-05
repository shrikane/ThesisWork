package edu.umbc.cs.index;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Random;
import java.util.Set;

import edu.umbc.cs.analysis.Analyzer;
import edu.umbc.cs.analysis.CharNGramAnalyzer;
import edu.umbc.cs.analysis.TokenNGramAnalyzer;
import edu.umbc.cs.scoring.InverseDocumentFrequency;
import edu.umbc.cs.scoring.NormalizedTermFrequencyScoring;
import edu.umbc.cs.scoring.ScoringSchema;
import edu.umbc.cs.scoring.TermFrequencyScoring;
import edu.umbc.cs.similarity.ChiSquare;
import edu.umbc.cs.similarity.CosineSimilarity;
import edu.umbc.cs.similarity.ISimilarity;
import edu.umbc.cs.similarity.MinMax;
import edu.umbc.cs.similarity.klDivergence;
import edu.umbc.cs.utils.AuthorIDMapping;
import edu.umbc.cs.utils.Document;

public class IndexBuilder {

	FileWriter fw;
	
	public IndexBuilder(String FIlePath) throws IOException {
fw = new FileWriter(FIlePath);
	}

	private Map<Integer, Document> profile;

	/**
	 * Builds set as per authors and returns grouped authors
	 * 
	 * @param corpus
	 * @return
	 */
	private HashMap<Integer, Set<Document>> buildSet(List<Document> corpus) {
		HashMap<Integer, Set<Document>> set = new HashMap<Integer, Set<Document>>();
		for (Document document : corpus) {
			Set<Document> docs = set.get(document.getAuthorId());
			if (docs == null) {
				docs = new HashSet<Document>();
				docs.add(document);
			}
			docs.add(document);
			set.put(document.getAuthorId(), docs);
		}

		return set;
	}

	public Map<Integer, Document> buildProfile(List<Document> trainingDataSet,ScoringSchema score) {
		Map<Integer, Set<Document>> set = buildSet(trainingDataSet);
		// System.out.println(set);
		Map<Integer, Document> profiles = new HashMap<Integer, Document>();
		for (Entry<Integer, Set<Document>> e : set.entrySet()) {

			List<Document> docs = new ArrayList<Document>();
			docs.addAll(e.getValue());
			int vectorSize = docs.get(0).getFeatureVector().length;
			float[] vector = new float[vectorSize];
			int vectorIndex = 0;
		/*	Map<String,Float> scoredTerms = new HashMap<String, Float>();
			for (Document d : docs) {
				scoredTerms.putAll(d.getScoredTerms());
			}
			*/
			
			//System.out.println("Size"+scoredTerms.size()+","+score.getDict().size());
			for (int i = 0; i < vectorSize; i++) {
				for (int j = 0; j < docs.size(); j++) {
					double currentValue = docs.get(j).getFeatureVector()[vectorIndex];
					vector[vectorIndex] += currentValue;
					// System.out.println(currentValue);
				}
				// System.out.println("next index"+vector[vectorIndex]);
				vector[vectorIndex] = vector[vectorIndex] / docs.size();
				vectorIndex++;

			}
			
			
		
			
			
			
			
			
			
			Document d = new Document();
			d.setFeatureVector(vector);
			d.setAuthorId(e.getKey());
			//d.setScoredTerms(scoredTerms);
			profiles.put(e.getKey(), d);
		}
		return profiles;
	}

	void getTrainingANDTESTInstance(List<Document> corpus,
		final List<Document> train, final List<Document> test) {

		Map<Integer, Set<Document>> set = buildSet(corpus);
		Random r = new Random();
		for (Integer authorId : set.keySet()) {
			List<Document> docs = new ArrayList<Document>();
			docs.addAll(set.get(authorId));
			// List<Document> docs = ;
			int testSize = (int) (docs.size() * 0.2);
			for (int j = 0; j < testSize; j++) {
				int id = r.nextInt(docs.size());
				test.add(docs.get(id));
				docs.remove(id);
			}

			for (Document document : docs) {
				train.add(document);
			}

		}

	}

	public double buildIndex(List<Document> corpus,ScoringSchema score, Analyzer analyzer,
			ISimilarity similarityMeasure) throws IOException {
		


		List<Document> train = new ArrayList<Document>();
		List<Document> test = new ArrayList<Document>();
		getTrainingANDTESTInstance(corpus, train, test);
		
		for (Document document : corpus) {
			Map<String, Float> terms = document.getScoredTerms();
			terms.clear();
			document.setScoredTerms(terms);
		}
		
		
		
		
		profile = buildProfile(train,score);

		int correct = 0;
		int tot = 0;
		for (Document document : test) {
			int authId = similarityMeasure.getAuthId(profile, document);
			tot++;
			// System.out.println("Expeted: "+document.getAuthorId()+" Actual: "+authId+" FileName: "+document.getDocName());
			if (authId == document.getAuthorId())
				correct++;
		}
		double p = (double) (((double) correct / (double) tot) * 100);
		// System.out.println("Size: "+analyzer.getTokenSize());
		// System.out.println("correct: " +p );
		return p;

	}
	
	public double[] buildReport(IndexBuilder ibx,List<Document> corpus,ScoringSchema score ,Analyzer analyzer,ISimilarity similarity,int foldValidation,int startIndex,int endIndex) throws IOException{
		double [] accStrore = new double[endIndex];
		int k=0;
		for (int i = startIndex; i < endIndex; i++) {
			analyzer.setTokenSize(i);
			double acc = 0.0;
			
			corpus = score.getScoredDocs(corpus, analyzer);
			//score.getTFIDF(corpus, analyzer);

			for (Document document : corpus) {
				document.setFeatureVector(score.getFeatureVector(document
						.getScoredTerms()));

			}
			
			
			for (int j = 0; j < foldValidation; j++) {
				
				acc += ibx.buildIndex(corpus,score, analyzer,
						similarity);
			}
			accStrore[k++] = acc / foldValidation;
			System.out.println("acc: " +acc / foldValidation  + " tokSize: "
					+ i);
		}
       return accStrore;
	}
	
	
	
	void printAccuracy(double charAcc[],double[] tokenAcc) throws IOException{
		for(int i=0;i<charAcc.length;i++){
			String out = (i+1)+","+charAcc[i]+","+tokenAcc[i];
			System.out.println(out);
			fw.append(out);
			fw.flush();
		}
	}

	void buildSimilarity(IndexBuilder ibx,List<Document> corpus,ISimilarity similarity,int foldValidation,int startIndex,int endIndex) throws IOException{
	
		ScoringSchema score = new NormalizedTermFrequencyScoring();
		String out = "Scoring: Normalized TF,,";
		System.out.println(out);
		fw.append(out);
		fw.flush();
		double charAcc [] =  ibx.buildReport(ibx, corpus, score, new CharNGramAnalyzer(), similarity, foldValidation, startIndex, endIndex);
		double[] tokenAcc = ibx.buildReport(ibx, corpus, score, new TokenNGramAnalyzer(), similarity, foldValidation, startIndex, endIndex);
		printAccuracy(charAcc, tokenAcc);
		
		out = "Scoring: raw TF,,";
		System.out.println(out);
		fw.append(out);
		fw.flush();
		//System.out.println(");
	    score = new TermFrequencyScoring();
	    charAcc   = ibx.buildReport(ibx, corpus, score, new CharNGramAnalyzer(), similarity, foldValidation, startIndex, endIndex);
	    tokenAcc =  ibx.buildReport(ibx, corpus, score, new TokenNGramAnalyzer(), similarity, foldValidation, startIndex, endIndex);
		printAccuracy(charAcc, tokenAcc);
		
		
		out = "Scoring:  TF-IDF,,";
		System.out.println(out);
		fw.append(out);
		fw.flush();
		score = new InverseDocumentFrequency();
		charAcc  = ibx.buildReport(ibx, corpus, score, new CharNGramAnalyzer(), similarity, foldValidation, startIndex, endIndex);
		tokenAcc = ibx.buildReport(ibx, corpus, score, new TokenNGramAnalyzer(), similarity, foldValidation, startIndex, endIndex);
		printAccuracy(charAcc, tokenAcc);
	}
	

	public static void main(String[] args) throws IOException {
		System.out.println("Main");
		IndexBuilder ibx = new IndexBuilder(args[1]);
		AuthorIDMapping authorMapping = new AuthorIDMapping();
		authorMapping.getLables(args[0]);
		
		List<Document> corpus = DocumentHelper.getDocs(args[0],
				authorMapping);
		int startIndex =1;
		int endIndex =6;
		int foldValidation = 10;
		
		ISimilarity similarity = new klDivergence();
		//System.out.println("Similarity Measure: K-L divergance,,");
		String out = "Similarity Measure: K-L divergance,,";
		System.out.println(out);
		ibx.fw.append(out);
		ibx.fw.flush();
		ibx.buildSimilarity(ibx, corpus, similarity, foldValidation, startIndex, endIndex);
		
		similarity = new ChiSquare();
		//System.out.println("Similarity Measure: ChiSquare,,");
		 out = "Similarity Measure: Chi-Square,,";
		System.out.println(out);
		ibx.fw.append(out);
		ibx.fw.flush();
		
		ibx.buildSimilarity(ibx, corpus, similarity, foldValidation, startIndex, endIndex);
		
		
		out = "Similarity Measure: Min-Max,,";
		System.out.println(out);
		ibx.fw.append(out);
		ibx.fw.flush();
		similarity = new MinMax();
		//System.out.println("Similarity Measure: min-Max,,");
		ibx.buildSimilarity(ibx, corpus, similarity, foldValidation, startIndex, endIndex);
		
		similarity = new CosineSimilarity();
		
		out = "Similarity Measure: cosine,,";
		System.out.println(out);
		ibx.fw.append(out);
		ibx.fw.flush();
		//System.out.println("Similarity Measure: Cosine,,");
		ibx.buildSimilarity(ibx, corpus, similarity, foldValidation, startIndex, endIndex);
		System.out.println("Done");
		
		
		/*
		for (int i = 6; i < 8; i++) {
			double acc = 0.0;
			for (int j = 0; j < foldValidation; j++) {
				acc += ibx.buildIndex(corpus,score, new CharNGramAnalyzer(i),
						similarity);
			}
			System.out.println("acc: " + acc / foldValidation + " tokSize: "
					+ i);
		}*/

	
	}
}
