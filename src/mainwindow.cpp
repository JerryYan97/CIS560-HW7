#include "mainwindow.h"
#include <ui_mainwindow.h>
#include "cameracontrolshelp.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mygl->setFocus();

    // Disable every pinBox
    ui->faceBlueSpinBox->setEnabled(false);
    ui->faceGreenSpinBox->setEnabled(false);
    ui->faceRedSpinBox->setEnabled(false);
    ui->vertPosXSpinBox->setEnabled(false);
    ui->vertPosYSpinBox->setEnabled(false);
    ui->vertPosZSpinBox->setEnabled(false);
    ui->pushButtonAddVertex->setEnabled(false);
    ui->pushButtonTriangulate->setEnabled(false);

    // Wake up related pinBox when a vertexListWedgetItem is selected
    // Then, we can change the value of the vertices by changing the values through pinbox
    connect(ui->vertsListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(slot_freeVerticesPinboxes(QListWidgetItem*)));

    // Wake up related pinBox when a faceListWedgetItem is selected
    // Then, we can change the value of the faces by changing the values through pinbox
    connect(ui->facesListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(slot_freeFacesPinboxes(QListWidgetItem*)));

    connect(ui->halfEdgesListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(slot_slientAllPinboxes(QListWidgetItem*)));

    // Connect slot and signal for pinboxes
    connect(ui->vertPosXSpinBox, SIGNAL(valueChanged(double)), this, SLOT(slot_VertexPositionXValue(double)));
    connect(ui->vertPosYSpinBox, SIGNAL(valueChanged(double)), this, SLOT(slot_VertexPositionYValue(double)));
    connect(ui->vertPosZSpinBox, SIGNAL(valueChanged(double)), this, SLOT(slot_VertexPositionZValue(double)));
    connect(ui->faceRedSpinBox, SIGNAL(valueChanged(double)), this, SLOT(slot_FaceColorRedValue(double)));
    connect(ui->faceGreenSpinBox, SIGNAL(valueChanged(double)), this, SLOT(slot_FaceColorGreenValue(double)));
    connect(ui->faceBlueSpinBox, SIGNAL(valueChanged(double)), this, SLOT(slot_FaceColorBlueValue(double)));

    // Connect slot and signal for highlight
    connect(ui->vertsListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(slot_highlightVertex(QListWidgetItem*)));
    connect(ui->facesListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(slot_highlightFace(QListWidgetItem*)));
    connect(ui->halfEdgesListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(slot_highlightHalfEdge(QListWidgetItem*)));

    // Connect slot and signal for Visual Debugging Tools
    connect(ui->mygl, SIGNAL(SendNextHEOfHE(QListWidgetItem*)), this, SLOT(slot_highlightHalfEdge(QListWidgetItem*)));
    connect(ui->mygl, SIGNAL(SendSYMHEOfHE(QListWidgetItem*)), this, SLOT(slot_highlightHalfEdge(QListWidgetItem*)));
    connect(ui->mygl, SIGNAL(SendVertexOfHE(QListWidgetItem*)), this, SLOT(slot_highlightVertex(QListWidgetItem*)));
    connect(ui->mygl, SIGNAL(SendFaceOfHE(QListWidgetItem*)), this, SLOT(slot_highlightFace(QListWidgetItem*)));
    connect(ui->mygl, SIGNAL(SendHEOfFace(QListWidgetItem*)), this, SLOT(slot_highlightHalfEdge(QListWidgetItem*)));
    connect(ui->mygl, SIGNAL(SendHEOfVertex(QListWidgetItem*)), this, SLOT(slot_highlightHalfEdge(QListWidgetItem*)));

    // Connect slot and signal for split edge and triangulate face
    connect(ui->pushButtonAddVertex, SIGNAL(clicked(bool)), this, SLOT(slot_splitCubeEdge(bool)));
    connect(ui->pushButtonTriangulate, SIGNAL(clicked(bool)), this, SLOT(slot_triangulateCubeFace(bool)));

    // Put the mesh into the tree_widget.
    connect(ui->mygl, SIGNAL(SendMesh(Mesh&)), this, SLOT(slot_addMeshToListWidget(Mesh&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionCamera_Controls_triggered()
{
    CameraControlsHelp* c = new CameraControlsHelp();
    c->show();
}

void MainWindow::slot_addMeshToListWidget(Mesh &iMesh)
{
    for(std::vector<std::unique_ptr<Face>>::iterator ptr = iMesh.mFaceList.begin();
        ptr != iMesh.mFaceList.end();
        ptr++)
    {
        ui->facesListWidget->addItem(ptr->get());
    }

    for(std::vector<std::unique_ptr<HalfEdge>>::iterator ptr = iMesh.mHalfEdgeList.begin();
        ptr != iMesh.mHalfEdgeList.end();
        ptr++)
    {
        ui->halfEdgesListWidget->addItem(ptr->get());
    }

    for(std::vector<std::unique_ptr<Vertex>>::iterator ptr = iMesh.mVertexList.begin();
        ptr != iMesh.mVertexList.end();
        ptr++)
    {
        ui->vertsListWidget->addItem(ptr->get());
    }
}

void MainWindow::slot_freeVerticesPinboxes(QListWidgetItem* i)
{
    ui->faceBlueSpinBox->setEnabled(false);
    ui->faceGreenSpinBox->setEnabled(false);
    ui->faceRedSpinBox->setEnabled(false);
    ui->vertPosXSpinBox->setEnabled(true);
    ui->vertPosYSpinBox->setEnabled(true);
    ui->vertPosZSpinBox->setEnabled(true);

    Vertex* vPtr = dynamic_cast<Vertex*>(i);
    ui->vertPosXSpinBox->setValue(vPtr->mPos.x);
    ui->vertPosYSpinBox->setValue(vPtr->mPos.y);
    ui->vertPosZSpinBox->setValue(vPtr->mPos.z);
}

void MainWindow::slot_freeFacesPinboxes(QListWidgetItem* i)
{
    ui->faceBlueSpinBox->setEnabled(true);
    ui->faceGreenSpinBox->setEnabled(true);
    ui->faceRedSpinBox->setEnabled(true);
    ui->vertPosXSpinBox->setEnabled(false);
    ui->vertPosYSpinBox->setEnabled(false);
    ui->vertPosZSpinBox->setEnabled(false);

    ui->pushButtonAddVertex->setEnabled(false);
    ui->pushButtonTriangulate->setEnabled(true);

    Face* fPtr = dynamic_cast<Face*>(i);
    ui->faceBlueSpinBox->setValue(fPtr->mColor.z);
    ui->faceGreenSpinBox->setValue(fPtr->mColor.y);
    ui->faceRedSpinBox->setValue(fPtr->mColor.x);
}

void MainWindow::slot_slientAllPinboxes(QListWidgetItem *i)
{
    ui->faceBlueSpinBox->setEnabled(false);
    ui->faceGreenSpinBox->setEnabled(false);
    ui->faceRedSpinBox->setEnabled(false);
    ui->vertPosXSpinBox->setEnabled(false);
    ui->vertPosYSpinBox->setEnabled(false);
    ui->vertPosZSpinBox->setEnabled(false);

    ui->pushButtonAddVertex->setEnabled(true);
    ui->pushButtonTriangulate->setEnabled(false);
}

void MainWindow::slot_VertexPositionXValue(double i)
{
    QListWidgetItem* curr =  ui->vertsListWidget->currentItem();
    Vertex* vPtr = dynamic_cast<Vertex*>(curr);
    vPtr->mPos.x = i;
    ui->mygl->AdjustMeshPlanar(ui->mygl->m_Cube);
    ui->mygl->setFocus();
    ui->mygl->m_Cube.destroy();
    ui->mygl->m_Cube.create();
    ui->mygl->update();
    emit ui->mygl->SendMesh(ui->mygl->m_Cube);
}

void MainWindow::slot_VertexPositionYValue(double i)
{
    QListWidgetItem* curr =  ui->vertsListWidget->currentItem();
    Vertex* vPtr = dynamic_cast<Vertex*>(curr);
    vPtr->mPos.y = i;
    ui->mygl->AdjustMeshPlanar(ui->mygl->m_Cube);
    ui->mygl->setFocus();
    ui->mygl->m_Cube.destroy();
    ui->mygl->m_Cube.create();
    ui->mygl->update();
    emit ui->mygl->SendMesh(ui->mygl->m_Cube);
}

void MainWindow::slot_VertexPositionZValue(double i)
{
    QListWidgetItem* curr =  ui->vertsListWidget->currentItem();
    Vertex* vPtr = dynamic_cast<Vertex*>(curr);
    vPtr->mPos.z = i;
    ui->mygl->AdjustMeshPlanar(ui->mygl->m_Cube);
    ui->mygl->setFocus();
    ui->mygl->m_Cube.destroy();
    ui->mygl->m_Cube.create();
    ui->mygl->update();
    emit ui->mygl->SendMesh(ui->mygl->m_Cube);
}

void MainWindow::slot_FaceColorRedValue(double i)
{
    QListWidgetItem* curr =  ui->facesListWidget->currentItem();
    Face* fPtr = dynamic_cast<Face*>(curr);
    fPtr->mColor.x = i;
    ui->mygl->setFocus();
    ui->mygl->m_Cube.destroy();
    ui->mygl->m_Cube.create();
    ui->mygl->update();
}

void MainWindow::slot_FaceColorGreenValue(double i)
{
    QListWidgetItem* curr =  ui->facesListWidget->currentItem();
    Face* fPtr = dynamic_cast<Face*>(curr);
    fPtr->mColor.y = i;
    ui->mygl->setFocus();
    ui->mygl->m_Cube.destroy();
    ui->mygl->m_Cube.create();
    ui->mygl->update();
}

void MainWindow::slot_FaceColorBlueValue(double i)
{
    QListWidgetItem* curr =  ui->facesListWidget->currentItem();
    Face* fPtr = dynamic_cast<Face*>(curr);
    fPtr->mColor.z = i;
    ui->mygl->setFocus();
    ui->mygl->m_Cube.destroy();
    ui->mygl->m_Cube.create();
    ui->mygl->update();
}

void MainWindow::slot_highlightVertex(QListWidgetItem *i)
{
    ui->mygl->DisplayClear();
    Vertex* vPtr = dynamic_cast<Vertex*>(i);
    ui->mygl->setFocus();
    ui->mygl->m_vertDisplay.updateVertex(vPtr);
    ui->mygl->m_vertDisplay.create();
}

void MainWindow::slot_highlightFace(QListWidgetItem *i)
{
    ui->mygl->DisplayClear();
    Face* fPtr = dynamic_cast<Face*>(i);
    ui->mygl->setFocus();
    ui->mygl->m_faceDisplay.updateFace(fPtr);
    ui->mygl->m_vertDisplay.create();
}

void MainWindow::slot_highlightHalfEdge(QListWidgetItem *i)
{
    ui->mygl->DisplayClear();
    HalfEdge* hePtr = dynamic_cast<HalfEdge*>(i);
    ui->mygl->setFocus();
    ui->mygl->m_halfEdgeDisplay.updateHalfEdge(hePtr);
    ui->mygl->m_halfEdgeDisplay.create();
}

void MainWindow::slot_splitCubeEdge(bool i)
{

    ui->mygl->SplitHE(ui->mygl->m_halfEdgeDisplay.representedHalfEdge, ui->mygl->m_Cube);
    ui->mygl->setFocus();
    ui->mygl->m_Cube.destroy();
    ui->mygl->m_Cube.create();
    ui->mygl->update();
    emit ui->mygl->SendMesh(ui->mygl->m_Cube);
}

void MainWindow::slot_triangulateCubeFace(bool i)
{
    ui->mygl->TriangulateFace(ui->mygl->m_faceDisplay.representedFace, ui->mygl->m_Cube);
    ui->mygl->setFocus();
    ui->mygl->m_Cube.destroy();
    ui->mygl->m_Cube.create();
    ui->mygl->update();
    emit ui->mygl->SendMesh(ui->mygl->m_Cube);
}
