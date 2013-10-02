def recursive_fib(n)
  if n == 0
    return 0
  elsif n == 1
    return 1
  end

  return recursive_fib(n - 1) + recursive_fib(n - 2)
end

t1 = Time.now

puts recursive_fib(ARGV[0].to_i)

t2 = Time.now

puts "Execution time: " + (t2 - t1).to_i.to_s + " seconds"
