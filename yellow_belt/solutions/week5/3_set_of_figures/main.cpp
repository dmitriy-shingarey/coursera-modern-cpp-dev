#include "set_of_figures.h"
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

std::shared_ptr<Figure> CreateFigure(istringstream &is)
{
    string figure;
    is >> figure;

    if (figure == "RECT")
    {
        float width, height;
        is >> width >> height;
        return make_shared<Rect>(width, height);
    }
    else if (figure == "TRIANGLE")
    {
        float a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }
    else
    {
        float r;
        is >> r;
        return make_shared<Circle>(r);
    }
}

int main()
{
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line);)
    {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD")
        {
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT")
        {
            for (const auto &current_figure : figures)
            {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}