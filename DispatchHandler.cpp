#include "DispatchHandler.hpp"

void DispatchHandler::handle(Qt::Key key, Scene* s){
    map<Qt::Key, DispatchFunction>::iterator itr = m_key_map.find(key);
    if (itr != m_key_map.end()){
        itr->*s->second();
    }else if (m_parent != NULL){
        m_parent->handle(key);
    }
    //QGraphicsScene::keyPressEvent(event);
}