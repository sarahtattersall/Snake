#include "Scene.hpp"
#include "FoodObject.hpp"
#include "SnakeObject.hpp"
#include "WallObject.hpp"
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
    m_timer->start(200);

    view.show();    
}

Scene::~Scene(){
    delete m_timer;
}

void Scene::move_snake(){
	bool result = true;
    if(!m_key_press){
        result = m_rules->move_snake(0);
    }
    update_view();
    m_key_press = false;
	if(!result){
		end_game();
	}
}

void Scene::end_game(){
	m_timer->stop();
}

void Scene::keyPressEvent(QKeyEvent* event){
	bool result;
	if(!m_key_press){
		switch(event->key()){
			case Qt::Key_Up:
				result = m_rules->move_snake(0, Coord::UP);
				break;
			case Qt::Key_Down:
				result = m_rules->move_snake(0, Coord::DOWN);
				break;
			case Qt::Key_Left:
				result = m_rules->move_snake(0, Coord::LEFT);
				break;
			case Qt::Key_Right:
				result = m_rules->move_snake(0, Coord::RIGHT);
				break;
		}
		if(!result){
			end_game();
		}else{
			m_key_press = true;
		    QGraphicsScene::keyPressEvent(event);
		}
	}
}

int Scene::map_to_view(int x, int size){
	return x*size;
}

void Scene::update_view(){
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
			} else if(occupier->get_type() == CellOccupier::WALL){
				addItem(new WallObject(x, y));
			} else if(occupier->get_type() == CellOccupier::FOOD){
				addItem(new FoodObject(x, y));
			}
		}
	}
}
