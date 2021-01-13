#ifndef ISCENE_HPP_INCLUDED
#define ISCENE_HPP_INCLUDED

#include "Group.hpp"

namespace Engine{
    class IScene: public Group{
    protected:
        explicit IScene() = default;
    public:
        IScene (IScene const&) = delete;
        IScene& operator =(IScene const&) = delete;
        virtual ~IScene() = default;
        virtual void Initialize() = 0;
        virtual void Terminate();
        void Draw() const override;
    };
}


#endif // ISCENE_HPP_INCLUDED
