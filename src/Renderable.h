

#pragma once

class Renderable {
public:
    virtual void render()=0;
    virtual void update()=0;
    virtual ~Renderable() = default;
};



