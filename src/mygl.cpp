#include "mygl.h"
#include <la.h>

#include <iostream>
#include <QApplication>
#include <QKeyEvent>


MyGL::MyGL(QWidget *parent)
    : OpenGLContext(parent),
      m_geomSquare(this),
      m_progLambert(this), m_progFlat(this),
      m_glCamera(), m_Cube(this), m_vertDisplay(this),
      m_faceDisplay(this), m_halfEdgeDisplay(this)
{}

MyGL::~MyGL()
{
    makeCurrent();
    glDeleteVertexArrays(1, &vao);
    m_geomSquare.destroy();
    m_Cube.destroy();
}

void MyGL::initializeGL()
{
    // Create an OpenGL context using Qt's QOpenGLFunctions_3_2_Core class
    // If you were programming in a non-Qt context you might use GLEW (GL Extension Wrangler)instead
    initializeOpenGLFunctions();
    // Print out some information about the current OpenGL context
    debugContextVersion();

    // Set a few settings/modes in OpenGL rendering
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    // Set the size with which points should be rendered
    glPointSize(5);
    // Set the color with which the screen is filled at the start of each render call.
    glClearColor(0.5, 0.5, 0.5, 1);

    printGLErrorLog();

    // Create a Vertex Attribute Object
    glGenVertexArrays(1, &vao);

    //Create the instances of Cylinder and Sphere.
    m_Cube.ConstructCube();
    m_geomSquare.create();
    m_Cube.create();


    // Create and set up the diffuse shader
    m_progLambert.create(":/glsl/lambert.vert.glsl", ":/glsl/lambert.frag.glsl");
    // Create and set up the flat lighting shader
    m_progFlat.create(":/glsl/flat.vert.glsl", ":/glsl/flat.frag.glsl");


    // We have to have a VAO bound in OpenGL 3.2 Core. But if we're not
    // using multiple VAOs, we can just bind one once.
    glBindVertexArray(vao);


    emit SendMesh(m_Cube);
}

void MyGL::resizeGL(int w, int h)
{
    //This code sets the concatenated view and perspective projection matrices used for
    //our scene's camera view.
    m_glCamera = Camera(w, h);
    glm::mat4 viewproj = m_glCamera.getViewProj();

    // Upload the view-projection matrix to our shaders (i.e. onto the graphics card)

    m_progLambert.setViewProjMatrix(viewproj);
    m_progFlat.setViewProjMatrix(viewproj);

    printGLErrorLog();
}

//This function is called by Qt any time your GL window is supposed to update
//For example, when the function update() is called, paintGL is called implicitly.
// It is called every frame
void MyGL::paintGL()
{
    // Clear the screen so that we only see newly drawn images
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_progFlat.setViewProjMatrix(m_glCamera.getViewProj());
    m_progFlat.setCamPos(m_glCamera.eye);
    m_progLambert.setViewProjMatrix(m_glCamera.getViewProj());
    m_progLambert.setCamPos(m_glCamera.eye);

//#define NOPE
#ifndef NOPE



    //Create a model matrix. This one scales the sphere uniformly by 3, then translates it by <-2,0,0>.
    //Note that we have to transpose the model matrix before passing it to the shader
    //This is because OpenGL expects column-major matrices, but you've
    //implemented row-major matrices.
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(-2,0,0)) * glm::rotate(glm::mat4(), 0.25f * 3.14159f, glm::vec3(0,1,0));
    //Send the geometry's transformation matrix to the shader
    m_progLambert.setModelMatrix(model);
    //Draw the example sphere using our lambert shader
    m_progLambert.draw(m_Cube);

    glDisable(GL_DEPTH_TEST);
    m_progFlat.setModelMatrix(model);
    m_vertDisplay.create();
    m_faceDisplay.create();
    m_halfEdgeDisplay.create();
    m_progFlat.draw(m_vertDisplay);
    m_progFlat.draw(m_faceDisplay);
    m_progFlat.draw(m_halfEdgeDisplay);
    glEnable(GL_DEPTH_TEST);

#endif
}

