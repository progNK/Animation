//
//  scene.cpp
//  Snowman
//
//  Created by Надия Кадерова on 22.04.2022.
//

#include "scene.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
//enum { k = 2, };

void Scene::timer_handler(void *data)
{
    Scene *this_handler = (Scene *) data;
    this_handler->move();
    this_handler->redraw();
    Fl::repeat_timeout(0.1, timer_handler, data);
}

Scene::Scene() : Fl_Box(FL_FLAT_BOX, 0, 0, 1000, 600, nullptr)
{
    figure[0] = new Snowman(x_s, y_s);
    figure[1] = new Sun(x_l, y_l);
    Fl::add_timeout(0.1, timer_handler, this);
}

Scene::~Scene()
{
    int i;
    for (i = 0; i < k; i++)
        delete figure[i];
}

void Scene::draw()
{
    Fl_Box::draw();
    int i;
    for (i = 0; i < k; i++)
        figure[i]->draw1(0, 0);
}

void Scene::move()
{
    int i;
    for (i = 0; i < k; i++)
        figure[i]->move();
}

//////////////////////

