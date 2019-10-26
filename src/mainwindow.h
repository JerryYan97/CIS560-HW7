#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mygl.h"


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();
public slots:
    void slot_addMeshToListWidget(Mesh& iMesh);

    void slot_freeVerticesPinboxes(QListWidgetItem* i);
    void slot_freeFacesPinboxes(QListWidgetItem* i);
    void slot_slientAllPinboxes(QListWidgetItem* i);

    void slot_VertexPositionXValue(double i);
    void slot_VertexPositionYValue(double i);
    void slot_VertexPositionZValue(double i);

    void slot_FaceColorRedValue(double i);
    void slot_FaceColorGreenValue(double i);
    void slot_FaceColorBlueValue(double i);

    void slot_highlightVertex(QListWidgetItem* i);
    void slot_highlightFace(QListWidgetItem* i);
    void slot_highlightHalfEdge(QListWidgetItem* i);

    void slot_splitCubeEdge(bool i);
    void slot_triangulateCubeFace(bool i);

    void on_actionCamera_Controls_triggered();

private slots:
    void on_actionQuit_triggered();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
