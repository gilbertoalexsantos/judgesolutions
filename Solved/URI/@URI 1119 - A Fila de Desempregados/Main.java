/*
  Lógica:

  Não há necessidade de usar Lista Duplamente Encadeada Circular aqui. Se pudesse usar a LDE de java.util.List, até poderia usar, mas como não pode, não há necessidade de implementar para resolver a questão.

  Como eu fiz? Do jeito mais simples. Eu crio um vetor de 'n' posições, todos com o valor falso. Se uma posição desse vetor estiver com valor TRUE, significa que o número já foi "retirado" e se estiver falso, o número ainda não foi retirado.

  Depois disso, você coloca uma variável apontando para o começo e uma para final do vetor, e fica só percorrendo o vetor quantas casas ele manda percorrer (o 'k' e 'm'). Perceba que, quando você está percorrendo, você só conta 1 casa, se o valor no vetor estiver FALSO. Porque se estiver TRUE, significa que o valor já foi retirado, logo você não pode contar ele.

  Um detalhe quanto a impressão dos números: Toda vez que você imprimir um número, você tem que imprimir uma quantidade de barras de espaço. Essa quantidade o problema não fala quanto é, mas eu olhei no Fórum, e eles falaram que são: 2 barras de espaço, se o número for menor que 10, 1 barra de espaço, se o número for maior ou igual que 10.

  A complexidade disso é O(max(k, m) * N).

  OBS: Se você usar uma Lista Duplamente Encadeada Circular, a complexidade continua O(max(k, m) * N).


  
  Comentários do seu código:

  * Deixe de ser viado, e coloque os nomes das variáveis certo... "nuevo" é foda kkkkkkk.
  * Se eu fosse implementar com Lista Duplamente Encadeada Circula, eu primeiramente, óbvio, implementaria a Lista Duplamente Encadeada Circular. Então, se você quiser ir por esse caminho, implemente certo! Só precisa de inserção na cauda, e remoção em qualquer lugar da lista... Não é muito complicado. Depois eu implemento e te mando.
 */

import java.util.Scanner;

public class Main {

  /*
    Retorna a posição à esquerda de 'pos'.
   */
  public static int getLeft(int pos, int limit) {
    return pos == 0 ? limit - 1 : pos - 1;
  }

  /*
    Retorna a posição à direita de 'pos'.
   */
  public static int getRight(int pos, int limit) {
    return (pos + 1) % limit;
  }

  /*
    Retorna a posição à esquerda de 'pos' que ESTEJA DISPONÍVEL.
   */
  public static int getNextDisponibleLeft(int pos, int limit, boolean[] arr) {
    pos = getLeft(pos, limit);
    while (arr[pos]) {
      pos = getLeft(pos, limit);
    }
    return pos;
  }

  /*
    Retorna a posição à direita de 'pos' que ESTEJA DISPONÍVEL.
   */
  public static int getNextDisponibleRight(int pos, int limit, boolean[] arr) {
    pos = getRight(pos, limit);
    while (arr[pos]) {
      pos = getRight(pos, limit);
    }
    return pos;
  }

  /*
    Basicamente, ele tenta andar para a esquerda, partindo de pos, 'qt' vezes.
    Ele apenas conta posições DISPONÍVEIS.
   */
  public static int walkLeft(int pos, int qt, int limit, boolean[] arr) {
    qt--;
    while (qt > 0) {
      pos = getNextDisponibleLeft(pos, limit, arr);
      qt--;
    }
    return pos;
  }

  /*
    Basicamente, ele tenta andar para a direita, partindo de pos, 'qt' vezes.
    Ele apenas conta posições DISPONÍVEIS.
   */
  public static int walkRight(int pos, int qt, int limit, boolean[] arr) {
    qt--;
    while (qt > 0) {
      pos = getNextDisponibleRight(pos, limit, arr);
      qt--;
    }
    return pos;
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n, k, m;
    while (true) {
      n = s.nextInt(); k = s.nextInt(); m = s.nextInt();
      if (n + k + m == 0) {
        break;
      }

      boolean[] arr = new boolean[n];
      for (int i = 0; i < n; i++) {
        arr[i] = false;
      }

      String toPrint = "";
      int cnt = 0, left = 0, right = n - 1;
      while (true) {
        left = walkRight(left, k, n, arr);
        right = walkLeft(right, m, n, arr);

        arr[left] = arr[right] = true;
        cnt += 1 + ((left != right) ? 1 : 0);

        System.out.print(toPrint);
        System.out.print((left+1) < 10 ? "  " : " ");
        System.out.print((left+1));
        if (left != right) {
          System.out.print((right+1) < 10 ? "  " : " ");
          System.out.print((right+1));
        }

        if (cnt == n) {
          break;
        }

        left = getNextDisponibleRight(left, n, arr);
        right = getNextDisponibleLeft(right, n, arr);
        toPrint = ",";
      }
      System.out.println();
    }
  }

}
