#ifndef __Segment_hpp__
#define __Segment_hpp__

#include "../Line/Line.hpp"


namespace JirungEngine {
    class Segment : public Line {
    public:
        Segment(Point point, Vector direction);
        Segment(Vector direction);

    public:
        bool isExistPointOfContactWith(const Segment& other) const;
        Point* getPointOfContactWith(const Segment& other) const;
        Point getFootOfPerpendicularFrom(const Point& point) const;
        Point getFootOfPerpendicularFrom(const Segment& line) const;
        float getDistanceTo(const Point& point) const;
        float getDistanceTo(const Segment& other) const;
        bool isParallelTo(const Segment& other) const;

        static float getDistanceBetween(const Point& point, const Segment& line);
        static float getDistanceBetween(const Segment& line, const Point& point);
        static float getDistanceBetween(const Segment& line1, const Segment& line2);
        static Segment getNormalOf(const Segment& line1, const Segment& line2);
        static bool isParallel(const Segment& line1, const Segment& line2);
        static Point getFootOfPerpendicular(const Segment& line, const Point& point);
        static Point getFootOfPerpendicular(const Segment& to, const Segment& from);
    };
}

#endif