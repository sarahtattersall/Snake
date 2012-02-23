#include "Scene.hpp"
#include "CellObject.hpp"
#include "CellOccupier.hpp"
#include "SnakeDirection.hpp"
Scene::Scene(shared_ptr<Board> board, shared_ptr<Rules> rules){
    m_board = board;
    m_rules = rules;
    m_key_press = false;
    m_playing = false;

    view.resize(m_board->get_width()*SnakeObject::get_width(), m_board->get_height()*SnakeObject::get_height());
    view.setAlignment(Qt::AlignTop | Qt::AlignLeft);
    view.setScene(this);
    view.setBackgroundBrush(Qt::black);
    view.setWindowTitle("Sarah's Amazing Snake Game");
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(move_snake()));
  
    update_view();
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
    m_playing = false;
    update_view();
}

void Scene::keyPressEvent(QKeyEvent* event){
    if( event->key() == Qt::Key_R && !m_playing ){
        if(m_rules->snake_dead()){
            m_rules->reset();
            update_view();
        }
    }
    if( event->key() == Qt::Key_S && !m_playing ){
        const Snake& snake = m_rules->get_snake(0);
        m_timer->start(100*snake.get_speed());
        m_playing = true;
    } else{
        bool result;
        if(!m_key_press && m_playing){
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
                default:
                    result = m_rules->move_snake(0);
                    break;
                }
            if(!result){
                end_game();
            } else{
                m_key_press = true;
                QGraphicsScene::keyPressEvent(event);
            }
        }
    }
}

int Scene::map_to_view(int x, int size){
  return x*size;
}

void Scene::update_view(){
    QTransform transform;
    bool dead = m_rules->snake_dead();
    int players = m_rules->get_player_count();
    QGraphicsItem* item;
    for( int player = 0; player < players; ++player){
        const Snake snake = m_rules->get_snake(player);
        for (SnakeTailIterator itr = snake.begin(); itr != snake.end(); ++itr){
            Coord coord = m_board->find(*itr);
            int x = map_to_view(coord.get_x(), SnakeObject::get_width());
            int y = map_to_view(coord.get_y(), SnakeObject::get_height());
            item = itemAt(x, y, transform);
            if(!item){
                if(!dead){
                    addItem(new SnakeObject(x, y, player));
                } else{
                    addItem(new SnakeDeadObject(x, y));
                }
            }
        }
    }
    
    FoodOccupiuer* food = m_rules->get_food();
    WallOccupier* wall = m_rules->get_wall();
    
    /*for( int row = 0; row < m_board->get_height(); ++row ){
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
                // TODO: Don't like cast
                Snake* snake = (Snake *)occupier;
                if(!dead){
                    addItem(new SnakeObject(x, y, snake->get_player_number()));
                } else{
                    addItem(new SnakeDeadObject(x, y));
                }
            } else if(occupier->get_type() == CellOccupier::WALL){
                addItem(new WallObject(x, y));
            } else if(occupier->get_type() == CellOccupier::FOOD){
                addItem(new FoodObject(x, y));
            }
        }
    }*/
}
