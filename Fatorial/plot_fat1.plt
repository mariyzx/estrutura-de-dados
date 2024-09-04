set terminal pngcairo size 800,600 enhanced font 'Verdana,10'
set output 'tempos_fatorial1.png'
set title "Tempo de Execução do Cálculo do Fatorial"
set xlabel "n (Fatorial de n)"
set ylabel "Tempo de Execução (nanosegundos)"
set grid
plot "output/tempos_fat1.txt" using 1:2 with linespoints title "Tempo de Execução"
