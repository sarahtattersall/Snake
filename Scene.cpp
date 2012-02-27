#include "Scene.hpp"
#include "CellOccupier.hpp"
#include "SnakeDirection.hpp"
#include "SnakeException.hpp"

#include <algorithm>
Scene::Scene(shared_ptr<Board> board, shared_ptr<Rules> rules)
        : m_transform(), m_last_objects(), m_directions(){
    if (rules->get_player_count() > MAX_PLAYERS){
        throw TooManyPlayersError();
    }
    m_board = board;
    m_rules = rules;
    m_playing = false;
    m_directions.resize(m_rules->get_player_count());
    reset_directions();
    
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

void Scene::reset_directions(){
    for (int player = 0; player < m_rules->get_player_count(); ++player){
        m_directions[player] = (m_rules->get_snake(player))->get_direction();
    }
}

void Scene::move_snake(){
    bool result = true;
    for (int player = 0; player < m_rules->get_player_count(); ++player){
        result &= m_rules->move_snake(player, m_directions[player]);
    }
    if(!result){
        end_game();
    }
    update_view();
}

void Scene::end_game(){
    m_timer->stop();
    m_playing = false;
}

void Scene::keyPressEvent(QKeyEvent* event){
    if (event->key() == Qt::Key_R && !m_playing){
        if(m_rules->snake_dead()){
            m_rules->reset();
            reset_directions();
            update_view();
        }
    }
    if (event->key() == Qt::Key_Space && !m_playing){
        const Snake* snake = m_rules->get_snake(0);
        m_timer->start(100*snake->get_speed());
        m_playing = true;
    } else{
        if (m_playing){
            switch(event->key()){
                case Qt::Key_Up:
                    m_directions[0] = Coord::UP;
                    break;
                case Qt::Key_Down:
                    m_directions[0] = Coord::DOWN;
                    break;
                case Qt::Key_Left:
                    m_directions[0] = Coord::LEFT;
                    break;
                case Qt::Key_Right:
                    m_directions[0] = Coord::RIGHT;
                    break;
                case Qt::Key_W:
                    m_directions[1] = Coord::UP;
                    break;
                case Qt::Key_S:
                    m_directions[1] = Coord::DOWN;
                    break;
                case Qt::Key_A:
                    m_directions[1] = Coord::LEFT;
                    break;
                case Qt::Key_D:
                    m_directions[1] = Coord::RIGHT;
                    break;
                default:
                    break;
                }
            QGraphicsScene::keyPressEvent(event);
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
    bool dead; //= m_rules->snake_dead();
    int players = m_rules->get_player_count();
    QGraphicsItem* item;
    Coord coord;
    for( int player = 0; player < players; ++player){
        const Snake* snake = m_rules->get_snake(player);
        dead = !snake->is_alive();
        for (SnakeIterator itr = snake->begin(); itr != snake->end(); ++itr){
            coord = get_scene_coord(*itr);
            item = find_item(coord);
            if (!item){
                if (dead){
                    add_object(new SnakeDeadObject(coord), &new_objects);
                } else {
                    add_object(new SnakeObject(coord, player), &new_objects);
                }
            } else {
                if (dead){
                    add_object(new SnakeDeadObject(coord), &new_objects);
                } else{
                    new_objects.insert(item);
                }
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
}

void Scene::display_board(){
    QGraphicsItem* item;
    Coord coord;
    vector<CellOccupier*> walls = m_rules->get_walls();
    for(vector<CellOccupier*>::iterator wall = walls.begin(); wall != walls.end(); ++wall ){
        vector<Coord> coords = m_board->find_all(*wall);
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
}
