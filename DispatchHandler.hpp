#ifndef DISPATCH_HANDLER_HPP
#define DISPATCH_HANDLER_HPP
#include <map>
class Scene;
using std::map;
using std::pair;
typedef void (Scene::*DispatchFunction)(void);
class DispatchHandler{
public:
    DispatchHandler(DispatchHandler* parent = NULL){
        m_parent = parent;
    }
    
    void handle(Qt::Key key, Scene* s);
    
    void add(Qt::Key key, void (Scene::*func)()){
        m_key_map.insert(pair<Qt::Key, DispatchFunction>(key, func));
    }
private:
    DispatchHandler* m_parent;
    map<Qt::Key, DispatchFunction> m_key_map;
};

#endif