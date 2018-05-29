/* The source code for generating the above plot */ 
#include <math.h>
#include <chplot.h>
#include <numeric.h>

int main() {
    double r, x[150], y[150], z[22500];
    int i, j;
    CPlot plot;                    // instantiate a plot class

    lindata(-10, 10, x);           // assign x with -10 <= x <= 10 linearly
    lindata(-10, 10, y);           // assign y with -10 <= y <= 10 linearly
    for(i=0; i<150; i++) {
        for(j=0; j<150; j++) {
            r = sqrt(x[i]*x[i]+y[j]*y[j]);
            z[150*i+j] = sin(r)/r; // peak function z in terms of (x, y) 
        }
    }
    plot.data3D(x, y, z);          // add 3D plotting data
    plot.plotting();               
}
