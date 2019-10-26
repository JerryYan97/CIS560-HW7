#ifndef MYGL_H
#define MYGL_H

#include <openglcontext.h>
#include <utils.h>
#include <shaderprogram.h>
#include <scene/squareplane.h>
#include "camera.h"
#include "primitivedisplay.h"
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>


class MyGL
    : public OpenGLContext
{
    Q_OBJECT
private:
    SquarePlane m_geomSquare;// The instance of a unit cylinder we can use to render any cylinder

    ShaderProgram m_progLambert;// A shader program that uses lambertian reflection
    ShaderProgram m_progFlat;// A shader program that uses "flat" reflection (no shadowing at all)

    GLuint vao; // A handle for our vertex array object. This will store the VBOs created in our geometry classes.
                // Don't worry too much about this. Just know it is necessary in order to render geometry.

    Camera m_glCamera;
    void HighlightDraw();

public:
    Mesh m_Cube;
    VertexDisplay m_vertDisplay;
    FaceDisplay m_faceDisplay;
    HalfEdgeDisplay m_halfEdgeDisplay;
    void DisplayClear(); // set every pointer in display to nullptr
    explicit MyGL(QWidget *parent = nullptr);
    ~MyGL();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void SplitHE(HalfEdge* he, Mesh& iMesh);
    void TriangulateFace(Face* f, Mesh& iMesh);
    bool CheckPlanar(Face* f);
    void AdjustMeshPlanar(Mesh& iMesh);
    Face* AddATriangle(Face* f, Mesh& iMesh);

protected:
    void keyPressEvent(QKeyEvent *e);

public slots:

signals:
    void SendMesh(Mesh& oMesh);
    void SendNextHEOfHE(QListWidgetItem* he);
    void SendSYMHEOfHE(QListWidgetItem* he);
    void SendFaceOfHE(QListWidgetItem* f);
    void SendVertexOfHE(QListWidgetItem* v);
    void SendHEOfVertex(QListWidgetItem* he);
    void SendHEOfFace(QListWidgetItem* he);
};


#endif // MYGL_H
