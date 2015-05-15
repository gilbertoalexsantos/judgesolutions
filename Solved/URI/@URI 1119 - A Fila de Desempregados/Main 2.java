import java.util.Scanner;

public class Main {

  public static class Node {
    Node left, right;
    int number;

    public Node() {
      this(0);
    }

    public Node(int number) {
      left = right = null;
      this.number = number;
    }
  }

  public static class List {
    Node head, tail;

    public List() {
      head = tail = null;
    }

    public void add(int number) {
      if (head == null) {
        head = new Node();
        tail = new Node();
        Node newNode = new Node(number);
        newNode.right = newNode;
        newNode.left = newNode;
        head.right = newNode;
        tail.right = newNode;
        return;
      }

      Node newNode = new Node(number);
      Node lastNode = tail.right;
      newNode.left = lastNode;
      newNode.right = lastNode.right;
      lastNode.right = newNode;
      tail.right = newNode;

      // Updating head
      head.right.left = newNode;
    }

    public void delete(Node n) {
      if (n == head.right && n == tail.right) {
        head = tail = n = null;
        return;
      }

      Node l = n.left;
      Node r = n.right;
      l.right = r;
      r.left = l;

      if (n == head.right) {
        head.right = r;
      }
      if (n == tail.right) {
        tail.right = l;
      }
    }

    public boolean isEmpty() {
      return head == null;
    }

  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);

    int n, qtRight, qtLeft;
    while (true) {
      n = s.nextInt(); qtRight = s.nextInt(); qtLeft = s.nextInt();
      if (n + qtRight + qtLeft == 0) {
        break;
      }

      List l = new List();
      for (int i = 1; i <= n; i++) {
        l.add(i);
      }

      Node i = l.head.right, j = l.tail.right;
      String sep = "";
      while (!l.isEmpty()) {
        int cnt = 0;
        while (cnt+1 < qtRight) {
          i = i.right;
          cnt++;
        }
        cnt = 0;
        while (cnt+1 < qtLeft) {
          j = j.left;
          cnt++;
        }

        System.out.print(sep);
        int n1 = i.number;
        int n2 = j.number;
        System.out.print(n1 < 10 ? "  " : " ");
        System.out.print(n1);
        if (n1 != n2) {
          System.out.print(n2 < 10 ? "  " : " ");
          System.out.print(n2);
        }
        sep = ",";

        Node d1 = i, d2 = j;
        if (d1.right == d2) {
          i = d2.right;
        } else {
          i = d1.right;
        }
        if (d2.left == d1) {
          j = d1.left;
        } else {
          j = d2.left;
        }

        l.delete(d1);
        if (n1 != n2) {
          l.delete(d2);
        }
      }
      System.out.println();

    }

  }

}
