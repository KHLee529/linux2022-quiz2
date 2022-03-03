reset
set term png size 800,800 enhanced font 'Verdana,10'
set output './plots/tzcnt_performance_comparison.png'

set multiplot layout 3,1

set xlabel 'epochs'
set yrange [0:100]
set ylabel 'time(nsec)'

set title 'Count Trailing Zero Performance Comparison with number = 1'

plot './txt/1.txt' using 1 with points title "a = 1 without using \`__builtin_ctz\`", \
'./txt/1.txt' using 2 with points title "a = 1 using \`__builtin_ctz\`"

set title 'Count Trailing Zero Performance Comparison with number = 0x80000000'

plot './txt/0x80000000.txt' using 1 with points title "a = 0x80000000 without using \`__builtin_ctz\`", \
'./txt/0x80000000.txt' using 2 with points title "a = 0x80000000 using \`__builtin_ctz\`"

set title 'Count Trailing Zero Performance Comparison with randomized number'

plot './txt/rand.txt' using 1 with points title "a = rand() without using \`__builtin_ctz\`", \
'./txt/rand.txt' using 2 with points title "a = rand() using \`__builtin_ctz\`"
