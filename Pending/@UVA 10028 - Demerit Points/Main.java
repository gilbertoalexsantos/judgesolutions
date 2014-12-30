import java.util.*;

public class Main {

  public static class Node {
    Calendar date;
    int value;

    public Node(String d, int v) {
      date = getDate(d);
      value = v;
    }
  }

  public static Calendar getDate(String w) {
    int year = Integer.parseInt(w.substring(0,4));
    int month = Integer.parseInt(w.substring(4,2));
    int day = Integer.parseInt(w.substring(6,2));
    Calendar ret = Calendar.getInstance();
    ret.set(year,month,day);
    return ret;
  }

  public String getFormated(Calendar d) {
    return d.get(Calendar.YEAR) + "-" + d.get(Calendar.DAY_OF_MONTH) + "-" + d.get(Calendar.DAY_OF_WEEK);
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int qt = Integer.parseInt(s.nextLine());
    s.nextLine();
    while((qt - 1) > 0) {
      qt--;
      Calendar date_begin = getDate(s.nextLine());
      ArrayList<Node> arr = new ArrayList<Node>();
      while(true) {
        String line = s.nextLine();
        if(line.isEmpty()) break;
        String[] cmd = line.split(" ");
        arr.add(new Node(cmd[0],Integer.parseInt(cmd[1])));
      }
      System.out.println(getFormated(date_begin) + " No merit or demerit points.);
      int i = 0;
      :wq

      while(i < arr.size()) {

      }
      if(qt > 0)
        System.out.println();
    }
  }

}
