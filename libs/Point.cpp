
struct Point
{
    int x;
    int y;

    //this function check does point belong to range 
    //from 0 to maxx by x and from 0 to maxy by y
    inline bool inRange(int ,int);
    //return sum of points a and b (it's x and y cords)
    Point operator+(Point);
    //compare points 
    bool operator==(Point);
};

bool Point::inRange(int maxx,int maxy)
{
    return (
            this->x < maxx && 
            this->y < maxy &&
            this->y >= 0 &&
            this->x >= 0 
            );
}

//operators
Point Point::operator+(Point elsePoint)
{
    return Point{this->x + elsePoint.x, this->y + elsePoint.y};
}

bool Point::operator==(Point elsePoint){
    return this->x == elsePoint.x && this->y == elsePoint.y;
}
