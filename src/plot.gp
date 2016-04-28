reset
load '~/.gnuplot'
set terminal wxt
set key top center

transform="../res/trans.dat"

set ylabel "Power"
set xlabel "Frequency"

plot transform u 1:2 w steps t 'real' ls 1, \
     transform u 1:3 w steps t 'imag' ls 3, \
     transform u 1:4 w steps t 'mod' ls 2,

#set terminal png
#set output 'output.eps'
#replot