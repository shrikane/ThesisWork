/*
Design and implement a class to generate random numbers in an arbitrary probability distribution given by an array of integer weights, i.e. for int[] w return a number, n, from 0 to w.length - 1 with probability w[n] / sum(w). Using an existing random number generator with a uniform distribution is permitted. 

Example distribution: 
w = 1, 2, 3, 2, 1 

Example probabilities: 
w / sum = 1/9, 2/9, 1/3, 2/9, 1/9 

Example results: 
n = 0, 1, 2, 3, 4 

Documentation: 

Class java.util.Random 

public int nextInt(int n) 

Returns a pseudorandom, uniformly distributed int value between 0 (inclusive) and the specified value (exclusive), drawn from this random number generator's sequence. The general contract of nextInt is that one int value in the specified range is pseudorandomly generated and returned. All n possible int values are produced with (approximately) equal probability. 

Parameters: 
n - the bound on the random number to be returned. Must be positive. 
Returns: 
the next pseudorandom, uniformly distributed int value between 0 (inclusive) and n (exclusive) from this random number generator's sequence 
Throws: 
IllegalArgumentException - if n is not positive
*/

/*
sumarray = array of values addedup. a = {1,2,3,2,1} => sumarray = {1,3,6,8,9}
sum = sum of all values of array.
num = random(sum).
binary search num in sumarray. if not found return next larger number's index.
return a[index];
*/
