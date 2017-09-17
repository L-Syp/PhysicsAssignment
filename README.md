# PhysicsAssignment
Assignment for Introduction for Physicists module at University of Malta. Plots were generated with gnuplot.

# Problem definition

Task which has been given consisted in computing the gravitational potential across a given two-dimensional grid imitating space containing a number of point masses. Each point in space has its own gravitational potential caused by the presence of masses in space. The higher the mass and the closer to the point it is the more influence it has on the gravitational potential at a given point. Gravitational potential infinitely far away from any mass is defined as zero therefore it is negative at any point in space. The potential at a distance x from a point mass of mass M is

V=−GMx

G is the gravitational constant. In this task it is assumed that G is equal to 1 to avoid dealing with very small numbers.

# Problem solution

 In order to calculate the gravitational potential properly at a certain point one has to keep in mind that net potential of the point is a sum of potentials caused by each body, so it is necessary to iterate over each point as many times as many bodies are defined in space. The first step of solving the problem was to present the universe as a variable. I have decided to create _Cell_ object containing variables for gravitational potential of a cell from each body and a net potential. _Cell_ object has a function to calculate net potential by adding partial potentials. Universe consists of an array of _Cell_ objects. There is no need of adding the variables for coordinates of the cell, position of a variable in the array would be used to identify the coordinates.  To calculate the gravitational potential it is necessary to have the distance between the mass point and the body, distance is calculated using Pythagorean theorem. To avoid dividing by zero I had to assume that if the distance is equal to zero the potential at that point is zero as well. To calculate potential of each grid I iterated over each row and each column. The number of iterations depends on the number of the bodies. It is assumed that the number of the bodies does not exceed five, so iterating five times over would be possible, but it would not be efficient. The next step is iterating again over each cell to calculate net potential then results are saved as a .csv file.

# Code explanation

In the first six lines of the _main()_ method variables are decelerated.

Variable named _universe_ is a two-dimensional array of _Cell_ type which represents a grid, dimensions of the array are defined as a constant in a _Universe.h_ header to allow a programmer to increase grid size and therefore accuracy of calculations if needed.

Each Cell variable consist of a float for storing net potential of a cell and an array of floats named _fPotential_ for storing potential caused by each body present in the universe. Struct _Cell_ also contains a method for calculating net potential which is just simple addition of values stored in _fPotential_. Struct _Cell_ also contains a constructor which sets all variables to zero to avoid  storing random values which interrupt proper calculations. The next variable is an array of body objects. Each body object consists of float values which represent x and y coordinates as well as its mass. Pointers are assigned to _Body_ array and a string containing file name in order to enable passing these variables as a parameters to the functions. _ChooseFileToRead()_ function is called to assign a file name to  a variable. This file name is used afterwards to load data from a text file. _LoadData()_ function requires file name and a pointer to an array of type _Body_. File name indicates which file should be opened while a pointer to an array of _Body_ type is needed to assign values from a text file to a _Body_ variables. Next step is loading data from a text file. Parameters for a _LoadData()_ function are  file name which is resolved by _ChooseFileToRead()_ function and a pointer to _Body_ type array for indication to which variable a data from a text file should be assigned to. Depending on what value _DetermineHowManyBodies()_ returns the proper method of reading the text file is used. The next step is iterating over all cells to calculate potential of each point. The number of iterations depends on the number of the bodies included in a given text file. Then all cells are iterated over again to calculate net potential of each cell. When all cells have assigned net potential all the data from the array of _Cell_ is exported to a .csv file.

# Potential improvements

However, program calculates the gravitational point at any point it can be improved to robust its efficiency and flexibility. The main issue of the program is that files which contain no more than five bodies data can be processed, if there are more the program is not capable of taking them into account while calculating the gravitational potential. There should be possibility of processing files containing any number of defined bodies. The other improvement which might be applied is a structure of a struct _Cell_. It consists of two variables, but _fNetPotential_ variable is redundant since net potential can be easily figured out by adding values from _fPotenial[]_. Removing _fNetPotenial_ would reduce the amount of memory used by a program and it is worth remembering that _universe_ variable is made of 10000 _Cell_ objects, so it would be great enhancement to decrease a size of a _Cell_ struct. The other drawback in the code is that when the size of the grid was greater than 205x205 the program crashed. If this problem was solved the accuracy of the calculations might be significantly improved. I think the grid limit is related the amount of memory used, supposedly larger grid could be used after reducing a size of a _Cell_ struct. Another potential solution for the grid limit would be writing each cell into a databased instead of the array of type _Cell_, size limit would be much higher. Another improvement which might be made is allowing to load a file from any location not just four files which are hard-coded. The last improvement I can think of is displaying a message after the file is processed and .csv file is exported.

<b>Figure 1. Main() function flowchart</b>
![alt text](https://github.com/L-Syp/PhysicsAssignment/blob/master/Plots/chart.png?raw=true)
&nbsp;&nbsp;

![alt text](https://github.com/L-Syp/PhysicsAssignment/blob/master/Plots/Bodies1.png?raw=true)
<b>Figure 2. Plot of the gravitational potential of the bodies defined in bodies1.txt</b>
&nbsp;&nbsp;

![alt text](https://github.com/L-Syp/PhysicsAssignment/blob/master/Plots/Bodies2.png?raw=true) 
<b>Figure 3. Plot of the gravitational potential of the bodies defined in bodies2.txt</b>
&nbsp;&nbsp;

![alt text](https://github.com/L-Syp/PhysicsAssignment/blob/master/Plots/Bodies3.png?raw=true) 
<b>Figure 4. Plot of the gravitational potential of the bodies defined in bodies3.txt</b>
&nbsp;&nbsp;

![alt text](https://github.com/L-Syp/PhysicsAssignment/blob/master/Plots/Bodies4.png?raw=true) 
<b>Figure 5. Plot of the gravitational potential of the bodies defined in bodies4.txt</b>
