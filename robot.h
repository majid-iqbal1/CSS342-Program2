#ifndef ROBOT_H_
#define ROBOT_H_
#include <iostream>
#include <string>
using namespace std;

// Point class
class Point 
{
public:

    // Constructors
    Point();
    Point(int x, int y);

    // getter
    int getX() const;
    int getY() const;

private:

    // data memebers
    int x_;
    int y_;
};

// Robot class
class Robot 
{
public:

    // Constructors
    Robot();
    Robot(int max_distance, Point robot_coordinates, Point treaure_coordinates);

    //verbs
    int findPath(const Point& current,const string& path, int& distance);

    // overload operator <<
    friend ostream &operator<<(ostream &out_stream, Robot &r);

private:

    // Data members
    int north_, south_, east_, west_;
    int maximum_steps_;
    int number_of_paths_;
    int shortest_distance_;
    Point start_point_, end_point_;
};
#endif 