//
// Created by markose on 5/10/20.
//

#include "algorithm.h"
#include <iostream>
#include "../API/api.h"
#include "../Direction/direction.h"

void fp::algorithm::log(const std::string& text)
{
    std::cerr << "\n" << text;
}
void fp::algorithm::displayNumber(const int num)
{
    std::cerr << num << std::endl;
}


void fp::algorithm::solve()
{
    Direction dirc;

//    char dir;
    // how to set direction
    dir = dirc.NORTH;
//    dir = dirc.SOUTH;
    width = fp::API::mazeWidth();
    height = fp::API::mazeHeight();
//    dir = 'n';
    direc = 'w';
    m = 0;
    n = 0;
    fp::algorithm::log("running...");
    fp::algorithm::log("Width is :");
    fp::algorithm::displayNumber(width);
    fp::algorithm::log("height is :");
    fp::algorithm::displayNumber(height);
//    std::cout<<width<<std::endl;
//    std::cout<<height<<std::endl;
    fp::API::setColor(0,0,'G');
    fp::API::setText(0, 0, "S");
    fp::API::setColor(7,7,'Y');
    fp::API::setText(7, 7, "G");
    for (int i = 0; i<width; i += 1){
        for (int j = 0; j<height; j += 1){
            if(i==0)
            {
                fp::API::setWall(i,j,'w');
            }
            if(j==0)
            {
                fp::API::setWall(i,j,'s');
            }
            if(i==width-1)
            {
                fp::API::setWall(i,j,'e');
            }
            if(j==width-1)
            {
                fp::API::setWall(i,j,'n');
            }
        }
    }
    while (true) {
        if (!fp::API::wallLeft()) {
            fp::API::turnLeft();
            if(dir==dirc.NORTH)
            {
                dir=dirc.WEST;
            }
            else if (dir==dirc.WEST)
            {
                dir=dirc.SOUTH;
            }
            else if(dir==dirc.SOUTH)
            {
                dir=dirc.EAST;
            }
            else if(dir==dirc.EAST)
            {
                dir=dirc.NORTH;
            }

        }
        while (fp::API::wallFront()) {
            fp::API::turnRight();
            if(dir==dirc.NORTH)
            {
                dir=dirc.EAST;
            }
            else if(dir==dirc.WEST)
            {
                dir=dirc.NORTH;
            }
            else if(dir==dirc.SOUTH)
            {
                dir=dirc.WEST;
            }
            else if(dir==dirc.EAST)
            {
                dir=dirc.SOUTH;
            }
        }
        fp::API::moveForward();
        if(dir==dirc.NORTH)
        {
            n = n + 1;
        }
        else if(dir==dirc.EAST)
        {
            m = m + 1;
        }
        else if(dir==dirc.SOUTH)
        {
            n = n - 1;
        }
        else if(dir==dirc.WEST)
        {
            m = m - 1;
        }
        if(fp::API::wallLeft())
        {
            if(dir==dirc.NORTH)
            {
                direc='w';
            }
            else if(dir==dirc.WEST)
            {
                direc='s';
            }
            else if(dir==dirc.SOUTH)
            {
                direc='e';
            }
            else if(dir==dirc.EAST)
            {
                direc='n';
            }
            fp::API::setWall(m,n,direc);

        }
        if(fp::API::wallRight())
        {
            if(dir==dirc.NORTH)
            {
                direc='e';
            }
            else if(dir==dirc.WEST)
            {
                direc='n';
            }
            else if(dir==dirc.SOUTH)
            {
                direc='w';
            }
            else if(dir==dirc.EAST)
            {
                direc='s';
            }
            fp::API::setWall(m,n,direc);
        }
        if(fp::API::wallFront())
        {
            fp::API::setWall(m,n,dir);
        }

    }

}