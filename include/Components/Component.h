#ifndef COMPONENT_H
#define COMPONENT_H

class Component {

public:
    virtual void start() = 0;
    virtual void update() = 0;
    virtual void end() = 0;

};

#endif /*COMPONENT_H*/