//
//  main.cpp
//  Snowman
//
//  Created by Надия Кадерова on 16.04.2022.
//

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include "figure.hpp"
#include "scene.hpp"

int main()
{
    Fl_Window* w = new Fl_Window(1000, 600);
    Scene *sc = new Scene();
    w->end();
    w->show();
    int code = Fl::run();
    delete sc;
    delete w;
    return code;
}


