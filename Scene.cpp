#include "Scene.hpp"
#include "CellOccupier.hpp"
#include "SnakeDirection.hpp"

#include <algorithm>
Scene::Scene(shared_ptr<Board> board, shared_ptr<Rules> rules)
        : m_transform(), m_last_objects(){
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
    display_board();
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
        const Snake* snake = m_rules->get_snake(0);
        m_timer->start(100*snake->get_speed());
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

Coord Scene::get_scene_coord(const CellOccupier* occupier){
    Coord coord = m_board->find(occupier);
    int x = map_to_view(coord.get_x(), SnakeObject::get_width());
    int y = map_to_view(coord.get_y(), SnakeObject::get_height()); 
    return Coord(x,y);
}
QGraphicsItem* Scene::find_item(Coord coord){
    return itemAt(coord.get_x(), coord.get_y(), m_transform);
}

void Scene::add_object(QGraphicsItem* obj, set<QGraphicsItem*>* new_objects){
    addItem(obj);
    if (new_objects){
        new_objects->insert(obj);
    }
}

void Scene::update_view(){
    set<QGraphicsItem*> new_objects;
    bool dead = m_rules->snake_dead();
    int players = m_rules->get_player_count();
    QGraphicsItem* item;
    Coord coord;
    for( int player = 0; player < players; ++player){
        const Snake* snake = m_rules->get_snake(player);
        for (SnakeIterator itr = snake->begin(); itr != snake->end(); ++itr){
            coord = get_scene_coord(*itr);
            item = find_item(coord);
            if(!dead){
                if (!item){
                    add_object(new SnakeObject(coord, player), &new_objects);
                } else{
                    new_objects.insert(item);
                }
            } else{
                if (item){
                    //removeItem(item);
                    // delete(item);
                }
                add_object(new SnakeDeadObject(coord), &new_objects);
            }
        }
    }
    coord = get_scene_coord(m_rules->get_food());
    item = find_item(coord);
    if(!item){
        add_object(new FoodObject(coord), &new_objects);
    } else{
        new_objects.insert(item);
    }

    set<QGraphicsItem*> result;
    set_difference(m_last_objects.begin(), m_last_objects.end(),
        new_objects.begin(), new_objects.end(), std::inserter(result, result.end()));
    
    for (set<QGraphicsItem*>::iterator itr = result.begin(); itr != result.end(); ++itr){
        removeItem(*itr);
        delete *itr;
    }
    m_last_objects = new_objects;
    /*Coord coord;
    for( int row = 0; row < m_board->get_height(); ++row ){
        for( int col = 0; col < m_board->get_width(); ++col ){
            const CellOccupier* occupier = m_board->lookup(Coord(col, row));
            int x = map_to_view(col, SnakeObject::get_width());
            int y = map_to_view(row, SnakeObject::get_height());
            coord = Coord(x,y);
            // Would rather remove if not snake?
            QGraphicsItem* item = itemAt(x, y, m_transform);
            if(item){
                removeItem(item);
                delete item;
            }
            if(occupier->get_type() == CellOccupier::SNAKE){
                // TODO: Don't like cast
                Snake* snake = (Snake *)occupier;
                if(!dead){
                    addItem(new SnakeObject(coord, 0));
                } else{
                    addItem(new SnakeDeadObject(coord));
                }
            } else if(occupier->get_type() == CellOccupier::WALL){
                addItem(new WallObject(coord));
            } else if(occupier->get_type() == CellOccupier::FOOD){
                addItem(new FoodObject(coord));
            }
        }
    }*/
}

void Scene::display_board(){
    QGraphicsItem* item;
    Coord coord;
    vector<Coord> coords = m_board->find_all(m_rules->get_wall());
    for (vector<Coord>::iterator itr = coords.begin(); itr != coords.end(); ++itr){
        int x = map_to_view((*itr).get_x(), SnakeObject::get_width());
        int y = map_to_view((*itr).get_y(), SnakeObject::get_height());
        coord = Coord(x,y); 
        item = find_item(coord);
        if(!item){
            add_object(new WallObject(coord));
        }
    }
}
