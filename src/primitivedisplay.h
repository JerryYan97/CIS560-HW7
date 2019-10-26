#ifndef PRIMITIVEDISPLAY_H
#define PRIMITIVEDISPLAY_H
#include "halfedge_datastructure.h"

class VertexDisplay : public Drawable{
protected:

public:
    Vertex *representedVertex;
    void create() override;
    void updateVertex(Vertex* iV);
    GLenum drawMode();
    VertexDisplay(OpenGLContext* context);
    ~VertexDisplay(){}
};

class FaceDisplay : public Drawable{
protected:

public:
    Face *representedFace;
    void create() override;
    void updateFace(Face* iF);
    GLenum drawMode();
    FaceDisplay(OpenGLContext* context);
    ~FaceDisplay(){}
};

class HalfEdgeDisplay : public Drawable{
protected:

public:
    HalfEdge *representedHalfEdge;
    void create() override;
    void updateHalfEdge(HalfEdge* iHE);
    GLenum drawMode();
    HalfEdgeDisplay(OpenGLContext* context);
    ~HalfEdgeDisplay(){}
};


#endif // PRIMITIVEDISPLAY_H
