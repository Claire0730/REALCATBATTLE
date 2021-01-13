#ifndef IOBJECT_HPP_INCLUDED
#define IOBJECT_HPP_INCLUDED
#include<list>
#include<utility>
#include "Point.hpp"

namespace Engine{
    //The base interface class for objects that needs to be drawn or rendered.
    class IObject{
        friend class Group; //enable group to access
    protected:
        //The iterator of objects linked-list when added to scene. It can make removing objects faster.
        std::list<std::pair<bool, IObject*>>::iterator objectIterator{};
        //The interface cannot be instantiated directly, must be inherited.
        explicit IObject() = default;
        explicit IObject(float x, float y, float w = 0, float h = 0, float anchorX = 0, float anchorY = 0);
    public:
        bool Visible = true;//Determines whether this object should be drawn and updated.
        Point Position;//The object's position, center depends on Anchor.
        Point Size;//The object's size.
        Point Anchor;//(0,0) top-left, (1,1) button-right
        //The default virtual destructor to support polymorphism destruction.
        virtual ~IObject() = default;
        //Copy assignment operator
        IObject& operator=(IObject const&) = default;
        //Retrieve the object iterator for later insertion
        std::list<std::pair<bool, IObject*>>::iterator GetObjectIterator()const;
        //Draw to window display. It is called when the game should redraw the window.
        virtual void Draw()const;
        //Run game logic : updating the game. It is called when the game should update its logic, usually'fps' times per second.
        virtual void Update(float deltaTime);
    };
}
#endif // IOBJECT_HPP_INCLUDED
