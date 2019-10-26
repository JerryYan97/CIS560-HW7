#ifndef HALFEDGE_DATASTRUCTURE_H
#define HALFEDGE_DATASTRUCTURE_H

#include "la.h"
#include <memory>
#include "drawable.h"
#include <QListWidget>

class HalfEdge;
class Face;
class OpenGLDS;

class Vertex : public QListWidgetItem
{
public:
    glm::vec4 mPos; // A vec3 for storing its position
    HalfEdge* mEdge_Ptr; // A pointer to one of the HalfEdges that points to this Vertex
    static unsigned int mID; // A unique integer to identify the Vertex in menus and while debugging
    Vertex();
    ~Vertex(){}
};

class HalfEdge : public QListWidgetItem
{
public:
    HalfEdge* mNextEdge_Ptr;
    HalfEdge* mSymEdge_Ptr;
    Face* mFace_Ptr;
    Vertex* mVertex_Ptr;
    static unsigned int mID;
    HalfEdge();
    ~HalfEdge(){}
};

class Face : public QListWidgetItem
{
public:
    HalfEdge* mEdge_Ptr;
    glm::vec4 mColor;
    static unsigned int mID;
    Face();
    ~Face(){}
};



class Mesh : public Drawable
{
public:
    std::vector<std::unique_ptr<Vertex>> mVertexList;
    std::vector<std::unique_ptr<HalfEdge>> mHalfEdgeList;
    std::vector<std::unique_ptr<Face>> mFaceList;
    friend class OpenGLDS;
    Mesh(OpenGLContext* context);
    ~Mesh(){}
    void create();
    GLenum drawMode();
    void ConstructCube();
    void OpenGLDataConversion(OpenGLDS& iGLDS);
    void ConstructStandardCube();
};

//OpenGL Datastructure
class OpenGLDS{
public:
    std::vector<glm::vec4> arrPos;
    std::vector<glm::vec4> arrNor;
    std::vector<glm::vec4> arrCol;
    std::vector<GLuint> arrIdx;
    OpenGLDS(){}
    OpenGLDS(Mesh& iMesh);
    OpenGLDS(glm::vec4 iVertex); // used to draw a point
    OpenGLDS(glm::vec4 vHead, glm::vec4 vTail); // used to draw a line
    OpenGLDS(std::vector<glm::vec4>& ringVerticesList, glm::vec4 iColor); // used to draw a ring
    ~OpenGLDS(){}
};

glm::vec3 CalculateVertexNorm(HalfEdge* hePtr);

#endif // HALFEDGE_DATASTRUCTURE_H
