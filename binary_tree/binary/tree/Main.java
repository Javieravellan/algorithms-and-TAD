package binary.tree;

public class Main {
    public static void main(String... args) {
        System.out.println("-----------------------------");
        System.out.println("Implementaciòn Àrbol binario.");
        System.out.println("-----------------------------");

        var binaryTree = new BinaryTree<>(5);
        binaryTree.add(6);
        binaryTree.add(7);
        binaryTree.add(1);
        binaryTree.add(12);
        binaryTree.add(254);

        var findValue = 254;
        System.out.print("Buscando el value "+ findValue +", Està dentro del arbol? Respuesta: ");
        System.out.println(binaryTree.containsNode(findValue));

        System.out.println("Eliminar un nodo del àrbol.");

        binaryTree.deleteNode(findValue);

        System.out.printf("Existe el nodo %s: %s %n", findValue, (binaryTree.containsNode(findValue) ? "SI" : "NO") );
        System.out.println("Fin implementaciòn.");
    }
}
