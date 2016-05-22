gnuplot gnu.plt
convert bar_chart.eps bar_chart.png
convert bar_chart.png -rotate 90 bar_chart1.png
mv bar_chart1.png bar_chart.png
convert bar_chart.png bar_chart.pdf
