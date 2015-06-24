package edu.umbc.cs.utils;

import java.util.Map;

public class Document {

	String docName;
	int authorId;
	double [] featureVector;
	char[] rawText;
	Map<String, Double> scoredTerms;
	
	
	public Double getScore(String term){
		return scoredTerms.get(term);
	}

	public void setScoredTerms(Map<String, Double> scoredTerms) {
		this.scoredTerms = scoredTerms;
	}
	
	public Map<String, Double> getScoredTerms() {
		return scoredTerms;
	}
	

	public Document() {
		
	}
	
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		String tab = "\t";
		sb.append("FileName: "+ this.docName+tab);
		sb.append("Authod Id: "+this.authorId+tab);
	//	sb.append("Tok: "+ this.scoredTerms+tab );
		return sb.toString();
	}
	
	@Override
	public boolean equals(Object arg0) {
		Document d = (Document) arg0;
		return this.docName.equalsIgnoreCase(d.getDocName()) && this.authorId == d.getAuthorId();
	}
	
	
	
	public Document(String name,int author,char[] text) {
		docName = name;
		authorId = author;
		rawText = text;
	}

	public String getDocName() {
		return docName;
	}

	public void setDocName(String docName) {
		this.docName = docName;
	}

	public int getAuthorId() {
		return authorId;
	}

	public void setAuthorId(int authorId) {
		this.authorId = authorId;
	}

	public double[] getFeatureVector() {
		return featureVector;
	}

	public void setFeatureVector(double[] featureVector) {
		this.featureVector = featureVector;
	}
	

	public String getRawText() {
		return new String(rawText);
	}

	public void setRawText(char[] rawText) {
		this.rawText = rawText;
	}

}
