//
//  figure.cpp
//  Snowman
//
//  Created by Надия Кадерова on 22.04.2022.
//

#include "figure.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
//base figures

Circle::Circle(int x_, int y_, int r_, Fl_Color col_) : x1(x_), y1(y_), r1(r_), col(col_){}

void Circle::draw1(int x_, int y_) const
{
    fl_color(col);
    fl_pie((x1 + x_) - r1, (y1 + y_) - r1, 2 * r1, 2 * r1, 0, 360);
}

void Circle::move(){}

Circle::~Circle(){}

Eyes::Eyes(int x_, int y_, int r_, Fl_Color col_) : x1(x_), y1(y_), r1(r_), col(col_), cir(0) {}

void Eyes::draw1(int x_, int y_) const
{
    fl_color(col);
    fl_pie((x1 + x_) - r1, (y1 + y_) - r1, 2 * r1, 2 * r1, 0, 360);
}

void Eyes::move()
{
    cir = cir + 1;
    if (cir >= 360) cir = 0;
    if (cir % 2 == 0) r1++;
    else r1--;
}

Eyes::~Eyes(){}

Nose::Nose(int x1_, int y1_, Fl_Color col_) : x1(x1_), y1(y1_), col(col_){};

void Nose::draw1(int x_, int y_) const
{
    fl_color(col);
    fl_polygon((x1 + x_), (y1 + y_), (x1 + x_) - 20, (y1 + y_) + 15, (x1 + x_), (y1 + y_) - 15); //треугольник
}

void Nose::move(){}

Nose::~Nose(){}

Straight_line::Straight_line(int x_, int y_,  Fl_Color col_) : x2(x_), y2(y_), col(col_), mov(1){}

void Straight_line::draw1(int x_, int y_) const
{
    fl_line((x2 + x_), (y2 + y_), (x2 + x_) - 100, (y2 + y_) + 100);
    fl_line((x2 + x_), (y2 + y_), (x2 + x_) - 130, (y2 + y_));
    fl_line((x2 + x_), (y2 + y_), (x2 + x_) - 100, (y2 + y_) - 100);
    fl_line((x2 + x_), (y2 + y_), (x2 + x_), (y2 + y_) - 130);
    fl_line((x2 + x_), (y2 + y_), (x2 + x_) + 100, (y2 + y_) + 100);
    fl_line((x2 + x_), (y2 + y_), (x2 + x_) + 130, (y2 + y_));
    fl_line((x2 + x_), (y2 + y_), (x2 + x_) + 100, (y2 + y_) - 100);
    fl_line((x2 + x_), (y2 + y_), (x2 + x_), (y2 + y_) + 130);
}

void Straight_line::move()
{
    mov = mov + 1;
    if (mov == 4) mov = 0;
    if (mov == 0 || mov == 1) y2 = y2 + 5;
    else if (mov == 2 || mov == 3) y2 = y2 - 5;
}

Straight_line::~Straight_line(){}

Circle1::Circle1(int x_, int y_, int r_, Fl_Color col_) : x2(x_), y2(y_), r2(r_), col(col_){}

void Circle1::draw1(int x_, int y_) const
{
    fl_color(col);
    fl_pie((x2 + x_) - r2, (y2 + y_) - r2, 2 * r2, 2 * r2, 0, 360);
}

void Circle1::move() {}

Circle1::~Circle1(){}

void Snowman::draw1(int x_, int y_) const
{
    int i;
    for (i = 0; i < 6; i++)
        snow[i]->draw1(x1, y1);
}

void Snowman::move()
{
    if (to_right) {
        int x_new = x1 + 5;
        if (x_new <= 500 - r_s) {
            x1 = x_new;
        } else {
            to_right = false;
        }
    }
    int i;
    for (i = 0; i < 6; i++)
        snow[i]->move();
}

Snowman::~Snowman()
{
    for (int i = 0; i < 6; i++)
        delete snow[i];
}


void Sun::draw1(int x_, int y_) const
{
    int i;
    for (i = 0; i < 2; i++)
        sun[i]->draw1(x2, y2);
}

void Sun::move()
{
    if (to_right) {
        int x_new = x2 + 5;
        if (x_new <= 500 - r_l) {
            x2 = x_new;
        } else {
            to_right = false;
        }
    } else {
        int x_new = x2 - 5;
        if (x_new >= r_l - 200 ) {
            x2 = x_new;
        } else {
            to_right = true;
        }
    }
    int i;
    for (i = 0; i < 2; i++)
        sun[i]->move();
     
}

Sun::~Sun()
{
    for (int i = 0; i < 2; i++)
        delete sun[i];
}


