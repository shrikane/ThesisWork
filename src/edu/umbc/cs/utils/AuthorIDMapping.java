package edu.umbc.cs.utils;

import java.io.File;
import java.io.IOException;
import java.util.*;

public class AuthorIDMapping {

	
	Map<String,Integer>  mapping ;
	public Map<String, Integer> getMapping() {
		return mapping;
	}

	public AuthorIDMapping() {
		mapping = new HashMap<String, Integer>();
	}
	
	public int getLabel(String fileName){
		return mapping.get(fileName);
	}
	
	public void getLables(String arg) throws IOException {
		int i=0;
		String [] folders = new File(arg).list();
		for (String s : folders) {
		
			File f = new File(arg+"\\"+s);
			for (String string : f.list()) {
				mapping.put(string, i);
			}
			i++;
		}
	}
	
}
