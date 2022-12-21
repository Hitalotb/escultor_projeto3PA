#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

class CutEllipsoid : public FiguraGeometrica{
    protected:
        int xcenter, ycenter, zcenter, rx, ry, rz;
        float r, g, b, a;
    public:
        CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
        ~CutEllipsoid();
        void draw(Sculptor &t);
};

#endif 