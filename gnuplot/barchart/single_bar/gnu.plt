set terminal postscript color solid
set termoption font ',20'
reset
set output "bar_chart.eps"

set boxwidth 0.5
set style fill solid
plot "data.dat" using 1:3:xtic(2) with boxes

