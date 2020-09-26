import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class KalkulatorSangatSederhana {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int Q = in.nextInt();
    Map<String, Operation> operationMap = new HashMap<>();
    operationMap.put("+", new Plus());
    operationMap.put("-", new Minus());
    operationMap.put("*", new Multiply());
    in.nextLine();
    for (int i = 0; i < Q; ++i) {
      String[] arguments = in.nextLine().split(" ");
      BigInteger a = new BigInteger(arguments[1]);
      BigInteger b = new BigInteger(arguments[2]);
      System.out.println(operationMap.get(arguments[0]).evaluate(a,b));
    }
  }

  public interface Operation {
    BigInteger evaluate(BigInteger a, BigInteger b);
  }

  public static class Plus implements Operation {
    @Override
    public BigInteger evaluate(BigInteger a, BigInteger b) {
      return a.add(b);
    }
  }

  public static class Minus implements Operation {
    @Override
    public BigInteger evaluate(BigInteger a, BigInteger b) {
      return a.subtract(b);
    }
  }

  public static class Multiply implements Operation {
    @Override
    public BigInteger evaluate(BigInteger a, BigInteger b) {
      return a.multiply(b);
    }
  }
}
