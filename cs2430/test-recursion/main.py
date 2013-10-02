import sys, time

def recursive_fib(n):
  if n == 0:
    return 0
  elif n == 1:
    return 1

  return recursive_fib(n - 1) + recursive_fib(n - 2)

def main(argv):
  t1 = time.clock()
  
  print recursive_fib(argv)
  
  t2 = time.clock()
  
  print 'Execution time: ', int(t2 - t1), ' seconds'

main(int(sys.argv[1]))