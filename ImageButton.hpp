#ifndef IMAGEBUTTON_HPP_INCLUDED
#define IMAGEBUTTON_HPP_INCLUDED

#include<allegro5/bitmap.h>
#include<functional>
#include<memory>
#include<string>

#include"IControl.hpp"
#include "Image.hpp"

namespace Engine{
    class ImageButton: public Image, public IControl{
    protected:
        bool mouseIn = false;
        //mouse-out display
        std::shared_ptr<ALLEGRO_BITMAP>imgOut;
        //mouse-in display
        std::shared_ptr<ALLEGRO_BITMAP>imgIn;
        //callback function
        std::function<void()> OnClickCallback;
    public:
        bool Enabled = true;//whether the button can be pressed or not
        explicit ImageButton(std::string img, std::string imgIn, float x, float y, float w = 0, float h = 0, float anchorX = 0, float anchorY = 0);
        void SetOnClickCallback(std::function<void(void)> onClickCallback);
        void OnMouseDown(int button, int mx, int my) override;
        void OnMouseMove(int mx, int my) override;
    };
}
#endif // IMAGEBUTTON_HPP_INCLUDED
