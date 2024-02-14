package binary.tree;

public class BinaryTree<T extends Number> {
    private Node<T> root;

    public BinaryTree(T rootValue) {
        root = new Node<>(rootValue);
    }

    public BinaryTree() {
    }

    public Node<T> getRoot() {
        return root;
    }

    public void add(T value) {
        root = addRecursive(root, value);
    }

    public boolean containsNode(T value) {
        return containsNodeRecursive(root, value);
    }

    public Node<T> findNode(T value) {
        return findNodeRecursive(root, value);
    }
    public void deleteNode(T value) {
        root = deleteRecursive(root, value);
    }

    public void traverseInOrder(Node<T> node) {
        if ( node != null ) {
            traverseInOrder(node.getLeft());
            System.out.println(" " + node.getData().doubleValue());
            traverseInOrder(node.getRight());
        }
    }

    public void traversePostOrder(Node<T> node) {
        if (node != null) {
            traversePostOrder(node.getLeft());
            traversePostOrder(node.getRight());
            System.out.println(" " + node.getData().doubleValue());
        }
    }

    public void traversePreOrder(Node<T> node) {
        if (node != null) {
            System.out.println(" " + node.getData().doubleValue());
            traversePreOrder(node.getLeft());
            traversePreOrder(node.getRight());
        }
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

    private Node<T> findNodeRecursive(Node<T> current, T value) {
        if (current == null) return null;

        if (value.doubleValue() == current.getData().doubleValue()) {
            return current;
        }

        return value.doubleValue() < current.getData().doubleValue() ?
                findNodeRecursive(current.getLeft(), value) : findNodeRecursive(current.getRight(), value);
    }

    private Node<T> deleteRecursive(Node<T> current, T value) {
        if (current == null) {
            return null;
        }

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
