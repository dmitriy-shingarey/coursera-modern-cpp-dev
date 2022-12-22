# Programming Assignment: Monthly Tasks

    Each of us has monthly tasks, each of which must be done on a particular day of each month: paying our electric bill, paying our phone bill, etc. communications charges, etc. You need to implement work with a list of such cases,namely, to process the following operations.  
      
        *ADD is*.
        Add a task with the name s to day i.
        *NEXT*.
        End the current month and start a new month. If the new month has more days than the current month, the added days will initially have no to-do's. If the new month has fewer days, however, the cases from all days removed will need to be moved to the last day of the new month. Note that the number of commands of this type can exceed 11.
        *DUMP i*.
        Output all cases on day i.
        Initially, the current month is January. The number of days in months corresponds to the Gregorian calendar with the only difference that February always has 28 days.
