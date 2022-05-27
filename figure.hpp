//
//  figure.hpp
//  Snowman
//
//  Created by Надия Кадерова on 22.04.2022.
//

#ifndef figure_hpp
#define figure_hpp

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

enum {
    x_s = 100,
    y_s = 150,
    x_l = 400,
    y_l = 50,
    r_s = 40,
    r_l = 65,
    f_l = true,
    f_s = true,
    col_s = FL_WHITE,
    col_l = FL_YELLOW,
    l = 900
};

class Figure
{
protected:
    int x, y;
public:
    virtual void draw1(int x_, int y_) const = 0;
    virtual void move() = 0;
    virtual ~Figure() {};
};

//base figures
class Circle : public Figure
{
    int x1, y1, r1;
    Fl_Color col;
public:
    Circle(int x_, int y_, int r_, Fl_Color col_);
    void draw1(int x_, int y_) const;
    void move();
    virtual ~Circle();
};

class Nose: public Figure
{
    int x1, y1;
    Fl_Color col;
public:
    Nose(int x1_, int y1_, Fl_Color col_);
    void draw1(int x_, int y_) const;
    void move();
    virtual ~Nose();
};

class Straight_line : public Figure
{
    int x2, y2;
    Fl_Color col;
    int mov;
public:
    Straight_line(int x_, int y_, Fl_Color col_);
    void draw1(int x_, int y_) const;
    void move();
    virtual ~Straight_line();
};

class Circle1 : public Figure
{
    int x2, y2, r2;
    Fl_Color col;
public:
    Circle1(int x_, int y_, int r_, Fl_Color col_);
    void draw1(int x_, int y_) const;
    void move();
    virtual ~Circle1();
};

class Eyes : public Figure
{
    int x1, y1, r1;
    Fl_Color col;
    int cir;
public:
    Eyes(int x_, int y_, int r_, Fl_Color col_);
    void draw1(int x_, int y_) const;
    void move();
    virtual ~Eyes();
};

//objects
class Snowman : public Figure
{
    int x1, y1;
    Fl_Color col;
    bool to_right;
    Figure *snow[6];
public:
    Snowman(int x_, int y_) : x1(x_), y1(y_), to_right(true)
    {
        snow[0] = new Circle(x_s, y_s, r_s, col_s);
        snow[1] = new Circle(x_s, y_s + 90, r_s + 15, col_s);//средний
        snow[2] = new Circle(x_s, y_s + 190, r_s + 25, col_s);//нижний
        snow[3] = new Eyes(x_s - 15, y_s - 10, r_s - 32, FL_BLACK);//глаза
        snow[4] = new Eyes(x_s + 15, y_s - 10, r_s - 32, FL_BLACK);
        snow[5] = new Nose(x_s, y_s + 5, FL_DARK_RED);
    }
    void draw1(int x_, int y_) const;
    void move();
    virtual ~Snowman();
};

class Sun : public Figure
{
    int x2, y2, r;
    bool to_right;
    Figure *sun[2];
public:
    Sun(int x_, int y_) : x2(x_), y2(y_), to_right(true)
    {
        sun[0] = new Circle1(x_l, y_l, r_l, col_l);
        sun[1] = new Straight_line(x_l, y_l, col_l);
    }
    void draw1(int x_, int y_) const;
    void move();
    virtual ~Sun();
};

#endif /* figure_hpp */
