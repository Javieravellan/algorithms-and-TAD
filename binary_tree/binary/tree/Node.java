package binary.tree;

public class Node<T extends Number> {
    private T data;
    private Node<T> right;
    private Node<T> left;

    public Node(T valueRoot) {
        this.data = valueRoot;
        right = null;
        left = null;
    }

    public T getData() {
        return data;
    }

    public void setData(T d) {
        data = d;
    }

    public Node<T> getRight() {
        return right;
    }

    public void setRight(Node<T> right) {
        this.right = right;
    }

    public Node<T> getLeft() {
        return left;
    }

    public void setLeft(Node<T> left) {
        this.left = left;
    }
}
