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
        binaryTree.add(256);

        System.out.print("Buscando el value 256, Està dentro del arbol? Respuesta: ");
        System.out.println(binaryTree.containsNode(256));

        System.out.println("Fin implementaciòn.");
    }
}
