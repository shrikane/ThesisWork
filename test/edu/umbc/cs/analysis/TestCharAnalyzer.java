package edu.umbc.cs.analysis;

import java.util.Arrays;
import java.util.List;

import junit.framework.TestCase;

import org.junit.Rule;
import org.junit.Test;
import org.junit.rules.ExpectedException;

public class TestCharAnalyzer extends TestCase {

	private String testString;
	private CharNGramAnalyzer analyzer;
	@Rule
	public ExpectedException exception = ExpectedException.none();

	private void validate(List<String> exptected, List<String> actual) {

		assertEquals(exptected.size(), actual.size());
		for (int i = 0; i < exptected.size(); i++) {
			assertEquals(exptected.get(i).equals(actual.get(i)), true);
		}
	}

	@Override
	protected void setUp() throws Exception {
		super.setUp();
		testString = "to_be_or_not_to_Be";
		analyzer = new CharNGramAnalyzer();
	}

	@Test
	public void testOneGram() {
		analyzer.tokenSize = 1;
		List<String> exptected = Arrays.asList(new String[] { "t", "o", "_",
				"b", "e", "_", "o", "r", "_", "n", "o", "t", "_", "t", "o",
				"_", "B", "e" });
		List<String> actual = analyzer.getTokens(testString);
		validate(exptected, actual);
	}

	@Test
	public void testTwoGram() {
		analyzer.tokenSize = 2;
		List<String> exptected = Arrays.asList(new String[] { "to", "o_", "_b",
				"be", "e_", "_o", "or", "r_", "_n", "no", "ot", "t_", "_t",
				"to", "o_", "_B", "Be" });
		List<String> actual = analyzer.getTokens(testString);
		validate(exptected, actual);
	}

	@Test
	public void testThreeGram() {
		analyzer.tokenSize = 3;
		List<String> exptected = Arrays.asList(new String[] { "to_", "o_b",
				"_be", "be_", "e_o", "_or", "or_", "r_n", "_no", "not", "ot_",
				"t_t", "_to", "to_", "o_B", "_Be" });
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

}
