#ifndef __Object_hpp__
#define __Object_hpp__

#include "../MathModule/Point/Point.hpp"
#include "../GraphicModule/Image/TextImage.hpp"
#include "Collider/Collider.hpp"
#include "Collider/BoxCollider.hpp"
#include "Physics/Physics.hpp"

#include "../../Util/UtilType.hpp"

#include <list>


namespace JirungEngine {
    class Object {
        public: std::string id;
        public: Point position;
        public: Physics physics;
        
        public: TextImage* image;
        public: std::list<Collider> collider;
        public: std::list<BoxCollider> box_collider;

        public: Object* parent_object;
        protected: std::list<Object*> child_object;

        protected: static std::list<std::string> object_id_list;

    public:
        Object(std::string id, const Point& position = Point { 0, 0, 0 }, Object* parent_object = nullptr);
        Object(std::string id, Object* parent_object);
        ~Object();

        Object* getParent();
        Object* getChildById(std::string id);

        void update();
    };
}

#endif