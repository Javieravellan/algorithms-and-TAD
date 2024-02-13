package binary.tree;

public class BinaryTree<T extends Number> {
    private Node<T> root;

    public BinaryTree(T rootValue) {
        root = new Node<>(rootValue);
    }

    public BinaryTree() {
    }

    public void add(T value) {
        root = addRecursive(root, value);
    }

    public boolean containsNode(T value) {
        return containsNodeRecursive(root, value);
    }

    private Node<T> addRecursive(Node<T> currentNode, T value) {
        if (currentNode == null) {
            return new Node<T>(value);
        }

        if (value.byteValue() < currentNode.getData().byteValue()) {
            currentNode.setLeft(addRecursive(currentNode.getLeft(), value));
        } else if (value.byteValue() > currentNode.getData().byteValue()) {
            currentNode.setRight(addRecursive(currentNode.getRight(), value));
        }

        return currentNode;
    }

    private boolean containsNodeRecursive(Node<T> current, T value) {
        if (current == null) return false;

        if (value.byteValue() == current.getData().byteValue()) {
            return true;
        }

        return value.byteValue() < current.getData().byteValue() ?
                containsNodeRecursive(current.getLeft(), value) : containsNodeRecursive(current.getRight(), value);
    }
}
