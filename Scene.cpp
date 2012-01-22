#include "Scene.hpp"
#include "SnakeObject.hpp"
#include "CellOccupier.hpp"
Scene::Scene(shared_ptr<Board> board, shared_ptr<Rules> rules){
	m_board = board;
	m_rules = rules;
	view.resize(m_board->get_width()*SnakeObject::get_width(), m_board->get_height()*SnakeObject::get_height());
	view.setAlignment(Qt::AlignTop);
    view.setScene(this);
    view.setBackgroundBrush(Qt::black);
    view.setWindowTitle("Sarah's Amazing Snake Game");
	updateView();
    view.show();    
}

void Scene::keyPressEvent(QKeyEvent* event){
	switch(event->key()){
		case Qt::Key_Up:
			m_rules->move_snake(0, Rules::UP);
			break;
		case Qt::Key_Down:
			m_rules->move_snake(0, Rules::DOWN);
			break;
		case Qt::Key_Left:
			m_rules->move_snake(0, Rules::LEFT);
			break;
		case Qt::Key_Right:
			m_rules->move_snake(0, Rules::RIGHT);
			break;
	}
	updateView();
    QGraphicsScene::keyPressEvent(event);
}

int Scene::mapToView(int x, int size){
	return x*size;
}

void Scene::updateView(){
	QTransform transform;
	for( int row = 0; row < m_board->get_height(); ++row ){
		for( int col = 0; col < m_board->get_width(); ++col ){
			shared_ptr<CellOccupier> occupier = m_board->get(col, row).get_occupier();
			int x = mapToView(col, SnakeObject::get_width());
			int y = mapToView(row, SnakeObject::get_height());
			// Would rather remove if not snake?
			QGraphicsItem* item = itemAt(x, y, transform);
			if(item){
				removeItem(item);
				delete item;
			}
			if(occupier->get_type() == CellOccupier::SNAKE){
				addItem(new SnakeObject(x, y));
			}
		}
	}
}
