#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QMouseEvent>
#include <QVector>
#include <QImage>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Point{
    int x_;
    int y_;
    Point(){x_ = 0;y_ = 0;};
    Point(int x,int y){x_ = x;y_ = y;};
};

enum GraphicType{
    GNone = 0,
    GDDALine = 1,
    GMidPointLine = 2,
    GBresenhamLine = 3,
    GMidPointCircle = 4,
    GBresenhamCircle = 5,
    GAETPolygon = 6,
    GFloodFill4 = 7,
    GScanLineFill4 = 8,
    GCohen_Sutherland = 9,
    GLiang_Barsky = 10,
    GSutherLand_Hodgeman = 11,
    GBezierCurve = 12
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPixmap pix, pixTmp,pixTmp2;
    bool drawing_;//记录绘图状态

    GraphicType GType_;
    Point Pstart_;
    Point Pend_;
    QVector<Point> Vertices_;

    int XLeft_;
    int XRight_;
    int YTop_;
    int YBottom_;
    bool showClipWindow_;

    int BezierN_;
    int BezierM_;

    int pensize_;
    QColor penColor_;

protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void drawPoint(Point p);
    void rubberBand(Point p0,Point p1);
    void rubberPoint(Point p);
    void DDALine(Point p0,Point p1);
    void MidPointLine(Point p0,Point p1);
    void BresenhamLine(Point p0,Point p1);
    void MidPointCircle(Point p0,Point p1);
    void BresenhamCircle(Point p0,Point p1);
    void AETPolygon(QVector<Point> Vertices);
    void FloodFill4(QImage* pIamge,Point seed,QColor oldcolor);
    void ScanLineFill4(QImage* pImage,Point seed,QColor oldcolor);
    int encode(int x,int y);
    void Cohen_SutherlandClip(Point p0,Point p1);
    void Liang_BarskyClip(Point p0,Point p1);
    QVector<Point> EdgeClipping(QVector<Point> Vertices,int Edgecode);
    void SutherLand_HodgemanClip(QVector<Point> Vertices);
    void BezierCurve(QVector<Point> Vertices);
    void NBezierCurve(QVector<Point> NCtrlPs,int M,QVector<Point> &curvePts);

private slots:
    void on_actionDDALine_triggered();
    void on_actionMidPointLine_triggered();
    void on_actionBresenhamLine_triggered();
    void on_actionMidPointCircle_triggered();
    void on_actionBresenhamCircle_triggered();
    void on_actionPenSetting_triggered();
    void on_actionGAETPolygon_triggered();
    void on_actionFloodFill4_triggered();
    void on_actionScanLineFill4_triggered();
    void on_actionClipWindow_triggered();
    void on_actionCohen_SutherLandClip_triggered();
    void on_actionLiang_BarskyClip_triggered();
    void on_actionPolygon_Clip_triggered();
    void on_actionBezierCurve_triggered();
};

#endif // MAINWINDOW_H
