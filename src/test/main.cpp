#include "../JirungEngine/JirungEngine.hpp"
#include "../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


int main() {
    println("\nTest Start!\n\n");

    Viewer* viewer = new ConsoleViewer();
    Renderer renderer;
    Polygon pol[10];
    int cnt = 0;
    for(Polygon& e : pol) {
        e.moveTo(e.p1 + Point { 0, 0, -float(cnt) });
        e.rotate(Line(e.getCenterOfGravity(), e.getNormal()), cnt/2.0f);
        cnt++;
    }
    
    for(int i=0; i<1000; ++i) {
        for(const Polygon& e : pol) {
            renderer.renderClear(e);
        }
        viewer->show(*renderer.image);
        for(Polygon& e : pol) {
            e.moveTo(e.p1 + Point(0, 0, 0.5));
            e.rotate(Line(e.getCenterOfGravity(), e.getNormal()), 0.1);
        }
        
        renderer.clearImage();
        sleep(1000/30);
    }
}