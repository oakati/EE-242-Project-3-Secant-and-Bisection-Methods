//Author: Ömer Alperen Kati
//Date: 19/06/2020
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
double eval(double* poly, int order, double a) {
	double value = 0; // value is initially zero, then after calculating each element of the polynomial, we add them to it
	for(int i = 0 ; i <=order ; i++) {
		value += poly[i] * pow(a,i); // adding coefficient times a to the power i to summation.
	}
	return value; // returning the final value of the function.
}

double bisection_method(double a, double b, double tol, double (*eval) (double*, int, double), double* poly, int order, int* noi1) {
	double m = ( a + b ) / 2;	//in case of not entering into while loop, we have already said what m is.
	while ( abs( b - a ) > tol ) {
		m = ( a + b ) / 2;	//updating m for each iteration
		if( eval(poly,order,a)*eval(poly,order,m) > 0) { // deciding to where the new value of m goes to
			a = m; //updating the interval
		} else {
			b = m; //updating the interval
		}
		(*noi1)++; //increasing # of iterations for each iteration.
	}
	return m; //finally returning the final value of m, in other words, calculated root to main function
}

double secant_method(double a, double b, double tol, double (*eval) (double*, int, double), double* poly, int order, int* noi2) {
	double m = a - eval(poly,order,a)*(a-b)/(eval(poly,order,a)-eval(poly,order,b)); //in case of not entering into while loop, we have already said what m is.
	while ( abs( b - a ) > tol ) {
		m = a - eval(poly,order,a)*(a-b)/(eval(poly,order,a)-eval(poly,order,b)); //updating m for each iteration
		b = a; //updating the interval
		a = m; //updating the interval
		(*noi2)++; //increasing # of iterations for each iteration.
	}
	return m; //finally returning the final value of m, in other words, calculated root to main function
}

double hybrid_method(double a, double b, double tol, double (*eval) (double*, int, double), double* poly, int order, int* noi3) {
	double m = ( a + b ) / 2; //in case of not entering into while and for loop, we have already said what m is.
	for( int i = 0 ; (i < 2) && (abs( b - a ) > tol); i++ ) {
		m = ( a + b ) / 2; //updating m for each iteration
		if( eval(poly,order,a)*eval(poly,order,m) > 0) { // deciding to where the new value of m goes to
			a = m; //updating the interval
		} else {
			b = m; //updating the interval
		}
		(*noi3)++;	//increasing # of iterations for each iteration.
	}
	
	while ( abs( b - a ) > tol ) {
		m = a - eval(poly,order,a)*(a-b)/(eval(poly,order,a)-eval(poly,order,b)); //updating m for each iteration
		b = a;	//updating the interval
		a = m;//updating the interval
		(*noi3)++; //increasing # of iterations for each iteration.
	}
	return m;	//finally returning the final value of m, in other words, calculated root to main function
}
int main(int argc, char* argv[]) {
	if(argc == 1) { // This statement is used in case of running the program without entering command line arguments.
		system("pause");
		return 0;
	}
	double* poly = new double[argc-4];	//This is an array for storing coefficients of the polynomial
	double a, b, m, tol, r1, r2, r3;	// a and b are for initially given points.
											//m is to store new-found points temporarily for each iteration 
											//tol is to store tolerance value.
											//r1, r2 and r3 are to store roots for each type of iteration
	
	int* noi1 = new int; //This is to store # of iterations for the bisection method.
	int* noi2 = new int;//This is to store # of iterations for the secant method.
	int* noi3 = new int;//This is to store # of iterations for the hybrid method.

//Here, initializing all # of iterations to 0 before starting.
	*noi1 = 0; 
	*noi2 = 0; 
	*noi3 = 0;
//Here, initializing all # of iterations to 0 before starting.	
	
	int order = argc - 5;	//storing order of the given polynomial to use while evaluating the function in eval.

// Matching given coefficients in command line arguments with each element of poly array.	
	for(int i = argc-5 ; i >= 0 ; i--) {
		poly[i] = strtod(argv[order+1-i], NULL);		
	}

//	other command line argument assignments.
	a = strtod(argv[argc-3], NULL);
	b = strtod(argv[argc-2], NULL);
	tol = strtod(argv[argc-1], NULL);
//	other command line argument assignments.

	r1 = bisection_method(a, b, tol, eval, poly, order, noi1);	//executing bisection method that returns calculated root to r1.

// before starting following method, reseting the values of a and b.
	a = strtod(argv[argc-3], NULL); 
	b = strtod(argv[argc-2], NULL);	
// before starting following method, reseting the values of a and b.
	
	r2 = secant_method(a, b, tol, eval, poly, order, noi2);//executing secant method that returns calculated root to r2.
	
// before starting following method, reseting the values of a and b.
	a = strtod(argv[argc-3], NULL);
	b = strtod(argv[argc-2], NULL);
// before starting following method, reseting the values of a and b.
	
	r3 = hybrid_method(a, b, tol, eval, poly, order, noi3);		//executing hybrid method that returns calculated root to r3.

//printing # of iterations and calculated roots for each method to screen.
	cout << "For the Bisection Method: " << *noi1 << " number of iterations and " << r1 << " is the root." << endl;
	cout << "For the Secant Method: " << *noi2 << " number of iterations and " << r2 << " is the root." << endl; 
	cout << "For the Hybrid Method: " << *noi3 << " number of iterations and " << r3 << " is the root." << endl; 
//printing # of iterations and calculated roots for each method to screen.

 
	return 0;
}
//Author: Ömer Alperen Kati
//Date: 19/06/2020
