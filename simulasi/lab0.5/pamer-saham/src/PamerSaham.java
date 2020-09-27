import java.util.Scanner;

public class PamerSaham {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int N = in.nextInt();
    long ans = 0;
    long total = 0;
    for (int i = 0; i < N; ++i) {
      int curr = in.nextInt();
      total += curr;
      ans = Math.max(ans, total);
      total = Math.max(total, 0);
    }
    System.out.println(ans);
  }
}
