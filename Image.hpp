#ifndef IMAGE_HPP_INCLUDED
#define IMAGE_HPP_INCLUDED

#include <allegro5/bitmap.h>
#include <memory>
#include <string>

#include "IObject.hpp"

namespace Engine{
    class Image: public IObject{
    public:
        std::shared_ptr<ALLEGRO_BITMAP> bmp;
        explicit Image(std::string img, float x, float y, float w = 0, float h = 0, float anchorX = 0, float anchorY = 0);
        void Draw() const override;
        int GetBitmapWidth() const;
        int GetBitmapHeight() const;
    };
}

#endif // IMAGE_HPP_INCLUDED
