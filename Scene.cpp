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
	update_view();

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(move_snake()));
    m_timer->start(1000);

    view.show();    
}

Scene::~Scene(){
    delete m_timer;
}

void Scene::move_snake(){
    if(!m_key_press){
        m_rules->move_snake(0);
    }
    update_view();
    m_key_press = false;
}

void Scene::keyPressEvent(QKeyEvent* event){
	switch(event->key()){
		case Qt::Key_Up:
			m_rules->move_snake(0, Coord::UP);
			break;
		case Qt::Key_Down:
			m_rules->move_snake(0, Coord::DOWN);
			break;
		case Qt::Key_Left:
			m_rules->move_snake(0, Coord::LEFT);
			break;
		case Qt::Key_Right:
			m_rules->move_snake(0, Coord::RIGHT);
			break;
	}
    m_key_press = true;
    QGraphicsScene::keyPressEvent(event);
}

int Scene::map_to_view(int x, int size){
	return x*size;
}

void Scene::update_view(){
	//m_log->Write("Entering updateView");
	QTransform transform;
	for( int row = 0; row < m_board->get_height(); ++row ){
		for( int col = 0; col < m_board->get_width(); ++col ){
			CellOccupier* occupier = m_board->lookup(Coord(col, row));
			int x = map_to_view(col, SnakeObject::get_width());
			int y = map_to_view(row, SnakeObject::get_height());
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
	//m_log->Write("Leaving updateView");
}
