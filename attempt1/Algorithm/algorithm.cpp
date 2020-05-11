//
// Created by markose on 5/10/20.
//

#include "algorithm.h"
#include <iostream>
#include "../API/api.h"

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
    width = fp::API::mazeWidth();
    height = fp::API::mazeHeight();
    dir = 'n';
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
            if(dir=='n')
            {
                dir='w';
            }
            else if (dir=='w')
            {
                dir='s';
            }
            else if(dir=='s')
            {
                dir='e';
            }
            else if(dir=='e')
            {
                dir='n';
            }

        }
        while (fp::API::wallFront()) {
            fp::API::turnRight();
            if(dir=='n')
            {
                dir='e';
            }
            else if(dir=='w')
            {
                dir='n';
            }
            else if(dir=='s')
            {
                dir='w';
            }
            else if(dir=='e')
            {
                dir='s';
            }
        }
        fp::API::moveForward();
        if(dir=='n')
        {
            n = n + 1;
        }
        else if(dir=='e')
        {
            m = m + 1;
        }
        else if(dir=='s')
        {
            n = n - 1;
        }
        else if(dir=='w')
        {
            m = m - 1;
        }
        if(fp::API::wallLeft())
        {
            if(dir=='n')
            {
                direc='w';
            }
            else if(dir=='w')
            {
                direc='s';
            }
            else if(dir=='s')
            {
                direc='e';
            }
            else if(dir=='e')
            {
                direc='n';
            }
            fp::API::setWall(m,n,direc);

        }
        if(fp::API::wallRight())
        {
            if(dir=='n')
            {
                direc='e';
            }
            else if(dir=='w')
            {
                direc='n';
            }
            else if(dir=='s')
            {
                direc='w';
            }
            else if(dir=='e')
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