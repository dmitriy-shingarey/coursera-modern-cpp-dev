# Programming Assignment: Mass of Blocks

Calculate the total mass of rectangular parallelepiped-shaped concrete blocks of the same density but different sizes.

## Directions

Consider that the dimensions of the blocks are measured in centimeters, the density in grams per cubic centimeter, and the resulting mass in grams. Thus, the mass of the block can be calculated as the simple product of density by volume.

## Input format

The first line contains two positive integers: the number of blocks _N_ and the density of each block _R_. Each of the following _N_ lines contains three positive integers _W_, _H_, _D_ - the size of the next block.

It is guaranteed that:

* the number of _N_ blocks does not exceed 10^5;
* block density _R_ does not exceed 100;
* block sizes _W_, _H_, _D_ do not exceed 10^4.

### Example

### Enter

```commandline
2 14
1 2 3
30 40 50
```

### Output

```commandline
840084
```

