# Technique for Managing Functions and Containers

## [Programming Assignment: Factorial](01_factorial)

Write a function that:

* is called Factorial
* returns int
* takes in an int and returns the factorial of its argument.
* It is guaranteed that the argument of the function does not exceed 10 in modulus.
* For negative arguments, the function should return 1.

## [Programming Assignment: Palindrome](02_palindrom)

Write a function that:

* is called IsPalindrome
* returns bool
* takes in a string parameter and returns whether the passed string is a palindrome
A palindrome is a word or phrase that is read the same way from left to right and right to left. An empty string is a palindrome.

## [Programming Assignment: Selection of Palindromes](selecting_palindroms)

Write a function that:

* is called PalindromeFilter
* returns ```vector<string>```
* takes in a ```vector<string>``` called ```words``` and an ```int``` called ```minLength``` and returns all strings from the words vector that are palindromes and have a length of at least minLength

## [Programming Assignment: Move Strings](05_move_strings)

Write a MoveStrings function that takes two vectors of strings, source and destination,
and adds all the strings from the first vector to the end of the second.
After executing the function, the vector source should be empty.

## [Programming Assignment: Reversing a Sequence](reverse)

Implement the function void Reverse(vector<int>& v) that rearranges the elements of the vector in reverse order.

## [Programming Training Assignment: Average Temperature](10_average_temperature)

Given the temperature values observed for N consecutive days. Find the day numbers (in a zero-based numbering) with a temperature value higher than the arithmetic mean for all N days.

It is guaranteed that the arithmetic mean of the temperature values is an integer.

### Input Format

An integer N is input, followed by N non-negative integers representing the temperature values for the 0th, 1st, ... (N-1)th day.

### Output Format

The first number K is the number of days with a temperature value higher than the arithmetic mean.
Then K integers follow, representing the numbers of these days.

## [Programming Assignment: Queue](queue)

People stand in a queue, but never leave its beginning, but can come to the end and leave from there.
Moreover, sometimes some people may stop and become worried because the queue is not moving.

Implement processing of the following operations on the queue:

* WORRY i: mark the i-th person from the beginning of the queue (numbered from 0) as worried;
* QUIET i: mark the i-th person as quiet;
* COME k: add k quiet people to the end of the queue;
* COME -k: remove k people from the end of the queue;
* WORRY_COUNT: find out the number of worried people in the queue.

Initially, the queue is empty.

### Input format

The number of operations Q, and then the descriptions of the operations.

For each operation WORRY i and QUIET i it is guaranteed that the person with number i exists in the queue at the time of the operation.

For each operation COME -k it is guaranteed that k is not greater than the current size of the queue.

### Output format

For each operation WORRY_COUNT, output the number of worried people.

## [Programming Assignment: Monthly Tasks](11_monthly_tasks)

We all have repeating monthly tasks that need to be completed on a specific day of each month:
paying electric bills, monthly communication fees, etc.
You need to implement work with a list of such tasks for a month, namely, to implement the following operations:

* ADD i s: Assign a task with the name s on day i of the current month.
* DUMP i: Output all tasks planned for day i of the current month.
* NEXT: Move to the list of tasks for a new month.

Upon executing this command, a new (active) list of tasks for the next month is created and becomes active in place of the current (old) list of tasks for the current month: all tasks from the old list are copied to the new list. After executing this command, the new list of tasks and the next month become current, and work with the old list of tasks stops.
The number of days in the new month can be different from the number of days in the old month. In this case, all tasks scheduled for days outside the range of the new month will be discarded.

### Input format

The first line contains the number of operations n (1 ≤ n ≤ 100). Then n lines follow, each containing the description of the operation in one of the above formats.

### Output format

For each DUMP operation, output the tasks planned for the specified day of the month on a separate line in the format day i: task1, task2, …, taskk, where i is the number of the day, and task1, task2, …, taskk are the tasks planned for this day (in the order they were added).
Tasks are separated by a comma and a space.

## [Programming Assignment: Anagrams](map_container/anagramms)

Words are called anagrams of each other if one of them can be obtained by rearranging the letters of the other.
For example, the word "eat" can be obtained by rearranging the letters of the word "tea", so these words are anagrams of each other.
Given pairs of words, check for each one if the words of the pair are anagrams of each other.

### Instruction

One way to check if words are anagrams of each other is as follows.
For each word, count the number of times each letter appears in it using a dictionary.
If these dictionaries are equal for both words (which is checked using the ordinary == operator),
then the words are anagrams of each other, otherwise they are not.

It is convenient to put the construction of such a dictionary for a word into a separate function BuildCharCounters.

### Input Format

First, given the number of word pairs N, then N pairs of words follow, each on a new line.
Words consist of lowercase Latin letters and are separated by spaces.

### Output Format

For each pair of words, output YES if the words are anagrams of each other, otherwise output NO.

## [Programming Assignment: Capital Directory](capitals_catalogue)

Implement a directory of the capitals of countries.

The program receives the following queries as input:

* **CHANGE_CAPITAL** ***country new_capital*** - change the capital of the country country to new_capital,
or adding a country with this capital, if it was not there before.
* **RENAME** ***old_country_name new_country_name*** - renaming the country from old_country_name to new_country_name.
* **ABOUT** ***country*** - output of the capital of country country.
**DUMP** - outputs capitals of all countries.

