import java.util.Scanner;

public class JuraganCoklat {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int N = in.nextInt();
    long[] ans = new long[N];
    for (int i = 0; i < N; ++i) {
      int K = in.nextInt();
      for (int j = 0; j < K; ++j) {
        int C = in.nextInt();
        ans[i] += C;
      }
    }
    int Q = in.nextInt();
    for (int i = 0; i < Q; ++i) {
      System.out.println(ans[in.nextInt()-1]);
    }
  }
}
