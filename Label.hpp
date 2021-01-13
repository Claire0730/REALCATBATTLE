#ifndef LABEL_HPP_INCLUDED
#define LABEL_HPP_INCLUDED

#include<allegro5/allegro_font.h>
#include<allegro5/color.h>
#include<memory>
#include<string>
#include "IObject.hpp"

namespace Engine{
    //text object
    class Label : public IObject{
    protected:
        std::shared_ptr<ALLEGRO_FONT> font;//pointer
    public:
        std::string Text;
        ALLEGRO_COLOR Color;
        //anchorX: 0 = left, 1 = right;
        explicit Label(const std::string& text, const std::string& font, int fontSize, float x, float y, unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255, float anchorX = 0, float anchorY = 0);
        void Draw()const override;//Draw text
        int GetTextWidth() const;
        int GetTextHeight() const;
    };
}

#endif // LABEL_HPP_INCLUDED
