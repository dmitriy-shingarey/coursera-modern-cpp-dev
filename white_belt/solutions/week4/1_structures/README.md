# Programming Assignment: LectureTitle Structure

    This is the LectureTitle structure:
    
     struct LectureTitle {
      string specialization;
      string course;
      string week;
     };
    
    Complete the constructor and structures Specialization, Course, Week,
    so that the LectureTitle object can be created using the code:
    
     LectureTitle title(
      Specialization("C++"),
      Course("White belt"),
      Week("4th")
     );
    
    but you couldn't with the following code snippets:
    
     LectureTitle title("C++", "White belt", "4th");
    
     LectureTitle title(string("C++"), string("white belt"), string("4th"));
    
     LectureTitle title = {"C++", "White belt", "4th"};
    
     LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
    
     LectureTitle title(
      Course("White belt"),
      Specialization("C++"),
      Week("4th")
     );
    
     LectureTitle title(
         Specialization("C++"),
         Week("4th"),
         Course("White belt")
     );
