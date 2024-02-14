package binary.tree;

public class Main {
    public static void main(String... args) {
        System.out.println("-----------------------------");
        System.out.println("Implementaciòn Àrbol binario.");
        System.out.println("-----------------------------");

        var binaryTree = new BinaryTree<>(5);
        binaryTree.add(6);
        binaryTree.add(7);
        binaryTree.add(4);
        binaryTree.add(2);
        binaryTree.add(1);
        binaryTree.add(12);
        binaryTree.add(254);

        var findValue = 254;
        System.out.print("Buscando el value "+ findValue +", Està dentro del arbol? Respuesta: ");
        System.out.println(binaryTree.containsNode(findValue));

        System.out.println("Eliminar un nodo del àrbol.");

        binaryTree.deleteNode(findValue);

        // volver a poner el nodo eliminado para buscarlo
        binaryTree.add(findValue);

        System.out.println("Recorrido inOrder");
        binaryTree.traverseInOrder(binaryTree.getRoot());

        System.out.println("Recorrido PreOrder");
        binaryTree.traversePreOrder(binaryTree.getRoot());

        System.out.println("Recarrido PostOrder");
        binaryTree.traversePostOrder(binaryTree.getRoot());

        System.out.println("Buscar el nodo: " + findValue);
        System.out.println("Node encontrado: " + binaryTree.findNode(findValue).getData());

        System.out.println("Fin implementaciòn.");
    }
}
