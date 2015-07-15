package min_stack;

public class MinStack {

    private static class IntStack {
        private int[] items = new int[16];
        private int size = 0;

        private void ensureSize(int newSize) {
            if (items.length < newSize) {
                int[] newItems = new int[items.length * 2];
                System.arraycopy(items, 0, newItems, 0, items.length);
                items = newItems;
            }
        }

        public void push(int v) {
            ensureSize(size + 1);
            items[size++] = v;
        }

        public void pop() {
            if (size == 0) {
                throw new IllegalStateException("The stack is empty");
            }
            size--;
        }

        public int top() {
            if (size == 0) {
                throw new IllegalStateException("The stack is empty");
            }
            return items[size - 1];
        }

        public boolean isEmpty() {
            return size == 0;
        }
    }

    private IntStack minStack = new IntStack();
    private IntStack stack = new IntStack();

    public void push(int x) {
        if (stack.isEmpty() || x <= minStack.top()) {
            minStack.push(x);
        }
        stack.push(x);
    }

    public void pop() {
        int x = stack.top();
        stack.pop();
        if (x == minStack.top()) {
            minStack.pop();
        }
    }

    public int top() {
        return stack.top();
    }

    public int getMin() {
        return minStack.top();
    }

}
