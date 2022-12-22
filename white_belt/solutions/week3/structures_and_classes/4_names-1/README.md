# Programming Assignment: First Names and Last Names - 1

    Implement a class for a person that maintains a history of a person's changes
    surname and first name.
    
    Consider that in each year there can be no more than one change of last name and no more than one change of first name. However, as time passes, more and more facts from the person's past can be discovered, so the years in successive calls to the ChangeLastName and ChangeFirstName methods don't have to increase.
    
    It is guaranteed that all names and surnames are non-empty.
    
    The string returned by the GetFullName method must contain a single space separated
    person's first and last name as of the end of the given year.
    
     * If no name and surname changes have occurred by the given year, return the string "Incognito".
    
     * If there was a change in the last name but no change in the first name, return "last_name with unknown first name".
    
     * If there was a name change for the given year, but there was no last name change, return "first_name with unknown last name".
