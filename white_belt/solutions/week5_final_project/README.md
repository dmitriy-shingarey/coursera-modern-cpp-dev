# Programming Assignment: Final Course Task

    You need to write a C++ program that implements a simple database (abbreviated as "DB"). The program will communicate with the user through the standard input and output (streams stdin and stdout).

    We will store in our database pairs of the following form: date, event. Define the date as a string of the form Year-Month-Day, where Year, Month and Day are integers.

    Let's define the event as a string of arbitrary printed symbols without separators inside (spaces, tabs, etc.). The event cannot be an empty string. Many different events can occur on the same date. different events may occur on the same date and the database must be able to save them all. The same events that occurred on the same day do not need to be saved: it is enough to save only one of them.

    Our database must understand certain commands so that you can interact with it:

    All commands, dates and events are separated by spaces when entered. Commands are read from standard input. There can be exactly one command per line, but you can enter multiple commands on multiple lines. Blank lines can also come in - these should be ignored and continue to process new commands on subsequent lines.

     *Add event (Add Date Event)*
     When adding an event, the database must memorize it and then display it when searching (using the Find command) or printing (using the Print command). 
     If the specified event for the given date already exists, adding it again should be ignored. 
     In case of correct input (see chapter "Processing of input errors") the program must not display anything on the screen.
    
     *Remove Event (Del Date Event)*
     The command should delete the previously added event with the specified name on the specified date, if it exists. 
     If the event is found and deleted, the program should output the line "Deleted successfully" (without quotation marks). 
     If the event is not found on the specified date, the program should output the "Event not found" string (without quotation marks).
    
     * Deleting multiple events (Del Date)*
     The command deletes all previously added events for the specified date. The program should always output 
     Deleted N events" line, where N is the number of all events found and deleted. 
     N may be equal to zero, if there were no events on the specified date.
    
     *Find events (Find Date)*.
     Find and print the previously added events on the specified date. 
     The program should print only the events themselves, one per line. 
     The events must be sorted in ascending order in the order in which the lines are compared to each other (string type).
    
     *Print all events (Print)
     This command can be used to show the full content of our database. 
     The program must print all Date Event pairs, one per line. 
     All pairs must be sorted by date, and events within one date must 
     sorted in ascending order in order of comparison of lines to each other (string type). 
     Dates must be formatted in a special way: YYYYY-MM-DD, where Y, M, D are the digits 
     where YYYY-MM-DD are the digits of the year, month and day respectively. If any number has fewer digits, it must be 
     If any number has fewer digits, it must be padded with zeros, for example, 0001-01-01 is the first of January of the first year. You do not need to output the date 
     with a negative year.
    
     _Processing input errors_.
     Input in this task is not always correct: some input errors must be handled correctly by your program.

     What input errors should be handled:
    
      * If the user has entered an unknown command, the program should report this by displaying the line 
      'Unknown command: COMMAND', where COMMAND is the command the user entered. '
      The command is the first word in the line (before the space).

      * If the date does not match the format Year-Month-Day where Year, Month and Day are arbitrary integers, 
      The program should print "Wrong date format: DATE", where DATE is what the user entered instead of 
      date (before the space). Note that parts of the date are separated by exactly one hyphen, and the date itself should not 
      must not contain extra characters in front of the year or after the day. The date parts cannot be empty, but can be 
      zero or even negative.

      * If the date format is correct, you must check the validity of the month and day.

      * If the month number is not a number between 1 and 12, print "Month value is invalid: MONTH", 
      where MONTH is an invalid month number, e.g. 13 or -1.
    
      * If the month is correct and the day is not between 1 and 31, print "Day value is invalid: DAY", 
      where DAY is an invalid day number in the month, for example, 39 or 0.

    Note that:

    The year value does not need to be checked separately. There is no need to check the calendar correctness of the date: the number of days in each month is assumed to be 31, leap years do not need to be taken into account. If both month and day are incorrect, you should print one error message per month.
