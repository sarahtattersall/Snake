#include "Scene.hpp"
#include "SnakeObject.hpp"
Scene::Scene()
{
    // addItem(new SnakeObject(0, 0));   
	view.setAlignment(Qt::AlignTop);
    view.setScene(this);
    view.setBackgroundBrush(Qt::black);
    view.setWindowTitle("Sarah's Amazing Snake Game");
    view.show();    
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    QGraphicsScene::keyPressEvent(event);
    
}