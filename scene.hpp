//
//  scene.hpp
//  Snowman
//
//  Created by Надия Кадерова on 22.04.2022.
//

#ifndef scene_hpp
#define scene_hpp
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include "figure.hpp"
enum { k = 2 };

class Scene : public Fl_Box
{
    Figure *figure[k];
    static void timer_handler(void *data);
public:
    Scene();
    ~Scene();
    void draw();
    void move();
};



#endif /* scene_hpp */
