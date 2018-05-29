/* File: recorddistance.ch
   Record time and distances, plot the acquired data */
#include <mindstorms.h>
#include <chplot.h>
CMindstorms robot;
double speed = 2.5;        // speed in 2.5 inches/seconds 
double radius = 1.1;      // radius of the wheel in inches
double distance = 12;      // distance in inches
double timeInterval = 0.1; // time interval in 0.1 second 
int numDataPoints;         // number of data points recorded
robotRecordData_t timedata, distances; // recorded time and distances 
CPlot plot;                // plotting class

/* move to the zero position */
robot.resetToZero();

/* set the robot speed */
robot.setSpeed(speed, radius);

/* begin recording time and distance based on joint 2 */
robot.recordDistanceBegin(timedata, distances, radius, timeInterval);

/* drive the specified distance based on the radius of the wheels */
robot.driveDistance(distance, radius);

/* end recording time and distance */
robot.recordDistanceEnd(numDataPoints);

/* plot the data */
plot.title("Distance versus time");
plot.label(PLOT_AXIS_X, "Time (seconds)");
plot.label(PLOT_AXIS_Y, "Distance (inches)");
plot.data2DCurve(timedata, distances, numDataPoints);
plot.plotting();
