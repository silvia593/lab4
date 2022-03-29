#ifndef REGRESSION_HPP
#define REGRESSION_HPP

#include <stdexcept>
#include <vector>


struct Result {
    double A {};
    double B {};
};

class Regression{
    private:
    struct Point{
        double x;
        double y;
    };
    std::vector<Point> points_;

    public:
    int size() const;

    void add (double x, double y);
     
    Result fit () const;
};


auto fit(Regression const &reg);



#endif