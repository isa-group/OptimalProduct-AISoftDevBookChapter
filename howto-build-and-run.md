# How to build, run, and customize the project
## Authors

Authors of the original implementation of the NSGA-II algorithm:
 * Miquing Li (https://sites.google.com/view/miqing-li/home)
This source code is part of the codebase used in the paper "(SIP: Optimal Product Selection from Feature Models Using Many-Objective Evolutionary Optimization)[http://dx.doi.org/10.1145/2897760]", and the rest of the source code used in such chapter is available at https://figshare.com/articles/code/The_SIP_Code/2115802

Author of the makefile, and this documentation:
 * José Antonio Parejo Maestre (japarejo@us.es)


## Building

This a C project, whose source code can be built in the Windows using Visual Studio and in Linux using GCC.
For compilation in Windows we recommend using Visual Studio 2022 community edition (which is free was used for compiling and runnig the samples shown in the book chapter). 
You can download such version of Visual Studio for free at:  https://visualstudio.microsoft.com/es/thank-you-downloading-visual-studio/?sku=Community&rel=17

Regarding compilation with GCC, we have created a makefile for building the project (you should clean the Debug folder inside src prior to that) .

## Running and report generation
In the folder src/Debug you will find an executable file that runs the example. You have also an R script for generating pretty tables with the obtained resuls. You will need to install R in your system if you want to run such script.