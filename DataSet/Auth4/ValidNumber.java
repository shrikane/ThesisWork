package valid_number;

public class ValidNumber {

    enum Status {
        INIT, SYMBOL, INT, DOT, FRAC, E, SYMBOL_E, INT_E
    }

    public class Solution {

        public boolean isNumber(String s) {
            s = s.trim();
            Status status = Status.INIT;
            boolean hasInt = false;
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                switch (status) {
                case INIT:
                    if (c == '+' || c == '-') {
                        status = Status.SYMBOL;
                    } else if (Character.isDigit(c)) {
                        status = Status.INT;
                        hasInt = true;
                    } else if (c == '.') {
                        status = Status.DOT;
                    } else {
                        return false;
                    }
                    break;
                case SYMBOL:
                    if (Character.isDigit(c)) {
                        status = Status.INT;
                        hasInt = true;
                    } else if (c == '.') {
                        status = Status.DOT;
                    } else {
                        return false;
                    }
                    break;
                case INT:
                    if (Character.isDigit(c)) {

                    } else if (c == '.') {
                        status = Status.DOT;
                    } else if (c == 'E' || c == 'e') {
                        status = Status.E;
                    } else {
                        return false;
                    }
                    break;
                case DOT:
                    if (Character.isDigit(c)) {
                        status = Status.FRAC;
                    } else if (c == 'E' || c == 'e') {
                        if (!hasInt) {
                            return false;
                        }
                        status = Status.E;
                    } else {
                        return false;
                    }
                    break;
                case FRAC:
                    if (Character.isDigit(c)) {
                    } else if (c == 'E' || c == 'e') {
                        status = Status.E;
                    } else {
                        return false;
                    }
                    break;
                case E:
                    if (Character.isDigit(c)) {
                        status = Status.INT_E;
                    } else if (c == '+' || c == '-') {
                        status = Status.SYMBOL_E;
                    } else {
                        return false;
                    }
                    break;
                case SYMBOL_E:
                    if (Character.isDigit(c)) {
                        status = Status.INT_E;
                    } else {
                        return false;
                    }
                    break;
                case INT_E:
                    if (Character.isDigit(c)) {
                    } else {
                        return false;
                    }
                    break;
                }
            }
            return (hasInt && status == Status.DOT) || status == Status.INT
                    || status == Status.FRAC || status == Status.INT_E;
        }
    }

    public static class UnitTest {

    }
}
