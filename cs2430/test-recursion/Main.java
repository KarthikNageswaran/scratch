import java.util.Calendar;

public class Main {

  static long recursiveFibonacci(long n)
  {
    if (n == 0)
    {
      return 0;
    }
    else if (n == 1)
    {
      return 1;
    }

    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
  }

  public static void main(String[] args) {
    if (args.length != 1) {
      System.out.println("Usage: java Main <n>");

      return;
    }


    final long index = Long.parseLong(args[0]);
    final long start = Calendar.getInstance().getTimeInMillis();
    
    System.out.println("" + recursiveFibonacci(index));
    
    final long stop = Calendar.getInstance().getTimeInMillis();
    
    System.out.println("Execution time: " + ((stop - start) / 1000) + " seconds");
  }

}
