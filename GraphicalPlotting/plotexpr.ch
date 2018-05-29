/* File: plotexpr.ch
   using the member function expr() to plot sin(x) and cos(x) for x from 0 to 10. */
#include <chplot.h>      
CPlot plot;

plot.expr(0, 10, 500, "sin(x)");
plot.legend("sin(x)");
plot.expr(0, 10, 500, "cos(x)");
plot.legend("cos(x)");
plot.plotting();