void MyGL::keyPressEvent(QKeyEvent *e)
{
    float amount = 2.0f;
    if(e->modifiers() & Qt::ShiftModifier){
        amount = 10.0f;
    }
    // http://doc.qt.io/qt-5/qt.html#Key-enum
    // This could all be much more efficient if a switch
    // statement were used
    if (e->key() == Qt::Key_Escape) {
        QApplication::quit();
    } else if (e->key() == Qt::Key_Right) {
        m_glCamera.RotateAboutUp(-amount);
    } else if (e->key() == Qt::Key_Left) {
        m_glCamera.RotateAboutUp(amount);
    } else if (e->key() == Qt::Key_Up) {
        m_glCamera.RotateAboutRight(-amount);
    } else if (e->key() == Qt::Key_Down) {
        m_glCamera.RotateAboutRight(amount);
    } else if (e->key() == Qt::Key_1) {
        m_glCamera.fovy += amount;
    } else if (e->key() == Qt::Key_2) {
        m_glCamera.fovy -= amount;
    } else if (e->key() == Qt::Key_W) {
        m_glCamera.TranslateAlongLook(amount);
    } else if (e->key() == Qt::Key_S) {
        m_glCamera.TranslateAlongLook(-amount);
    } else if (e->key() == Qt::Key_D) {
        m_glCamera.TranslateAlongRight(amount);
    } else if (e->key() == Qt::Key_A) {
        m_glCamera.TranslateAlongRight(-amount);
    } else if (e->key() == Qt::Key_Q) {
        m_glCamera.TranslateAlongUp(-amount);
    } else if (e->key() == Qt::Key_E) {
        m_glCamera.TranslateAlongUp(amount);
    } else if (e->key() == Qt::Key_R) {
        m_glCamera = Camera(this->width(), this->height());
    } else if (e->key() == Qt::Key_N) {
        // NEXT half-edge of the currently selected half-edge
        emit SendNextHEOfHE(m_halfEdgeDisplay.representedHalfEdge->mNextEdge_Ptr);
    } else if (e->key() == Qt::Key_M) {
        // SYM half-edge of the currently selected half-edge
        emit SendSYMHEOfHE(m_halfEdgeDisplay.representedHalfEdge->mSymEdge_Ptr);
    } else if (e->key() == Qt::Key_F) {
        // FACE of the currently selected half-edge
        emit SendFaceOfHE(m_halfEdgeDisplay.representedHalfEdge->mFace_Ptr);
    } else if (e->key() == Qt::Key_V) {
        // VERTEX of the currently selected half-edge
        emit SendVertexOfHE(m_halfEdgeDisplay.representedHalfEdge->mVertex_Ptr);
    } else if ((e->modifiers() == Qt::ShiftModifier) && (e->key() == Qt::Key_H)) {
        // HALF-EDGE of the currently selected face
        emit SendHEOfFace(m_faceDisplay.representedFace->mEdge_Ptr);
    } else if (e->key() == Qt::Key_H) {
        // HALF-EDGE of the currently selected vertex
        emit SendHEOfVertex(m_vertDisplay.representedVertex->mEdge_Ptr);
    }
    m_glCamera.RecomputeAttributes();
    update();  // Calls paintGL, among other things
}

void MyGL::DisplayClear()
{
    m_vertDisplay.updateVertex(nullptr);
    m_faceDisplay.updateFace(nullptr);
    m_halfEdgeDisplay.updateHalfEdge(nullptr);
    m_vertDisplay.destroy();
    m_faceDisplay.destroy();
    m_halfEdgeDisplay.destroy();
    m_vertDisplay.create();
    m_faceDisplay.create();
    m_halfEdgeDisplay.create();
}

void MyGL::SplitHE(HalfEdge* he, Mesh& iMesh)
{
    HalfEdge* he1 = he;
    HalfEdge* he2 = he1->mSymEdge_Ptr;

    // Create and Get the pos of middle vertex
    // the middle vertex is at the front of both halfedge
    Vertex* v1 = he1->mVertex_Ptr;
    Vertex* v2 = he2->mVertex_Ptr;
    std::unique_ptr<Vertex> uV3 = std::make_unique<Vertex>(Vertex());
    Vertex* v3 = uV3.get();
    glm::vec4 temp = v1->mPos + v2->mPos;
    v3->mPos = glm::vec4(temp.x / 2, temp.y / 2, temp.z / 2, temp.w / 2);

    // Create the two new half-edges HE1B and HE2B needed
    // to surround the middle vertex
    // HE1B points to V1
    // HE2B points to V2
    std::unique_ptr<HalfEdge> uHe1b = std::make_unique<HalfEdge>(HalfEdge());
    std::unique_ptr<HalfEdge> uHe2b = std::make_unique<HalfEdge>(HalfEdge());
    HalfEdge* he1b = uHe1b.get();
    HalfEdge* he2b = uHe2b.get();
    he1b->mVertex_Ptr = v1;
    he2b->mVertex_Ptr = v2;
    // set face pointers in HE1B and HE2B
    he1b->mFace_Ptr = he1->mFace_Ptr;
    he2b->mFace_Ptr = he2->mFace_Ptr;
    // Just create, do not affect other thing

    // Adjust the sym, next, and vert pointers of HE1, HE2,
    // HE1B, and HE2B
    he1b->mNextEdge_Ptr = he1->mNextEdge_Ptr;
    he2b->mNextEdge_Ptr = he2->mNextEdge_Ptr;
    he1->mNextEdge_Ptr = he1b;
    he2->mNextEdge_Ptr = he2b;
    he1->mVertex_Ptr = he2->mVertex_Ptr = v3;
    he1->mSymEdge_Ptr = he2b;
    he2b->mSymEdge_Ptr = he1;
    he2->mSymEdge_Ptr = he1b;
    he1b->mSymEdge_Ptr = he2;

    // Push v3, he1b and he2b into the Mesh Datastructure
    iMesh.mVertexList.push_back(std::move(uV3));
    iMesh.mHalfEdgeList.push_back(std::move(uHe1b));
    iMesh.mHalfEdgeList.push_back(std::move(uHe2b));
}

