#!/bin/bash
doxygen Doxyfile
cd latex/
latex refman.tex
latex refman.tex
dvipdf refman.dvi ../manual.pdf
cd ../
