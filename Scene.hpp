#ifndef SCENE_HPP
#define SCENE_HPP

// #include "snake.hpp"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QDebug>


class Scene : public QGraphicsScene
{

    public:
        Scene();
        void keyPressEvent(QKeyEvent *event);

    private:    
        QGraphicsView view;
        QPainter painter;
        // Snake *m_snake; 
        // Food *m_food;
        
};

#endif