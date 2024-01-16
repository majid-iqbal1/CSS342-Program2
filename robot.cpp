#include "robot.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//Global static for string vector compass that save the value of N, S, W, E in recursive function
static vector<string> compass_;

//Point default constructor
Point::Point()
{
    x_ = 0;
    y_ = 0;
}

//Constructor creates a point object
Point::Point(int x, int y)
{
    x_ = x;
    y_ = y;
}

// Function to get x coordinate
int Point::getX() const
{
    return x_;
};

// Function to get x coordinate
int Point::getY() const
{
    return y_;
};

// Deafut Robot constrctor to initialize the values
Robot::Robot()
{
    maximum_steps_ = 0;
    start_point_ = Point();
    end_point_ = Point();
    number_of_paths_ = 0;
    shortest_distance_ = 0;
}
// Robot constructor to initialize the values
Robot::Robot(int max_distance, Point robot_coordinates, Point treaure_coordinates)
    : maximum_steps_(max_distance), start_point_(robot_coordinates), end_point_(treaure_coordinates), number_of_paths_(0), north_(max_distance), south_(max_distance), east_(max_distance), west_(max_distance), shortest_distance_(abs(robot_coordinates.getX() - treaure_coordinates.getX()) + abs(robot_coordinates.getY() - treaure_coordinates.getY()))
{
    number_of_paths_ += findPath(start_point_, "", shortest_distance_);
}

// Recursive function to determine the path along shortest distance and number of path
int Robot::findPath(const Point& current, const string& path, int& distance)
{
    // if statement checks if robot's coordinate are same as treasure's.
    if (current.getX() == end_point_.getX() && current.getY() == end_point_.getY())
    {
        // Add string path to compass vector
        compass_.push_back(path);
        distance = min(distance, shortest_distance_);
        return 1;
    }

    int currSteps = 0;

    // this if statement checks the y coordinates of treasure is bigger than robot's and then robot y moves a value up in recursive function call.
    if (current.getY() < end_point_.getY() && north_ > 0)
    {
        Robot newRobot(*this);
        newRobot.north_--;
        newRobot.south_ = maximum_steps_;
        newRobot.west_ = maximum_steps_;
        newRobot.east_ = maximum_steps_;
        currSteps += newRobot.findPath(Point(current.getX(), current.getY() + 1), path + "N↑ ", distance);
    }

    // this if statement checks the y coordinates of treasure is smaller than robot's and then robot y moves a value down in recursive function call.
    if (current.getY() > end_point_.getY() && south_ > 0)
    {
        Robot newRobot(*this);
        newRobot.south_--;
        newRobot.north_ = maximum_steps_;
        newRobot.west_ = maximum_steps_;
        newRobot.east_ = maximum_steps_;
        currSteps += newRobot.findPath(Point(current.getX(), current.getY() - 1), path + "S↓ ", distance);
    }

    // // this if statement checks the x coordinates of treasure is bigger than robot's and then robot x moves a value up in recursive function call.
    if (current.getX() < end_point_.getX() && east_ > 0)
    {
        Robot newRobot(*this);
        newRobot.east_--;
        newRobot.north_ = maximum_steps_;
        newRobot.west_ = maximum_steps_;
        newRobot.south_ = maximum_steps_;
        currSteps += newRobot.findPath(Point(current.getX() + 1, current.getY()), path + "E→ ", distance);
    }

    // this if statement checks the x coordinates of treasure is smaller than robot's and then robot x moves a value down in recursive function call.
    if (current.getX() > end_point_.getX() && west_ > 0)
    {
        Robot newRobot(*this);
        newRobot.west_--;
        newRobot.north_ = maximum_steps_;
        newRobot.south_ = maximum_steps_;
        newRobot.east_ = maximum_steps_;
        currSteps += newRobot.findPath(Point(current.getX() - 1, current.getY()), path + "W← ", distance);
    }
    return currSteps;
}

// ostream operator to print paths, shortest distance, and number of path.
ostream &operator<<(ostream &out_stream, Robot &r)
{
    if (r.number_of_paths_ == 0) {
        cout << "Error! No paths have been found! Try different coordinates or try changing the max distance limit " << endl;
    }
    for (int i = 0; i < compass_.size(); ++i) {
        out_stream << compass_[i] << endl;
    }  
    out_stream << "(Shortest distance: " << r.shortest_distance_ << " , Number of paths: " << r.number_of_paths_ << " ) "<<endl;
    return out_stream;
}
