#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include "libs/Point.cpp"
#include "libs/utils.cpp"
#include "libs/Field.cpp"

//build :time g++ ./lab.cpp -o labGen -O3


int main(int argc, char*argv[])
{
    int width,height;

    //set seed for random function
    //you can delte this string but then maze always will be same 
   // srand (timeSinceEpochMillisec());


    //parsing argv part
    if(argc<3)
    {
        cout << "usage: ./labGen width height" << endl;
        exit(0);
    }

    width = atoi(argv[1]);

    height = atoi(argv[2]);

    //creating lab part
    Field maze(width,height);
    //you can also get vectors of points by call "maze.table"
    maze.print_table();
}