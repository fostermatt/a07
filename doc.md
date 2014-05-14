###Assignment 6 - Documentation###
#####What the program does#####  
This program is designed to input an adjacency matrix from a file given at the command line. The Floyd-Warshall shortest path algorithm is used to find the shortest paths between all verticies. The original matrix and shortest paths will then be output to the screen.


#####Limitations#####   
This program will only accept integers; floats and doubles may not be used. The current implementation will not work with any weights larger than 9,999. As per the Floyd-Warshall algorithm, the graph cannot be cyclic if it contains any negative edges.

#####Operation#####  
Command line operation execution as follows:  

	$ ./<executable.name> <data.file>


#####Output#####  
Upon execution the program will output the original matrix followed by the shortest paths to and from each vertex.