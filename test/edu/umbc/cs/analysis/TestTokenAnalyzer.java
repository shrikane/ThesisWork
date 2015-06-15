package edu.umbc.cs.analysis;

import java.util.Arrays;
import java.util.List;

import junit.framework.TestCase;

import org.junit.Rule;
import org.junit.Test;
import org.junit.rules.ExpectedException;

public class TestTokenAnalyzer extends TestCase {

	private String testString;
	private TokenNGramAnalyzer analyzer;
	@Rule
	public ExpectedException exception = ExpectedException.none();

	private void validate(List<String> exptected, List<String> actual) {

		assertEquals(exptected.size(), actual.size());
		for (int i = 0; i < exptected.size(); i++) {
			assertEquals(true, exptected.get(i).equals(actual.get(i)));
		}
	}

	@Override
	protected void setUp() throws Exception {
		super.setUp();
		testString = "to be or not to be";
		analyzer = new TokenNGramAnalyzer();
	}

	@Test
	public void testOneGram() {
		analyzer.tokenSize = 1;
		List<String> exptected = Arrays.asList(new String[] { "to", " be",
				" or", " not", " to", " be" });
		List<String> actual = analyzer.getTokens(testString);
		validate(exptected, actual);
	}

	@Test
	public void testTwoGram() {
		analyzer.tokenSize = 2;
		List<String> exptected = Arrays.asList(new String[] { "to be",
				" be or", " or not", " not to", " to be" });
		List<String> actual = analyzer.getTokens(testString);
		validate(exptected, actual);
	}

	@Test
	public void testNoText() {
		analyzer.tokenSize = 3;
		exception.expect(NullPointerException.class);
	}

	@Test
	public void testZeroLengthNGram() {
		exception.expect(IllegalArgumentException.class);
	}

	@Test
	public void testThreeGram() {
		analyzer.tokenSize = 3;
		List<String> exptected = Arrays.asList(new String[] { "to be or",
				" be or not", " or not to", " not to be" });
		List<String> actual = analyzer.getTokens(testString);
		validate(exptected, actual);
	}

}
