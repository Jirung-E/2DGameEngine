#include "BoxCollider.hpp"

using namespace JirungEngine;


BoxCollider::BoxCollider(const Point& top_left, const Point& buttom_right) : Collider { top_left, Vector2D { } }, 
    top_left { top_left }, buttom_right { buttom_right }, 
    side {
        Collider { top_left, Vector2D(buttom_right.x - top_left.x, 0) }, 
        Collider { Point(buttom_right.x, top_left.y), Vector2D(0, buttom_right.y - top_left.y) }, 
        Collider { buttom_right, Vector2D(top_left.x - buttom_right.x, 0) }, 
        Collider { Point(top_left.x, buttom_right.y), Vector2D(0, top_left.y - buttom_right.y) }
    } {
    
}

BoxCollider::BoxCollider(const BoxCollider& box_collider) : BoxCollider { box_collider.top_left, box_collider.buttom_right } {
    
}


Collider BoxCollider::getTopSide() const {
    return side[0];
}

Collider BoxCollider::getRightSide() const {
    return side[1];
}

Collider BoxCollider::getButtomSide() const {
    return side[2];
}

Collider BoxCollider::getLeftSide() const {
    return side[3];
}

Point BoxCollider::getTopLeftPoint() const {
    return top_left;
}

Point BoxCollider::getTopRightPoint() const {
    return Point(buttom_right.x, top_left.y);
}

Point BoxCollider::getButtomRightPoint() const {
    return buttom_right;
}

Point BoxCollider::getButtomLeftPoint() const {
    return Point(top_left.x, buttom_right.y);
}