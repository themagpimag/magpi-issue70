// File: drawcat.ch
#include <chplot.h>
CPlot plot;

plot.noStrokeColor();                     // set no oulines for shapes
plot.fillColor("#cc9933");                // set RGB value for fill color of light brown face
plot.circle(0, 0, 28);                    // plots circle for face
plot.triangle(7, 26, 27, 8, 30, 30);      // plots triangles for ears
plot.triangle(-7, 26, -27, 8, -30, 30);
plot.fillColor("#ffcc66");             
plot.ellipse(0, -10, 35, 21, 0);      
plot.fillColor("#ffcccc");                // set RGB value for fill color of pink nose
plot.strokeColor("#ff6666");              // sets RGB value for ouline color of pink nose
plot.triangle(-5, -3, 5, -3, 0, -8);      // plots triangle for nose
plot.strokeColor("#ffcccc");              // sets RGB value for fill color of light pink inner ears
plot.triangle(14, 22, 23, 14, 25, 25);    // plots triangles for inner ears
plot.triangle(-14, 22, -23, 14, -25, 25);
plot.fillColor("white");                  // sets fill color of white eyes
plot.noStrokeColor();                     
plot.ellipse(7, 7, 9, 15, 0);             // plots ellipses for eyes
plot.ellipse(-7, 7, 9, 15, 0);
plot.fillColor("black");                  // sets fill color of black pupils
plot.strokeColor("black");                // sets outline color of black whiskers and smile
plot.ellipse(7, 5, 5, 9, 0);              // plots ellipses for pupils
plot.ellipse(-7, 5, 5, 9, 0);
plot.arc(0, 5, 20, 250, 290);             // plots arc for smile
plot.line(0, -8, 0, -15);                 // plots four whiskers
plot.line(3, -9, 21, -5);
plot.line(-3, -9, -21, -5);
plot.line(3, -10, 21, -14);
plot.line(-3, -10, -21, -14);
plot.grid(PLOT_OFF);                      // removes grid lines from plot

plot.axisRange(PLOT_AXIS_XY, -48, 48);    // sets range of plot
plot.sizeRatio(1);
plot.plotting();
