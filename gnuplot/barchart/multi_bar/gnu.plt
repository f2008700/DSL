set terminal postscript color solid
set termoption font ',20'
reset
set output "bar_chart.eps"

set style line 1 lc rgb "red"
set style line 2 lc rgb "blue"

set xtics ("label" 0.25, "label2" 1.75, "bar label" 3.25,)

set boxwidth 0.48
set style fill solid

plot 'data.dat' every 2    using 1:2 with boxes ls 1,\
     'data.dat' every 2::1 using 1:2 with boxes ls 2


