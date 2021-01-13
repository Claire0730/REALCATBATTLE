#ifndef ICONTROL_HPP_INCLUDED
#define ICONTROL_HPP_INCLUDED

#include<list>
#include<utility>

namespace Engine{
    class IControl{
        friend class Group;
    protected:
        std::list<std::pair<bool, IControl*>>::iterator controlIterator{};
        explicit IControl() = default;
    public:
        virtual ~IControl() = default;
        IControl(const IControl& other) = default;
        IControl& operator=(IControl const&) = default;
        virtual void OnKeyDown(int keyCode);
        virtual void OnKeyUp(int keyCode);
        virtual void OnMouseDown(int button, int mx, int my);
        virtual void OnMouseUp(int button, int mx, int my);
        virtual void OnMouseMove(int mx, int my);
        virtual void OnMouseScroll(int mx, int my, int delta);
    };
}



#endif // ICONTROL_HPP_INCLUDED
