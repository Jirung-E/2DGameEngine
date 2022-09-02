#ifndef __Object_hpp__
#define __Object_hpp__

#include "../../Math/Geometry/Geometry.hpp"
#include "../../Math/Polygon/Polygon.hpp"

#include <vector>


namespace Engine {
    class Object {
    public:
        std::vector<Math::Polygon> polygons;
        Math::Geometry geometry;
        
    public:
        Object();
        ~Object();
        
    public:
        void setPolygons(std::vector<Math::Polygon> polygons);
        void addPolygon(Math::Polygon polygon, Math::Point point);
    };
}

#endif