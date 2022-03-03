reset
set xlabel 'epochs'
set yrange [0:1000]
set ylabel 'time(nsec)'
set title 'GCD Functions Performance Comparison'
set term png enhanced font 'Verdana,10'
set output 'gcd_performance_comparison.png'

plot 'benchmark.txt' using 1 with points title "not using \`__builtin_ctz\`", \
'benchmark.txt' using 2 with points title "using \`__builtin_ctz\`"
