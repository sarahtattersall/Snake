#include "Scene.hpp"
#include "SnakeObject.hpp"
Scene::Scene(shared_ptr<Board> board, shared_ptr<Rules> rules){
	m_board = board;
	m_rules = rules;
	view.setAlignment(Qt::AlignTop);
    view.setScene(this);
    view.setBackgroundBrush(Qt::black);
    view.setWindowTitle("Sarah's Amazing Snake Game");
    view.show();    
}

void Scene::keyPressEvent(QKeyEvent* event){
	switch(event->key()){
		case Qt::Key_Up:
			m_rules->move_snake(0, Rules::UP);
		case Qt::Key_Down:
			m_rules->move_snake(0, Rules::DOWN);
		case Qt::Key_Left:
			m_rules->move_snake(0, Rules::LEFT);
		case Qt::Key_Right:
			m_rules->move_snake(0, Rules::RIGHT);
	}
    QGraphicsScene::keyPressEvent(event);
}