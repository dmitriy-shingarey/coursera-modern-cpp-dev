# Programming Assignment: Average Temperature - 2

The temperature values observed on N consecutive days are given. Find the numbers of days (numbered from zero) with temperature values higher than the arithmetic mean of all N days.

It is guaranteed that the arithmetic mean of the temperature values is an integer.

## Input format

The number N is entered, followed by N integers - the temperature values on the 0th, 1st, ... (N-1)-days. It is guaranteed that N does not exceed a million (10^6), and the temperature values measured in millionths of degrees Celsius lie in the range from -10^8 to 10^8. There is no need to check these limits: you can rely on them when choosing the most appropriate types for your variables.

## Output format

The first number K is the number of days whose temperature value is higher than the arithmetic mean. Then K integers are the numbers of those days.

## Example

### Input

```commandline
5
5 4 1 -2 7

```

### Output

```commandline
3
0 1 4
```