// For any number of half-edge
Face* MyGL::AddATriangle(Face *f, Mesh &iMesh)
{
    Face* face1 = f;
    HalfEdge* HE_0 = face1->mEdge_Ptr;
    // Create two new half-edges HE_A and HE_B
    std::unique_ptr<HalfEdge> uHE_A = std::make_unique<HalfEdge>(HalfEdge());
    std::unique_ptr<HalfEdge> uHE_B = std::make_unique<HalfEdge>(HalfEdge());
    HalfEdge* HE_A = uHE_A.get();
    HalfEdge* HE_B = uHE_B.get();
    HE_A->mVertex_Ptr = HE_0->mVertex_Ptr;
    // It looks like that it can only work in the condition of square->tri
    HE_B->mVertex_Ptr = HE_0->mNextEdge_Ptr->mNextEdge_Ptr->mVertex_Ptr;
    HE_A->mSymEdge_Ptr = HE_B;
    HE_B->mSymEdge_Ptr = HE_A;

    // Create a second face FACE2
    std::unique_ptr<Face> uFace2 = std::make_unique<Face>(Face());
    Face* face2 = uFace2.get();
    face2->mColor = face1->mColor;
    HE_A->mFace_Ptr = face2;
    HE_0->mNextEdge_Ptr->mFace_Ptr = face2;
    HE_0->mNextEdge_Ptr->mNextEdge_Ptr->mFace_Ptr = face2;
    HE_B->mFace_Ptr = face1;
    face2->mEdge_Ptr = HE_A;

    // Fix up the next pointers for our half-edges
    HE_B->mNextEdge_Ptr = HE_0->mNextEdge_Ptr->mNextEdge_Ptr->mNextEdge_Ptr;
    HE_0->mNextEdge_Ptr->mNextEdge_Ptr->mNextEdge_Ptr = HE_A;
    HE_A->mNextEdge_Ptr = HE_0->mNextEdge_Ptr;
    HE_0->mNextEdge_Ptr = HE_B;

    // Push everything into the mesh
    iMesh.mHalfEdgeList.push_back(std::move(uHE_A));
    iMesh.mHalfEdgeList.push_back(std::move(uHE_B));
    iMesh.mFaceList.push_back(std::move(uFace2));

    return face1;
}

int FaceEdgeNum(Face* f)
{
    int counter = 0;
    HalfEdge* hePtr = f->mEdge_Ptr;
    do{
        counter++;
        hePtr = hePtr->mNextEdge_Ptr;
    }while(hePtr != f->mEdge_Ptr);
    return counter;
}

void MyGL::TriangulateFace(Face *f, Mesh &iMesh)
{
    Face* oldFace;
    for(;;)
    {
        oldFace = AddATriangle(f, iMesh);
        int faceVNum = FaceEdgeNum(oldFace);
        if(faceVNum <= 3)
        {
            break;
        }
    }
}

bool MyGL::CheckPlanar(Face *f)
{
    int count = FaceEdgeNum(f);
    if(count <= 3)
    {
        return true;
    }else{
        // Get every normal for every vertices in this face
        HalfEdge* hePtr = f->mEdge_Ptr;
        std::vector<glm::vec3> normList;
        do{
            glm::vec3 nor = CalculateVertexNorm(hePtr);
            // Ignore the vertex that is align with front and back vertex
            if((glm::abs(nor.x) > DBL_EPSILON) || (glm::abs(nor.y) > DBL_EPSILON) || (glm::abs(nor.z) > DBL_EPSILON))
            {
                normList.push_back(nor);
            }
            hePtr = hePtr->mNextEdge_Ptr;
        }while(hePtr != f->mEdge_Ptr);
        // Check whether these normal are same
        for(std::vector<glm::vec3>::iterator norPtr = normList.begin(); norPtr != normList.end(); norPtr++)
        {
            std::vector<glm::vec3>::iterator nextPtr = norPtr + 1;
            for(;nextPtr != normList.end(); nextPtr++)
            {
                if(*norPtr != *nextPtr)
                {
                    TriangulateFace(f, m_Cube);
                    return false;
                }
            }
        }
        return true;
    }
}

void MyGL::AdjustMeshPlanar(Mesh &iMesh)
{
    for(std::vector<std::unique_ptr<Face>>::iterator fVecPtr = iMesh.mFaceList.begin(); fVecPtr != iMesh.mFaceList.end(); fVecPtr++)
    {
        Face* fPtr = fVecPtr->get();
        CheckPlanar(fPtr);
    }
}
