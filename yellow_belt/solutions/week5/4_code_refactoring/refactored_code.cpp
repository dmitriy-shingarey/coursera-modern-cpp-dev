#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
protected:
    const string Name;
    const string Type;

public:
    Person(string type, string name) : Type(type), Name(name){};
    void virtual Walk(string destination) const = 0;
    string GetName() const
    {
        return Name;
    }
    string GetType() const
    {
        return Type;
    }
};

class Student : public Person
{
public:
    Student(string name, string favouriteSong) : Person("Student", name), FavouriteSong(favouriteSong){};

    void Learn() const
    {
        cout << "Student: " << Name << " learns" << endl;
    }

    void Walk(string destination) const override
    {
        cout << Type << ": " << Name << " walks to: " << destination << endl;
        cout << Type << ": " << Name << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() const
    {
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

private:
    string FavouriteSong;
};

class Teacher : public Person
{
public:
    Teacher(string name, string subject) : Person("Teacher", name), Subject(subject){};

    void Teach() const
    {
        cout << Type << " " << Name << " teaches : " << Subject << endl;
    }

    void Walk(string destination) const override
    {
        cout << Type << ": " << Name << " walks to: " << destination << endl;
    }

private:
    const string Subject;
};

class Policeman : public Person
{
public:
    Policeman(string name) : Person("Policeman", name){};

    void Check(Person &p)
    {
        cout << Type << " " << Name << " checks " << p.GetType() << ". " << p.GetType() << "'s name is: " << p.GetName() << endl;
    }

    void Walk(string destination) const override
    {
        cout << Type << ": " << Name << " walks to: " << destination << endl;
    }
};

void VisitPlaces(Person &person, vector<string> places)
{
    for (auto p : places)
    {
        person.Walk(p);
    }
}

int main()
{
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
