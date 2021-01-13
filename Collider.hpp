#ifndef COLLIDER_HPP_INCLUDED
#define COLLIDER_HPP_INCLUDED
#include <allegro5/bitmap.h>
#include <memory>

namespace Engine{
    struct Point;
    //Calculating physical collision, overlap, point, in region
    struct Collider final{
        explicit Collider() = delete;
        //Check Opaqueness
        static bool IsPointInBitmap(Point pnt, const std::shared_ptr<ALLEGRO_BITMAP>& bmp);
		static bool IsPointInRect(Point pnt, Point rectPos, Point rectSize);
		static bool IsRectOverlap(Point rect1p1, Point rect1p2, Point rect2p1, Point rect2p2);
		static bool IsCircleOverlap(Point c1, float r1, Point c2, float r2);
    };
}


#endif // COLLIDER_HPP_INCLUDED
