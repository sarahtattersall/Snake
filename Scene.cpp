#include "Scene.hpp"
#include "SnakeObject.hpp"
#include "CellOccupier.hpp"
#include "SnakeDirection.hpp"
Scene::Scene(shared_ptr<Board> board, shared_ptr<Rules> rules){
	m_board = board;
	m_rules = rules;
    m_key_press = false;
	view.resize(m_board->get_width()*SnakeObject::get_width(), m_board->get_height()*SnakeObject::get_height());
	view.setAlignment(Qt::AlignTop);
    view.setScene(this);
    view.setBackgroundBrush(Qt::black);
    view.setWindowTitle("Sarah's Amazing Snake Game");
	updateView();

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(move_snake()));
    m_timer->start(1000);

    view.show();    
}

Scene::~Scene(){
    delete m_timer;
}

// TODO FIX THIS ONCE MADE A SNAKE HEAD THAT KNOWS ITS DIRECTION
void Scene::move_snake(){
    if(!m_key_press){
        m_rules->move_snake(0, m_board->get_snake_head()->get_direction());
    }
    updateView();
    m_key_press = false;
}

void Scene::keyPressEvent(QKeyEvent* event){
	switch(event->key()){
		case Qt::Key_Up:
			m_rules->move_snake(0, SnakeDirection::UP);
			break;
		case Qt::Key_Down:
			m_rules->move_snake(0, SnakeDirection::DOWN);
			break;
		case Qt::Key_Left:
			m_rules->move_snake(0, SnakeDirection::LEFT);
			break;
		case Qt::Key_Right:
			m_rules->move_snake(0, SnakeDirection::RIGHT);
			break;
	}
    m_key_press = true;
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
