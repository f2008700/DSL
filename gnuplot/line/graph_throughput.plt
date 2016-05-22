set terminal postscript color solid
set termoption font ',20'
reset
set output "ThroughputValues_points_mapping.eps"
set xlabel "False Positive" font ", 30" offset 0,-1,0
set ylabel "True Positive" font ", 30" offset -1,0,0
set autoscale
set term post size 14,10

set key default font ", 25"
set key top left
set key spacing 1
set grid

set xtics font ", 30"
set ytics font ", 30" 



set style data linespoints
set style fill pattern border -1


set style line 1 lt rgb "blue" lw 5
set style line 2 lt rgb "orange" lw 5
set style line 3 lt rgb "red" lw 2
set style line 4 lt rgb "green" lw 0
set style line 5 lt 5 lw 0


plot "1" using 1:2 title "ROC Curve" pt 7 ps 1
