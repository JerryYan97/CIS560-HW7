#include "halfedge_datastructure.h"

unsigned int Vertex::mID = 0;
unsigned int HalfEdge::mID = 0;
unsigned int Face::mID = 0;

Vertex::Vertex()
{
    this->setText(QString::number(mID));
    mID++;
}

HalfEdge::HalfEdge()
{
    this->setText(QString::number(mID));
    mID++;
}

Face::Face()
{
    this->setText(QString::number(mID));
    mID++;
}


Mesh::Mesh(OpenGLContext *context)
    : Drawable(context)
{}

GLenum Mesh::drawMode()
{
    return GL_TRIANGLES;
}

// Populates the VBOs of the Drawable
// Organizing our data to make them fulfill the requirement of Opengl Triangle
// Meaning create, put opengl data into VBO.
void Mesh::create()
{
    // Convert half-edge ds to opengl ds
    OpenGLDS mDataArrays = OpenGLDS(*this);

    count = mDataArrays.arrIdx.size();
    generateIdx();
    mp_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    mp_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, mDataArrays.arrIdx.size() * sizeof(GLuint), mDataArrays.arrIdx.data(), GL_STATIC_DRAW);

    generatePos();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    mp_context->glBufferData(GL_ARRAY_BUFFER, mDataArrays.arrPos.size() * sizeof(glm::vec4), mDataArrays.arrPos.data(), GL_STATIC_DRAW);

    generateNor();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufNor);
    mp_context->glBufferData(GL_ARRAY_BUFFER, mDataArrays.arrNor.size() * sizeof(glm::vec4), mDataArrays.arrNor.data(), GL_STATIC_DRAW);

    generateCol();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    mp_context->glBufferData(GL_ARRAY_BUFFER, mDataArrays.arrCol.size() * sizeof(glm::vec4), mDataArrays.arrCol.data(), GL_STATIC_DRAW);

}

