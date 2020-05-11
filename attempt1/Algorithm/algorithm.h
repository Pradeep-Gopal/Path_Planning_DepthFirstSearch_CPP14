

#pragma once
#include<string>

namespace fp {
    class algorithm {

    public:

        void solve();
        int width;
        int height;
        char dir;
        char direc;
        int m;
        int n;
        void log(const std::string& text);
        void displayNumber(int num);

    };
}