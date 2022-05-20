#include "Segment.hpp"

using namespace std;
using namespace JirungEngine;


Segment::Segment(Point point, Vector direction) : point { point }, direction { direction }, start_point { nullptr }, end_point { nullptr } {

}

Segment::Segment(Vector direction) : Segment { Point(0, 0, 0), direction } {

}


float Segment::x(float parameter) const {
    return point.x + direction.x*parameter;
}

float Segment::y(float parameter) const {
    return point.y + direction.y*parameter;
}

float Segment::z(float parameter) const {
    return point.z + direction.z*parameter;
}

bool Segment::isExistPointOfContactWith(const Segment& other) const {
    // 평행한지 검사 
    if(this->direction.x / other.direction.x == this->direction.y / other.direction.y && this->direction.y / other.direction.y == this->direction.z / other.direction.z) {
        // 평행하면 -> 같은점을 지나는지 검사(other에 this->start_point 대입해보기)
        
    }
    
    // 평행하지 않으면 ...


    float* tx;
    float* ty;
    float* tz;

    // 대입
    if(this->direction.x == other.direction.x) {
        tx = nullptr;
    }
    else {
        tx = new float { (-this->point.x + other.point.x) / (this->direction.x - other.direction.x) };
    }

    if(this->direction.y == other.direction.y) {
        ty = nullptr;
    }
    else {
        ty = new float { (-this->point.y + other.point.y) / (this->direction.y - other.direction.y) };
    }

    if(this->direction.z == other.direction.z) {
        tz = nullptr;
    }
    else {
        tz = new float { (-this->point.z + other.point.z) / (this->direction.z - other.direction.z) };
    }

    // 평행한지 검사
    if(tx == nullptr && ty == nullptr) {
        if()
    }

    if(tx == ty && ty == tz) {
        return true;
    }
    return false;
}