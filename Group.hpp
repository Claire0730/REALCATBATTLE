#ifndef GROUP_HPP_INCLUDED
#define GROUP_HPP_INCLUDED

#include<list>
#include<utility>
#include "IControl.hpp"
#include "IObject.hpp"

namespace Engine{
    class Group:public IObject, public IControl{
    protected:
        std::list<std::pair<bool, IObject*>> objects;
        std::list<std::pair<bool, IControl*>> controls;
        void addObject(bool shouldDelete, IObject* obj);
        void addControl(bool shouldDelete, IControl* ctrl);
        void insertObject(bool shouldDelete, IObject* obj, std::list<std::pair<bool, IObject*>>::iterator it);
    public:
        explicit Group() = default;
        Group(Group const& ) = delete;
        Group& operator = (Group const&) = delete;
        virtual ~Group();
        void Clear();
        void Update(float deltaTime) override;
        void Draw() const override;
        void OnKeyDown(int keyCode) override;
        void OnKeyUp(int keyCode) override;
        void OnMouseDown(int button, int mx, int my) override;
        void OnMouseUp(int button, int mx, int my) override;
        void OnMouseMove(int mx, int my) override;
        void OnMouseScroll(int mx, int my, int delta) override;

        void RemoveObject(std::list<std::pair<bool, IObject*>>::iterator it);
        void RemoveControl(std::list<std::pair<bool, IControl*>>::iterator it);
        void RemoveControlObject(std::list<std::pair<bool, IControl*>>::iterator ctrlIt, std::list<std::pair<bool, IObject*>>::iterator objIt);

        void AddNewObject(IObject* obj);
        //Insert Object to scene before the iterator
        void InsertNewObject(IObject* obj, std::list<std::pair<bool, IObject*>>::iterator it);
        void AddNewControl(IControl* ctrl);
        void AddNewControlObject(IControl* ctrl);
        //Use reference when adding a new object
        void AddRefObject(IObject& obj);
        //Insert a new object before iterator while using iterator.
        void InsertRefObject(IObject& obj, std::list<std::pair<bool, IObject*>>::iterator it);
        void AddRefControl(IControl& ctrl);
        void AddRefControlObject(IControl& ctrl);
        std::list<IObject*>GetObjects();
        std::list<IControl*>GetControls();
    };
}
#endif // GROUP_HPP_INCLUDED
