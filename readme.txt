//Author: Ömer Alperen Katı - 2017401069
//Date: 19/06/2020

Project 3: Secant and Bisection Methods

HOW TO RUN THE PROGRAM USING CMD

-Firstly, press windows key on your keybord, write cmd and press enter to open command
window. Then adjust the directory of cmd as where source.cpp is located.

-Secondly, if you are in the correct directory, write "g++ source.cpp -o source.exe" to
generate .exe file, and press enter.

Example: C:\Users\(!!username here!!)\Desktop\EE242_Project3>g++ source.cpp -o source.exe

-After that, write "source.exe c_n c_n-1 ... c_1 c_0 a b tol",
and press enter to run the program.
where c_ns are the line inputs of the coefficients of the polynomial,
	a and b are initial guesses for the interval of the root,
	tol is the tolerance value.

Example: C:\Users\(!!username here!!)\Desktop\EE242_Project3>source.exe 2 2 -7 1 -7 1.5 1.8 0.001

for the polynomial of 2*x^4 + 2*x^3 - 7*x^2 + x - 7, the interval of [1.5,1.8],
and the tolerance of 0.001

//Author: Ömer Alperen Katı - 2017401069
//Date: 19/06/2020