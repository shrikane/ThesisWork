package edu.umbc.cs.index;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import edu.umbc.cs.utils.AuthorIDMapping;
import edu.umbc.cs.utils.Document;

public class DocumentHelper {

	public DocumentHelper() {
		// TODO Auto-generated constructor stub
	}

	public static List<Document> getDocs(String dirPath,AuthorIDMapping authorMapping) {
		String[] folders = new File(dirPath).list();
		List<Document> corpus = new ArrayList<Document>();
		FileReader fr = null;
		try {
			for (String s : folders) {
				System.out.println(s);
				File f = new File(dirPath + "\\" + s);
				for (File fileName : f.listFiles()) {
					fr = new FileReader(fileName);
					char[] rawText = new char[(int) (fileName.length() + 1)];
					fr.read(rawText);
					String FileName = fileName.getName();
					Integer authId = authorMapping.getLabel(FileName);
					if(authId == null){
						System.err.println("Author not found skipping file : "+ fileName.getAbsolutePath());
					}else{
						Document d = new Document(FileName,authId,rawText);
						corpus.add(d);
					}	
				}
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (fr != null) {
					fr.close();
				}
			} catch (IOException e) {
				
				e.printStackTrace();
			}
		}
		return corpus;
	}
}