### **Input format**

The first line contains the number of queries Q, the following Q lines contain the query descriptions.
All names of countries and capitals consist only of Latin letters, numbers and underscores.

### **Output format**

Print the result of each query:

As a response to the query **CHANGE_CAPITAL** ***country new_capital*** output

* **Introduce new country** ***country*** **with capital** ***new_capital*** if ***country*** did not exist before;
* **Country** ***country*** **hasn't changed its capital**, if the country ***country*** had a capital ***new_capital*** until now;
* **Country** ***country*** **has changed its capital from** ***old_capital*** **to** ***new_capital***,
if ***country***country***had***old_capital***capital until now, which name is not the same as***new_capital***.

As a response to the request **RENAME** ***old_country_name new_country_name*** print
**Incorrect rename, skip** if the new country name matches the old one,
country ***old_country_name*** does not exist or country ***new_country_name*** already exists;

* **Country** ***old_country_name*** **with capital** ***capital*** **has been renamed to** ***new_country_name***,
if the request is correct and the country has capital ***capital***.

As a response to the request **ABOUT** ***country*** print

* **Country** ***country*** *doesn't exist** if the country with the name***country*** does not exist;
* **Country** ***country*** *has capital*****capital***if the country***country***exists and has capital***capital***.

As a response to the **DUMP** prompt print
**There are no countries in the world** if no country has been added yet;

* ***country/capital*** pairs sequence describing the capitals of all the countries if there is at least one country in the world.
When outputting the sequence, the pairs of the specified type must be ordered by the country name and separated by a space.

## [Programming Assignment: Bus Stops - 1](map_container/bus_stops)

Implement a system for storing bus routes.
You need to process the following requests:

* **NEW_BUS** ***bus stop_count stop1 stop2 ...*** - add a bus route
with name bus and stop_count stops with names ***stop1, stop2, ...***
**BUSES_FOR_STOP** ***stop*** - display names of all bus routes that pass through the stop ***stop***.
***STOPS_FOR_BUS** ***bus*** - display names of all bus stops with the list of buses,
which can be switched at each of the stops.
**ALL_BUSES** - output the list of all routes with stops.

### **Input format**

The first line of the input contains the number of Q requests, then Q lines contain the descriptions of the requests.

It is guaranteed that all route and stop names consist only of Latin letters, numbers and underscores.

For each query **NEW_BUS** ***bus stop_count stop1 stop2 ...*** it is guaranteed
that there is no ***bus*** route, the number of stops is greater than 0,
and the number ***stop_count*** is followed by exactly that number of stop names, and all the names in each list are different.

### **Format of output**

For each query except **NEW_BUS**, print the corresponding response to it:

* For **BUSES_FOR_STOP** request ***stop*** print the list of buses
passing through the stop in the order in which they were created by the **NEW_BUS** commands.
If a ***stop*** does not exist, output **No stop**.
* When requested **STOPS_FOR_BUS** ***bus***, output the descriptions of the ***bus*** stops on separate lines in the order they were created with the **NEW_BUS** commands,
in the order in which they have been given in the corresponding command **NEW_BUS**.
The description of each ***stop*** should look like **Stop** ***stop: bus1 bus2 ...***,
where ***bus1 bus2 ...*** is the list of buses passing through the stop ***stop***,
in the order in which they were created with the commands **NEW_BUS**, except the original route ***bus***.
If no buses other than ***bus*** pass through the stop ***stop***,
print **no interchange** instead of the list of buses for it. If no ***bus*** route exists, output **No bus**.
* At **ALL_BUSES**, print descriptions of all buses in alphabetical order.
The description of each ***bus*** route must have the form **Bus** ***bus: stop1 stop2 ...***,
where ***stop1 stop2 ...*** is the list of bus stops ***bus*** in the order
in the order in which they were asked in the corresponding command **NEW_BUS**. If there are no buses, print **No buses**.

## [Programming Assignment: Synonyms](set_container/synonyms)

Two words are called synonyms for each other if they have similar meanings.
Implement the following operations on the synonym dictionary:

* **ADD** ***word1 word2*** - add a pair of synonyms (word1, word2) to the dictionary.
* **COUNT** ***word*** - get the number of synonyms for the word ***word***.
* **CHECK** ***word1 word2*** - check whether ***word1*** and ***word2*** are synonyms.
The words ***word1*** and ***word2*** are considered synonyms if there was at least one **ADD** among the queries
**ADD** ***word1*** ***word2*** or **ADD** ***word2*** ***word1***.

### **Note**

For simplicity, we will assume that synonyms have no transitivity, that is, if A is a synonym of B
and B is synonymous with C, it does NOT follow that A is synonymous with C.

### **Input format**

First the number of queries Q is entered, then Q rows with query descriptions.
It is guaranteed that in each CHECK and ADD query the words word1 and word2 are different.
All words consist only of Latin letters, numbers and underscores.

### **Output format**

For each query print its answer on the corresponding line:

* In response to the query **COUNT** ***word*** print a single integer - the number of synonyms for the word ***word***.
* As a response to the **CHECK** ***word1*** ***word2*** query, output the string **YES**,
if ***word1*** and ***word2*** are synonyms, and **NO** otherwise.
