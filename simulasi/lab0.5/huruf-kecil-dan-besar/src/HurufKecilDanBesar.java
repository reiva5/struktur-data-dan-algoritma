import java.util.Scanner;

public class HurufKecilDanBesar {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    char[] s = in.nextLine().toCharArray();
    for (int i = 0; i < s.length; ++i) {
      s[i] = i % 2 == 0 ? Character.toLowerCase(s[i]) : Character.toUpperCase(s[i]);
    }
    System.out.println(new String(s));
  }
}