bool PairMatch(std::pair<HalfEdge*, Vertex*>& a, std::pair<HalfEdge*, Vertex*>& b)
{
    if(a.second == b.first->mVertex_Ptr && b.second == a.first->mVertex_Ptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Mesh::ConstructCube()
{
    // Create all Vertices
    std::array<std::unique_ptr<Vertex>, 8> vArray;
    for(int i = 0; i < 8; i++)
    {
        vArray.at(i) = std::make_unique<Vertex>(Vertex());
    }
    // Create all Half-edges
    std::array<std::unique_ptr<HalfEdge>, 24> hArray;
    for(int i = 0; i < 24; i++)
    {
        hArray.at(i) = std::make_unique<HalfEdge>(HalfEdge());
    }
    // Create all Faces
    std::array<std::unique_ptr<Face>, 6> fArray;
    for(int i = 0; i < 6; i++)
    {
        fArray.at(i) = std::make_unique<Face>(Face());
    }

    // Input vertices data
    vArray.at(0)->mPos = glm::vec4( 0.5,  0.5,  0.5, 1);
    vArray.at(1)->mPos = glm::vec4(-0.5,  0.5,  0.5, 1);
    vArray.at(2)->mPos = glm::vec4(-0.5, -0.5,  0.5, 1);
    vArray.at(3)->mPos = glm::vec4( 0.5, -0.5,  0.5, 1);
    vArray.at(4)->mPos = glm::vec4( 0.5,  0.5, -0.5, 1);
    vArray.at(5)->mPos = glm::vec4(-0.5,  0.5, -0.5, 1);
    vArray.at(6)->mPos = glm::vec4(-0.5, -0.5, -0.5, 1);
    vArray.at(7)->mPos = glm::vec4( 0.5, -0.5, -0.5, 1);

    vArray.at(0)->mEdge_Ptr = hArray.at(3).get();
    vArray.at(1)->mEdge_Ptr = hArray.at(0).get();
    vArray.at(2)->mEdge_Ptr = hArray.at(1).get();
    vArray.at(3)->mEdge_Ptr = hArray.at(2).get();
    vArray.at(4)->mEdge_Ptr = hArray.at(10).get();
    vArray.at(5)->mEdge_Ptr = hArray.at(9).get();
    vArray.at(6)->mEdge_Ptr = hArray.at(8).get();
    vArray.at(7)->mEdge_Ptr = hArray.at(11).get();

    // Input faces data
    fArray.at(0)->mColor = glm::vec4(1, 0, 0, 1);
    fArray.at(1)->mColor = glm::vec4(0, 1, 0, 1);
    fArray.at(2)->mColor = glm::vec4(0, 0, 1, 1);
    fArray.at(3)->mColor = glm::vec4(1, 1, 0, 1);
    fArray.at(4)->mColor = glm::vec4(1, 0, 1, 1);
    fArray.at(5)->mColor = glm::vec4(0, 1, 1, 1);

    fArray.at(0)->mEdge_Ptr = hArray.at(3).get();
    fArray.at(1)->mEdge_Ptr = hArray.at(7).get();
    fArray.at(2)->mEdge_Ptr = hArray.at(11).get();
    fArray.at(3)->mEdge_Ptr = hArray.at(15).get();
    fArray.at(4)->mEdge_Ptr = hArray.at(19).get();
    fArray.at(5)->mEdge_Ptr = hArray.at(23).get();

    // Input half-edge data
    // mNextEdge_Ptr
    hArray.at(0)->mNextEdge_Ptr = hArray.at(1).get();
    hArray.at(1)->mNextEdge_Ptr = hArray.at(2).get();
    hArray.at(2)->mNextEdge_Ptr = hArray.at(3).get();
    hArray.at(3)->mNextEdge_Ptr = hArray.at(0).get();

    hArray.at(4)->mNextEdge_Ptr = hArray.at(5).get();
    hArray.at(5)->mNextEdge_Ptr = hArray.at(6).get();
    hArray.at(6)->mNextEdge_Ptr = hArray.at(7).get();
    hArray.at(7)->mNextEdge_Ptr = hArray.at(4).get();

    hArray.at(8)->mNextEdge_Ptr = hArray.at(9).get();
    hArray.at(9)->mNextEdge_Ptr = hArray.at(10).get();
    hArray.at(10)->mNextEdge_Ptr = hArray.at(11).get();
    hArray.at(11)->mNextEdge_Ptr = hArray.at(8).get();

    hArray.at(12)->mNextEdge_Ptr = hArray.at(13).get();
    hArray.at(13)->mNextEdge_Ptr = hArray.at(14).get();
    hArray.at(14)->mNextEdge_Ptr = hArray.at(15).get();
    hArray.at(15)->mNextEdge_Ptr = hArray.at(12).get();

    hArray.at(16)->mNextEdge_Ptr = hArray.at(17).get();
    hArray.at(17)->mNextEdge_Ptr = hArray.at(18).get();
    hArray.at(18)->mNextEdge_Ptr = hArray.at(19).get();
    hArray.at(19)->mNextEdge_Ptr = hArray.at(16).get();

    hArray.at(20)->mNextEdge_Ptr = hArray.at(21).get();
    hArray.at(21)->mNextEdge_Ptr = hArray.at(22).get();
    hArray.at(22)->mNextEdge_Ptr = hArray.at(23).get();
    hArray.at(23)->mNextEdge_Ptr = hArray.at(20).get();

    // mSymEdge_Ptr
    hArray.at(0)->mSymEdge_Ptr = hArray.at(6).get();
    hArray.at(1)->mSymEdge_Ptr = hArray.at(20).get();
    hArray.at(2)->mSymEdge_Ptr = hArray.at(12).get();
    hArray.at(3)->mSymEdge_Ptr = hArray.at(16).get();

    hArray.at(4)->mSymEdge_Ptr = hArray.at(10).get();
    hArray.at(5)->mSymEdge_Ptr = hArray.at(21).get();
    hArray.at(6)->mSymEdge_Ptr = hArray.at(0).get();
    hArray.at(7)->mSymEdge_Ptr = hArray.at(19).get();

    hArray.at(8)->mSymEdge_Ptr = hArray.at(14).get();
    hArray.at(9)->mSymEdge_Ptr = hArray.at(22).get();
    hArray.at(10)->mSymEdge_Ptr = hArray.at(4).get();
    hArray.at(11)->mSymEdge_Ptr = hArray.at(18).get();

    hArray.at(12)->mSymEdge_Ptr = hArray.at(2).get();
    hArray.at(13)->mSymEdge_Ptr = hArray.at(23).get();
    hArray.at(14)->mSymEdge_Ptr = hArray.at(8).get();
    hArray.at(15)->mSymEdge_Ptr = hArray.at(17).get();

    hArray.at(16)->mSymEdge_Ptr = hArray.at(3).get();
    hArray.at(17)->mSymEdge_Ptr = hArray.at(15).get();
    hArray.at(18)->mSymEdge_Ptr = hArray.at(11).get();
    hArray.at(19)->mSymEdge_Ptr = hArray.at(7).get();

    hArray.at(20)->mSymEdge_Ptr = hArray.at(1).get();
    hArray.at(21)->mSymEdge_Ptr = hArray.at(5).get();
    hArray.at(22)->mSymEdge_Ptr = hArray.at(9).get();
    hArray.at(23)->mSymEdge_Ptr = hArray.at(13).get();

    // mFace_Ptr
    hArray.at(0)->mFace_Ptr = fArray.at(0).get();
    hArray.at(1)->mFace_Ptr = fArray.at(0).get();
    hArray.at(2)->mFace_Ptr = fArray.at(0).get();
    hArray.at(3)->mFace_Ptr = fArray.at(0).get();

    hArray.at(4)->mFace_Ptr = fArray.at(1).get();
    hArray.at(5)->mFace_Ptr = fArray.at(1).get();
    hArray.at(6)->mFace_Ptr = fArray.at(1).get();
    hArray.at(7)->mFace_Ptr = fArray.at(1).get();

    hArray.at(8)->mFace_Ptr = fArray.at(2).get();
    hArray.at(9)->mFace_Ptr = fArray.at(2).get();
    hArray.at(10)->mFace_Ptr = fArray.at(2).get();
    hArray.at(11)->mFace_Ptr = fArray.at(2).get();

    hArray.at(12)->mFace_Ptr = fArray.at(3).get();
    hArray.at(13)->mFace_Ptr = fArray.at(3).get();
    hArray.at(14)->mFace_Ptr = fArray.at(3).get();
    hArray.at(15)->mFace_Ptr = fArray.at(3).get();

    hArray.at(16)->mFace_Ptr = fArray.at(4).get();
    hArray.at(17)->mFace_Ptr = fArray.at(4).get();
    hArray.at(18)->mFace_Ptr = fArray.at(4).get();
    hArray.at(19)->mFace_Ptr = fArray.at(4).get();

    hArray.at(20)->mFace_Ptr = fArray.at(5).get();
    hArray.at(21)->mFace_Ptr = fArray.at(5).get();
    hArray.at(22)->mFace_Ptr = fArray.at(5).get();
    hArray.at(23)->mFace_Ptr = fArray.at(5).get();

    // mVertex_Ptr
    hArray.at(0)->mVertex_Ptr = vArray.at(1).get();
    hArray.at(1)->mVertex_Ptr = vArray.at(2).get();
    hArray.at(2)->mVertex_Ptr = vArray.at(3).get();
    hArray.at(3)->mVertex_Ptr = vArray.at(0).get();

    hArray.at(4)->mVertex_Ptr = vArray.at(5).get();
    hArray.at(5)->mVertex_Ptr = vArray.at(1).get();
    hArray.at(6)->mVertex_Ptr = vArray.at(0).get();
    hArray.at(7)->mVertex_Ptr = vArray.at(4).get();

    hArray.at(8)->mVertex_Ptr = vArray.at(6).get();
    hArray.at(9)->mVertex_Ptr = vArray.at(5).get();
    hArray.at(10)->mVertex_Ptr = vArray.at(4).get();
    hArray.at(11)->mVertex_Ptr = vArray.at(7).get();

    hArray.at(12)->mVertex_Ptr = vArray.at(2).get();
    hArray.at(13)->mVertex_Ptr = vArray.at(6).get();
    hArray.at(14)->mVertex_Ptr = vArray.at(7).get();
    hArray.at(15)->mVertex_Ptr = vArray.at(3).get();

    hArray.at(16)->mVertex_Ptr = vArray.at(3).get();
    hArray.at(17)->mVertex_Ptr = vArray.at(7).get();
    hArray.at(18)->mVertex_Ptr = vArray.at(4).get();
    hArray.at(19)->mVertex_Ptr = vArray.at(0).get();

    hArray.at(20)->mVertex_Ptr = vArray.at(1).get();
    hArray.at(21)->mVertex_Ptr = vArray.at(5).get();
    hArray.at(22)->mVertex_Ptr = vArray.at(6).get();
    hArray.at(23)->mVertex_Ptr = vArray.at(2).get();

    // Push vertices, half-edges and faces unique pointers to their own vectors
    for(int i = 0; i < 8; i++)
    {
        mVertexList.push_back(std::move(vArray.at(i)));
    }
    for(int i = 0; i < 24; i++)
    {
        mHalfEdgeList.push_back(std::move(hArray.at(i)));
    }
    for(int i = 0; i < 6; i++)
    {
        mFaceList.push_back(std::move(fArray.at(i)));
    }
}

void IndexInput(std::vector<GLuint>& idxVec, unsigned int firstVertIdx, unsigned int vertNum)
{
    for(unsigned int i = 0; i < (vertNum - 2); i++)
    {
        idxVec.push_back(firstVertIdx);
        idxVec.push_back(firstVertIdx + i + 1);
        idxVec.push_back(firstVertIdx + i + 2);
    }
}

// Calculate the normal at the vertex pointed by this halfedge
glm::vec3 CalculateVertexNorm(HalfEdge* hePtr)
{
    // current point
    glm::vec3 v1 = glm::vec3(
                hePtr->mVertex_Ptr->mPos.x,
                hePtr->mVertex_Ptr->mPos.y,
                hePtr->mVertex_Ptr->mPos.z);
    // back point
    glm::vec3 v2 = glm::vec3(
                hePtr->mSymEdge_Ptr->mVertex_Ptr->mPos.x,
                hePtr->mSymEdge_Ptr->mVertex_Ptr->mPos.y,
                hePtr->mSymEdge_Ptr->mVertex_Ptr->mPos.z);
    // front point
    glm::vec3 v3 = glm::vec3(
                hePtr->mNextEdge_Ptr->mVertex_Ptr->mPos.x,
                hePtr->mNextEdge_Ptr->mVertex_Ptr->mPos.y,
                hePtr->mNextEdge_Ptr->mVertex_Ptr->mPos.z);

    glm::vec3 vec1 = v3 - v1;
    glm::vec3 vec2 = v2 - v1;
    return glm::normalize(glm::cross(vec1, vec2));
}

glm::vec4 CalculateFaceNorm(Face* f)
{
    glm::vec3 accuNorm = glm::vec3(0, 0, 0);
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
    // Calculate the average of the normals in the normlist
    for(std::vector<glm::vec3>::iterator norPtr = normList.begin(); norPtr != normList.end(); norPtr++)
    {
        accuNorm += *norPtr;
    }
    int counter = normList.size();

    return glm::vec4(accuNorm.x / counter, accuNorm.y / counter, accuNorm.z / counter, 1);
}

OpenGLDS::OpenGLDS(Mesh &iMesh)
{
    // Construct arrPos, arrNor, arrCol according to faces sequence
    // Construct indexArray for each face
    for(std::vector<std::unique_ptr<Face>>::iterator fVecPtr = iMesh.mFaceList.begin();
        fVecPtr != iMesh.mFaceList.end();
        fVecPtr++)
    {
        // auxiliary variables
        unsigned int arrInitSize = arrPos.size();
        unsigned int counter = 0;

        // Push every vertices' pos, col in this ring into arrPos
        Face& temp = **fVecPtr;
        HalfEdge* ePtr = temp.mEdge_Ptr;
        do{
            arrPos.push_back(glm::vec4(ePtr->mVertex_Ptr->mPos.x,
                                       ePtr->mVertex_Ptr->mPos.y,
                                       ePtr->mVertex_Ptr->mPos.z,
                                       1.f));
            arrCol.push_back(temp.mColor);
            ePtr = ePtr->mNextEdge_Ptr;
            counter++;
        }while(ePtr != temp.mEdge_Ptr);

        // Calculate this face's normal
        Face* fPtr = fVecPtr->get();
        glm::vec4 nor = CalculateFaceNorm(fPtr);

        // Push the normal into arrNor
        // for 'counter' times
        // there are counter number points in a ring
        for(unsigned int i = 0; i < counter; i++)
        {
            arrNor.push_back(nor);
        }

        // Construct the index array for this face
        // triangluate this face
        IndexInput(arrIdx, arrInitSize, counter);
    }
}

OpenGLDS::OpenGLDS(glm::vec4 iVertex)
{
    arrPos.push_back(iVertex);
    arrCol.push_back(glm::vec4(1, 1, 1, 1));
    arrNor.push_back(glm::vec4(1, 0, 0, 1));
    arrIdx.push_back(0);
}

OpenGLDS::OpenGLDS(glm::vec4 vHead, glm::vec4 vTail)
{
    arrPos.push_back(vHead);
    arrPos.push_back(vTail);
    arrCol.push_back(glm::vec4(1, 1, 0, 1)); // head -- yellow
    arrCol.push_back(glm::vec4(1, 0, 0, 1)); // tail -- red
    arrNor.push_back(glm::vec4(1, 0, 0, 1));
    arrNor.push_back(glm::vec4(1, 0, 0, 1));
    arrIdx.push_back(0);
    arrIdx.push_back(1);
}

OpenGLDS::OpenGLDS(std::vector<glm::vec4>& ringVerticesList, glm::vec4 iColor)
{
    int vSize = ringVerticesList.size();
    // Construct the Idx arr
    for(int i = 0; i < vSize; i++)
    {
        arrIdx.push_back(i);
        if(i + 1 >= vSize)
        {
            arrIdx.push_back(0);
        }
        else
        {
            arrIdx.push_back(i + 1);
        }
    }
    // Construct the pos, nor, col arr
    for(std::vector<glm::vec4>::iterator vPtr = ringVerticesList.begin(); vPtr != ringVerticesList.end(); vPtr++)
    {
        arrPos.push_back(*vPtr);
        arrCol.push_back(iColor);
        arrNor.push_back(glm::vec4(1, 0, 0, 1));
    }
}
