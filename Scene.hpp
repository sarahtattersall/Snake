#ifndef SCENE_HPP
#define SCENE_HPP

#include "Rules.hpp"
#include "Board.hpp"
#include "Coord.hpp"
#include "CellObject.hpp"
#include "DispatchHandler.hpp"

#include <set>

#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <QBrush>

using std::set;
using boost::scoped_ptr;

class Scene : public QGraphicsScene{
    Q_OBJECT
public:
    Scene(shared_ptr<Board> board, shared_ptr<Rules> rules);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void move_snake();
private:
    static const int MAX_PLAYERS = 2;
    static const QBrush FOOD_BRUSH;
    static const QBrush WALL_BRUSH;
    static const QBrush DEAD_BRUSH;
    static const QBrush PLAYER_BRUSHES[2];
    
    QGraphicsView view;    
    QPainter painter;
    shared_ptr<Board> m_board;
    shared_ptr<Rules> m_rules;
    QTransform m_transform;
    set<QGraphicsItem*> m_last_objects;
    vector<Vector::Direction> m_directions;
    scoped_ptr<QTimer> m_timer;
    DispatchHandler m_not_playing_handler;
    bool m_playing;

    void end_game();
    void update_view();
    // Maps board point x to the view, taking into consideration
    // size of objects
    int map_to_view(int x, int size);
    QGraphicsItem* find_item(Coord coord);
    Coord get_scene_coord(const CellOccupier* occupier);
    void add_object(QGraphicsItem* obj, set<QGraphicsItem*>* new_objects = NULL);
    void display_walls();
    void update_food();
    void reset_directions();
    CellObject* create_new_cell_object(Coord coord, QBrush brush);
    void reset();
    void start_game();
    void setup_keys();
};

#endif
