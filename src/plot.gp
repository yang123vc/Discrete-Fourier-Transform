reset
load '~/.gnuplot'
set terminal wxt

transform="../res/trans.dat"

a = 0

#plot 'trans.dat' u 1:2 w steps t 'real', \
#     'trans.dat' u 1:3 w steps t 'imag', \
#     'trans.dat' u 1:4 w steps t 'mod', a

#set xrange[0:50]
k0=0.25
y0=800.
A=16000.
f(x)=A*(k0/3.141592)*(1/(x**2+k0**2))+y0

#fit f(x) 'trans.dat' u 1:4 via k0,y0,A

#set label 1 sprintf("f(x)=A*(k0/PI)*(1/(x**2+k0**2))+y0") at 10,16000
#set label 2 sprintf("A  = %f", A) at 10, 15000
#set label 3 sprintf("k0 = %f", k0) at 10, 14000
#set label 4 sprintf("y0 = %f", y0) at 10, 13000

#set title "Power Spectrum"
set ylabel "Power"
set xlabel "Frequency"

plot transform u 1:4 w steps t 'Modulus' ls 1
#, f(x)

#set terminal png
#set output 'mtas-full-fit.png'
#replot