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

    public void deleteNode(T value) {
        root = deleteRecursive(root, value);
    }
    private Node<T> addRecursive(Node<T> currentNode, T value) {
        if (currentNode == null) {
            return new Node<T>(value);
        }

        if (value.doubleValue() < currentNode.getData().doubleValue()) {
            currentNode.setLeft(addRecursive(currentNode.getLeft(), value));
        } else if (value.doubleValue() > currentNode.getData().doubleValue()) {
            currentNode.setRight(addRecursive(currentNode.getRight(), value));
        }

        return currentNode;
    }

    private boolean containsNodeRecursive(Node<T> current, T value) {
        if (current == null) return false;

        if (value.doubleValue() == current.getData().doubleValue()) {
            return true;
        }

        return value.doubleValue() < current.getData().doubleValue() ?
                containsNodeRecursive(current.getLeft(), value) : containsNodeRecursive(current.getRight(), value);
    }

    private Node<T> deleteRecursive(Node<T> current, T value) {
        if (current == null) {
            return null;
        }
        System.out.println("Valor a eliminar: " + value.doubleValue());
        System.out.println("Valor del nodo actual: " + current.getData().doubleValue());
        if (value.doubleValue() == current.getData().doubleValue()) {
            // Si es un Nodo hoja
            if (current.getLeft() == null && current.getRight() == null) {
                return null;
            }

            // Si solo tiene hijo izquierdo
            if (current.getRight() == null) {
                return current.getLeft();
            }

            // Si solo tiene hijo derecho
            if (current.getLeft() == null) {
                return current.getRight();
            }

            // Eliminar Nodo cuando el padre tiene 2 hijos.
            // Buscamos el nodo màs pequeño del subarbol derecho.
            var smallValue = findSmallestValue(current.getRight());
            // seteamos el valor más pequeño del subarbol derecho en el nodo actual, o sea el padre.
            current.setData(smallValue);
            // finalmente, eliminamos el nodo y retornamos current.
            current.setRight(deleteRecursive(current.getRight(), smallValue));
            return current;
        }

        if (value.doubleValue() < current.getData().doubleValue()) {
            current.setLeft(deleteRecursive(current.getLeft(), value));
            return current;
        }

        current.setRight(deleteRecursive(current.getRight(), value));
        return current;
    }

    private T findSmallestValue(Node<T> node) {
        return node.getLeft() == null ? node.getData() : findSmallestValue(node.getLeft());
    }
}
