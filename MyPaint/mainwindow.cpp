#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>
#include <QPainter>
#include <pensettingdialog.h>
#include <clipwindowsettingdialog.h>
#include <beziersettingdialog.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("MyPaintWorks"));
    pix = QPixmap(1200,600);
    pix.fill(Qt::white);
    pixTmp = QPixmap(1200,600);
    pixTmp.fill(Qt::white);

    drawing_ = false;
    GType_ = GNone;
    pensize_ = 3;
    penColor_ = Qt::black;

    XLeft_ = 200;
    XRight_ = 600;
    YTop_ = 400;
    YBottom_ = 100;
    showClipWindow_ = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pix);
}

void MainWindow::rubberBand(Point p0,Point p1)
{
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::gray);
    QPainter painter(&pix);
    painter.setPen(pen);
    if(GType_ == GDDALine || GType_ == GMidPointLine || GType_ == GBresenhamLine
        || GType_ == GAETPolygon || showClipWindow_ == true || GType_ == GCohen_Sutherland
        || GType_ == GSutherLand_Hodgeman){
        painter.drawLine(p0.x_,p0.y_,p1.x_,p1.y_);
    }
    if(GType_ == GMidPointCircle || GType_ == GBresenhamCircle){
        int r = sqrt((p0.x_ - p1.x_)*(p0.x_ - p1.x_) + (p0.y_ - p1.y_)*(p0.y_ - p1.y_));
        painter.drawEllipse(p0.x_ - r, p0.y_ - r, r*2, r*2);
    }
}

void MainWindow::rubberPoint(Point p){
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);
    QPainter painter(&pix);
    painter.setPen(pen);
    if(GType_ == GBezierCurve){
        painter.drawPoint(p.x_,p.y_);
    }
}

void MainWindow::DDALine(Point p0,Point p1)
{
    int x, x0, y0, x1, y1, flag;
    float m, y;
    x0 = p0.x_;
    y0 = p0.y_;
    x1 = p1.x_;
    y1 = p1.y_;

    if(x0 == x1&&y0 == y1){
        return;
    }
    if(x0 == x1){//垂直线
        if(y0 > x1){
            y = y0;y0 = y1;y1 = y;
        }
        for(y = y0;y < y1;y++){
            drawPoint(Point(x0,y));
        }
        return;
    }
    if(y0 == y1){//水平线
        if(x0 > x1){
            x = x0;x0 = x1;x1 = x;
        }
        for(x = x0;x < x1;x++){
            drawPoint(Point(x,y0));
        }
        return;
    }

    if(x0 > x1){//exchange x0 and x1
        x = x0;x0 = x1;x1 = x;
        y = y0;y0 = y1;y1 = y;
    }

    flag = 0;
    if (x1 - x0 > y1 - y0 && y1 - y0 > 0){
        flag = 1;
    }
    if (x1 - x0 > y0 - y1 && y0 - y1 > 0){
       flag = 2; y0 = -y0; y1 = -y1;
    }
    if (y1 - y0 > x1 - x0){
       flag = 3; x = x0; x0 = y0; y0 = x; x = x1; x1 = y1; y1 = x;
    }
    if (y0 - y1 > x1 - x0){
       flag = 4; x = x0; x0 = -y0; y0 = x; x = x1; x1 = -y1; y1 = x;
    }

    m = (float)(y1 - y0) / (float)(x1 - x0);
    for (x = x0, y = (float)y0; x <= x1; x++, y = y + m)
    {
        if (flag == 1) drawPoint(Point(x, int(y+0.5)));
        if (flag == 2) drawPoint(Point(x, -int(y+0.5)));
        if (flag == 3) drawPoint(Point(int(y+0.5), x));
        if (flag == 4) drawPoint(Point(int(y+0.5), -x));
    }
    return;
}

void MainWindow::MidPointLine(Point p0,Point p1)
{
    int x0,y0,x1,y1;
    int x,y,a,b,flag;
    int d,d1,d2;

    x0 = p0.x_;
    y0 = p0.y_;
    x1 = p1.x_;
    y1 = p1.y_;

    if(x0 == x1&&y0 == y1){
        return;
    }
    if(x0 == x1){//垂直线
        if(y0 > x1){
            y = y0;y0 = y1;y1 = y;
        }
        for(y = y0;y < y1;y++){
            drawPoint(Point(x0,y));
        }
        return;
    }
    if(y0 == y1){//水平线
        if(x0 > x1){
            x = x0;x0 = x1;x1 = x;
        }
        for(x = x0;x < x1;x++){
            drawPoint(Point(x,y0));
        }
        return;
    }

    if(x0 > x1){//exchange x0 and x1
        x = x0;x0 = x1;x1 = x;
        y = y0;y0 = y1;y1 = y;
    }

    flag = 0;
    if (x1 - x0 > y1 - y0 && y1 - y0 > 0){
        flag = 1;
    }
    if (x1 - x0 > y0 - y1 && y0 - y1 > 0){
       flag = 2; y0 = -y0; y1 = -y1;
    }
    if (y1 - y0 > x1 - x0){
       flag = 3; x = x0; x0 = y0; y0 = x; x = x1; x1 = y1; y1 = x;
    }
    if (y0 - y1 > x1 - x0){
       flag = 4; x = x0; x0 = -y0; y0 = x; x = x1; x1 = -y1; y1 = x;
    }

    x = x0;
    y = y0;
    a = y0 - y1;
    b = x1 - x0;
    d = 2*a + b;
    d1 = 2*a;
    d2 = 2*(a + b);

    drawPoint(Point(x,y));
    while(x <= x1){
        x = x + 1;
        if (d >= 0){
            if (flag == 1) drawPoint(Point(x, y));
            if (flag == 2) drawPoint(Point(x,-y));
            if (flag == 3) drawPoint(Point(y, x));
            if (flag == 4) drawPoint(Point(y,-x));
            d = d + d1;
        }
        else{
            y = y + 1;
            if (flag == 1) drawPoint(Point(x, y));
            if (flag == 2) drawPoint(Point(x,-y));
            if (flag == 3) drawPoint(Point(y, x));
            if (flag == 4) drawPoint(Point(y,-x));
            d = d +d2;
        }
    }
    return;

}

void MainWindow::BresenhamLine(Point p0,Point p1)
{
    int x0,y0,x1,y1;
    int x,y,flag;
    int e,deltax,deltay;

    x0 = p0.x_;
    y0 = p0.y_;
    x1 = p1.x_;
    y1 = p1.y_;

    if(x0 == x1&&y0 == y1){
        return;
    }
    if(x0 == x1){//垂直线
        if(y0 > x1){
            y = y0;y0 = y1;y1 = y;
        }
        for(y = y0;y < y1;y++){
            drawPoint(Point(x0,y));
        }
        return;
    }
    if(y0 == y1){//水平线
        if(x0 > x1){
            x = x0;x0 = x1;x1 = x;
        }
        for(x = x0;x < x1;x++){
            drawPoint(Point(x,y0));
        }
        return;
    }

    if(x0 > x1){//exchange x0 and x1
        x = x0;x0 = x1;x1 = x;
        y = y0;y0 = y1;y1 = y;
    }

    flag = 0;
    if (x1 - x0 > y1 - y0 && y1 - y0 > 0){
        flag = 1;
    }
    if (x1 - x0 > y0 - y1 && y0 - y1 > 0){
       flag = 2; y0 = -y0; y1 = -y1;
    }
    if (y1 - y0 > x1 - x0){
       flag = 3; x = x0; x0 = y0; y0 = x; x = x1; x1 = y1; y1 = x;
    }
    if (y0 - y1 > x1 - x0){
       flag = 4; x = x0; x0 = -y0; y0 = x; x = x1; x1 = -y1; y1 = x;
    }

    e = x0 - x1;
    deltax = 2*(x1 - x0);
    deltay = 2*(y1 - y0);
    x = x0;
    y = y0;

//    drawPoint(Point(x,y));
    while(x <= x1){
        x = x + 1;
        e = e +deltay;
        if(e <= 0){
            if (flag == 1) drawPoint(Point(x, y));
            if (flag == 2) drawPoint(Point(x,-y));
            if (flag == 3) drawPoint(Point(y, x));
            if (flag == 4) drawPoint(Point(y,-x));
        }
        else{
            y = y + 1;
            if (flag == 1) drawPoint(Point(x, y));
            if (flag == 2) drawPoint(Point(x,-y));
            if (flag == 3) drawPoint(Point(y, x));
            if (flag == 4) drawPoint(Point(y,-x));
            e = e - deltax;
        }
    }
    return;
}

void MainWindow::MidPointCircle(Point p0,Point p1){
    int r = int(sqrt((p0.x_ - p1.x_)*(p0.x_ - p1.x_) + (p0.y_ - p1.y_)*(p0.y_ - p1.y_))+0.5);
    int x = 0;
    int y = r;
    drawPoint(Point(p0.x_ + x,p0.y_ + y));
    drawPoint(Point(p0.x_ + x,p0.y_ - y));
    drawPoint(Point(p0.x_ + y,p0.y_ + x));
    drawPoint(Point(p0.x_ - y,p0.y_ + x));

    int e = 1 - r;
    int d1 = 3;
    int d2 = -2*r + 5;
    while(x <= y){
        x = x + 1;
        if (e < 0){
            e = e + d1;
            d1 = d1 + 2;
            d2 = d2 + 2;
        }
        else{
            y = y - 1;
            e = e + d2;
            d1 = d1 + 2;
            d2 = d2 + 2;
        }
        drawPoint(Point(p0.x_ + x,p0.y_ + y));
        drawPoint(Point(p0.x_ + y,p0.y_ + x));
        drawPoint(Point(p0.x_ + x,p0.y_ - y));
        drawPoint(Point(p0.x_ - y,p0.y_ + x));
        drawPoint(Point(p0.x_ - x,p0.y_ + y));
        drawPoint(Point(p0.x_ + y,p0.y_ - x));
        drawPoint(Point(p0.x_ - x,p0.y_ - y));
        drawPoint(Point(p0.x_ - y,p0.y_ - x));
    }
    return;
}

void MainWindow::BresenhamCircle(Point p0,Point p1){
    int r = int(sqrt((p0.x_ - p1.x_)*(p0.x_ - p1.x_) + (p0.y_ - p1.y_)*(p0.y_ - p1.y_))+0.5);
    int x = 0;
    int y = r;
    drawPoint(Point(p0.x_ + x,p0.y_ + y));
    drawPoint(Point(p0.x_ + x,p0.y_ - y));
    drawPoint(Point(p0.x_ - y,p0.y_ + x));
    drawPoint(Point(p0.x_ - y,p0.y_ - x));

    int D = 2 - 2*r;
    int deltaHD,deltaDV;
    int flag = 0;
    while(y > 0){
        if(D < 0){
            deltaHD = 2*(D + y) - 1;
            if (deltaHD <= 0){
                flag = 1;
            }
            else{
                flag = 2;
            }
        }
        else if(D > 0){
            deltaDV = 2*(D - x) - 1;
            if (deltaDV <= 0){
                flag = 2;
            }
            else{
                flag = 3;
            }
        }
        else{
            flag = 2;
        }
        if(flag == 1){
            x = x + 1;
            D = D + 2*x + 1;
        }
        else if(flag == 2){
            x = x + 1;
            y = y - 1;
            D = D + 2*x - 2*y + 1;
        }
        else{
            y = y -1;
            D = D - 2*y + 1;
        }

        drawPoint(Point(p0.x_ + x,p0.y_ + y));
        drawPoint(Point(p0.x_ + x,p0.y_ - y));
        drawPoint(Point(p0.x_ - y,p0.y_ + x));
        drawPoint(Point(p0.x_ - y,p0.y_ - x));
    }
}

void MainWindow::AETPolygon(QVector<Point> vertices){
    int oldPensize = pensize_;
    pensize_ = 1;

    typedef struct XET{
        double x;
        double dx;
        int ymax;
        bool newEdge;
        XET* next;
    }AET,NET;

    int verNum = vertices.count();
    int MaxY = vertices[0].y_;
    int MinY = vertices[0].y_;
    for(int i = 1;i < verNum;i++){
        if(MaxY < vertices[i].y_)
            MaxY = vertices[i].y_;
        if(MinY > vertices[i].y_)
            MinY = vertices[i].y_;
    }

    //录入新边表
    NET** pNET = new NET*[MaxY - MinY + 1];
    for(int i = 0;i < MaxY - MinY + 1;i++){
        pNET[i] = new NET;
        pNET[i]->x = 0;
        pNET[i]->dx = 0;
        pNET[i]->ymax = 0;
        pNET[i]->newEdge =true;
        pNET[i]->next = NULL;

        int scanY = MinY + i;
        for(int j = 0;j < verNum;j++){
            if(vertices[j].y_ == scanY){
                int preVer = j - 1;
                if(preVer < 0)
                    preVer += verNum;
                if(vertices[preVer].y_ > scanY){
                    NET* p =new NET;
                    p->x = vertices[j].x_;
                    p->ymax = vertices[preVer].y_;
                    p->dx = (double(vertices[preVer].x_ - vertices[j].x_))/(double(vertices[preVer].y_ - vertices[j].y_));
                    p->next = pNET[i]->next;
                    pNET[i]->next = p;
                }

                int nextVer = j + 1;
                if(nextVer > verNum - 1)
                    nextVer -= verNum;
                if(vertices[nextVer].y_ > scanY){
                    NET* p =new NET;
                    p->x = vertices[j].x_;
                    p->ymax = vertices[nextVer].y_;
                    p->dx = (double(vertices[nextVer].x_ - vertices[j].x_))/(double(vertices[nextVer].y_ - vertices[j].y_));
                    p->next = pNET[i]->next;
                    pNET[i]->next = p;
                }
            }
        }
    }

    //初始化NET
    AET* pAET = new AET;
    pAET->next = NULL;

    for(int i = 0;i < MaxY - MinY + 1;i++){
        int scanY = MinY + i;

        NET* p = pAET->next;
        AET* q = pAET;
        while(p != NULL){
            p->x += p->dx;
            p = p->next;
        }

        p = q->next;
        while(p !=NULL){
            if(p->ymax <= scanY){
                q->next = p->next;
                delete p;
                p = q->next;
            }
            else{
                q = q->next;
                p = q->next;
            }
        }

        p = pNET[i]->next;
        q = pAET;
        while(p!= NULL){
            while(q->next &&(q->next->x < p->x || (q->next->x == p->x &&q->next->dx < p->dx))){
                q = q->next;
            }

            NET* s = p->next;
            p->next = q->next;
            q->next = p;
            p = s;
            q = pAET;
        }

        p = pAET->next;
        while(p && p->next){
            int x0 = int(p->x + 0.5);
            int x1 = int(p->next->x + 0.5);
            if(x0 != x1){
                for(int j = x0;j <= x1;j++){
                    drawPoint(Point(j,scanY));
                }
                p->newEdge = false;
                p->next->newEdge = false;
                p = p->next->next;
            }
            else{
                if(p->newEdge == p->next->newEdge){
                    drawPoint(Point(x0,scanY));
                    p->newEdge = false;
                    p->next->newEdge = false;
                    p = p->next->next;
                }
                else{
                    p->newEdge = false;
                    p->next->newEdge = false;
                    p = p->next;
                }
            }
        }
    }
    delete [] pNET;
    pensize_ = oldPensize;
}

void MainWindow::FloodFill4(QImage* pImage,Point seed,QColor oldcolor){
    if(!pImage)
        return;
    if(!pImage->valid(seed.x_,seed.y_))
        return;
    QColor color = pImage->pixel(seed.x_,seed.y_);
    if(color.rgb() == oldcolor.rgb()){
        pImage->setPixelColor(seed.x_,seed.y_,penColor_.rgb());
        FloodFill4(pImage,Point(seed.x_-1,seed.y_),oldcolor);
        FloodFill4(pImage,Point(seed.x_,seed.y_-1),oldcolor);
        FloodFill4(pImage,Point(seed.x_+1,seed.y_),oldcolor);
        FloodFill4(pImage,Point(seed.x_,seed.y_+1),oldcolor);
    }
}

void MainWindow::ScanLineFill4(QImage* pImage,Point seed,QColor oldcolor){
    if(!pImage)
        return;

    int x,y,xl,xr,flag;
    QVector<Point> seed_stack;
    seed_stack.push_back(seed);
    int seed_num = seed_stack.size();
    while(seed_num > 0){
        Point p = seed_stack.last();
        seed_stack.pop_back();
        pImage->setPixelColor(p.x_,p.y_,penColor_.rgb());

        x = p.x_ + 1;
        while(QColor(pImage->pixel(x,p.y_)).rgb() == oldcolor.rgb()){
            pImage->setPixelColor(x,p.y_,penColor_.rgb());
            x++;
        }
        xr = x-1;

        x = p.x_ - 1;
        while(QColor(pImage->pixel(x,p.y_)).rgb() == oldcolor.rgb()){
            pImage->setPixelColor(x,p.y_,penColor_.rgb());
            x--;
        }
        xl = x+1;

        x = xl;
        flag = 1;
        while(x <= xr){
            flag = 0;
            while(QColor(pImage->pixel(x,p.y_+1)).rgb() == oldcolor.rgb()){
                flag = 1;
                x++;
            }
            if(flag == 1){
                seed_stack.push_back(Point(x-1,p.y_+1));
                flag = 0;
            }
            while(QColor(pImage->pixel(x,p.y_+1)).rgb() != oldcolor.rgb() && x <= xr){
                x++;
            }
        }

        x = xl;
        while(x <= xr){
            flag = 0;
            while(QColor(pImage->pixel(x,p.y_-1)).rgb() == oldcolor.rgb()){
                flag = 1;
                x++;
            }
            if (flag ==1){
                seed_stack.push_back(Point(x-1,p.y_-1));
                flag = 0;
            }
            while(QColor(pImage->pixel(x,p.y_-1)).rgb() != oldcolor.rgb() && x <= xr){
                x++;
            }
        }
        seed_num = seed_stack.size();
    }
}

#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8
int MainWindow::encode(int x,int y){
    int code = 0;
    if(x < XLeft_)
        code |= LEFT;
    if(x > XRight_)
        code |= RIGHT;
    if(y < YBottom_)
        code |= BOTTOM;
    if(y > YTop_)
        code |= TOP;
    return code;
}

void MainWindow::Cohen_SutherlandClip(Point p0,Point p1){
    int code1,code2,code;
    code1 = encode(p0.x_,p0.y_);
    code2 = encode(p1.x_,p1.y_);

    float x,y,x1,y1,x2,y2;
    x1 = p0.x_; y1 = p0.y_;
    x2 = p1.x_; y2 = p1.y_;

    while(code1 != 0 || code2 != 0){
        if((code1 & code2) !=0)
            return;
        if(code1 != 0)
            code = code1;
        else
            code = code2;

        if((LEFT & code) !=0){
            x = XLeft_;
            y = y1 + (y2 - y1)/(x2 - x1)*(XLeft_ - x1);
        }
        else if((RIGHT & code) !=0){
            x = XRight_;
            y = y1 + (y2 - y1)/(x2 - x1)*(XRight_ - x1);
        }
        else if((BOTTOM & code) !=0){
            y = YBottom_;
            x = x1 + (x2 - x1)/(y2 - y1)*(YBottom_ - y1);
        }
        else if((TOP & code) !=0){
            y = YTop_;
            x = x1 + (x2 - x1)/(y2 - y1)*(YTop_ - y1);
        }

        if(code == code1){
            x1 = x; y1 = y; code1 = encode(int(x + 0.5),int(y + 0.5));
        }
        else{
            x2 = x; y2 = y; code2 = encode(int(x + 0.5),int(y + 0.5));
        }
    }

    DDALine(Point(x1,y1),Point(x2,y2));
}

bool ClipT(float p, float q,float* u1,float* u2){
    float u;
    if(p < 0){
        u = q/p;
        if(u > *u2)return false;
        if(u > *u1)*u1 = u;
    }
    else if(p > 0){
        u = q/p;
        if(u < *u1)return false;
        if(u < *u2)*u2 = u;
    }
    else return(q >= 0);
    return true;
}

void MainWindow::Liang_BarskyClip(Point p1,Point p2){
    float u1,u2,dx,dy;
    dx = p2.x_ - p1.x_; dy = p2.y_ - p1.y_;
    u1 = 0; u2 = 1;
    if(ClipT(-dx,p1.x_ - XLeft_, &u1,&u2))
        if(ClipT(dx,XRight_ - p1.x_, &u1,&u2))
            if(ClipT(-dy,p1.y_ - YBottom_, &u1,&u2))
                if(ClipT(dy,YTop_ - p1.y_, &u1,&u2))
    DDALine(Point(p1.x_ + u1*dx,p1.y_ + u1*dy),Point(p1.x_ + u2*dx,p1.y_ + u2*dy));
}

QVector<Point> MainWindow::EdgeClipping(QVector<Point> vertices,int Edgecode){
    QVector<Point> new_vertices;
    float x,y;
    //Edgecode LEFT-0 BOTTOM-1 RIGHT-2 TOP-3
    if(Edgecode == 0){
        for(int i = 0;i < vertices.size();i++){
            Point S = vertices[i];
            Point P = vertices[(i+1)%vertices.size()];
            if(S.x_ < XLeft_ && P.x_ < XLeft_)
                continue;
            if(S.x_ >= XLeft_ && P.x_ >= XLeft_)
                new_vertices.push_back(P);
            x = XLeft_;
            y = S.y_ + (float)(P.y_-S.y_)/(float)(P.x_-S.x_)*(float)(x - S.x_);
            if(S.x_ >= XLeft_ && P.x_ < XLeft_)
                new_vertices.push_back(Point(x,y));
            if(S.x_ < XLeft_ && P.x_ >= XLeft_){
                new_vertices.push_back(Point(x,y));
                new_vertices.push_back(P);
            }
        }
    }

    if(Edgecode == 1){
        for(int i = 0;i < vertices.size();i++){
            Point S = vertices[i];
            Point P = vertices[(i+1)%vertices.size()];
            if(S.y_ < YBottom_ && P.y_ < YBottom_)
                continue;
            if(S.y_ >= YBottom_ && P.y_ >= YBottom_)
                new_vertices.push_back(P);
            y = YBottom_;
            x = S.x_ + (float)(P.x_-S.x_)/(float)(P.y_-S.y_)*(float)(y - S.y_);
            if(S.y_ >= YBottom_ && P.y_ < YBottom_)
                new_vertices.push_back(Point(x,y));
            if(S.y_ < YBottom_ && P.y_ >= YBottom_){
                new_vertices.push_back(Point(x,y));
                new_vertices.push_back(P);
            }
        }
    }

    if(Edgecode == 2){
        for(int i = 0;i < vertices.size();i++){
            Point S = vertices[i];
            Point P = vertices[(i+1)%vertices.size()];
            if(S.x_ > XRight_ && P.x_ > XRight_)
                continue;
            if(S.x_ <= XRight_ && P.x_ <= XRight_)
                new_vertices.push_back(P);
            x = XRight_;
            y = S.y_ + (float)(P.y_-S.y_)/(float)(P.x_-S.x_)*(float)(x - S.x_);
            if(S.x_ <= XRight_ && P.x_ > XRight_)
                new_vertices.push_back(Point(x,y));
            if(S.x_ > XRight_ && P.x_ <= XRight_){
                new_vertices.push_back(Point(x,y));
                new_vertices.push_back(P);
            }
        }
    }

    if(Edgecode == 3){
        for(int i = 0;i < vertices.size();i++){
            Point S = vertices[i];
            Point P = vertices[(i+1)%vertices.size()];
            if(S.y_ > YTop_ && P.y_ > YTop_)
                continue;
            if(S.y_ <= YTop_ && P.y_ <= YTop_)
                new_vertices.push_back(P);
            y = YTop_;
            x = S.x_ + (float)(P.x_-S.x_)/(float)(P.y_-S.y_)*(float)(y - S.y_);
            if(S.y_ <= YTop_ && P.y_ > YTop_)
                new_vertices.push_back(Point(x,y));
            if(S.y_ > YTop_ && P.y_ <= YTop_){
                new_vertices.push_back(Point(x,y));
                new_vertices.push_back(P);
            }
        }
    }

    return new_vertices;
}

void MainWindow::SutherLand_HodgemanClip(QVector<Point> Vertices){
    QVector<Point> vers = Vertices;
    vers = EdgeClipping(vers,0);
    vers = EdgeClipping(vers,1);
    vers = EdgeClipping(vers,2);
    vers = EdgeClipping(vers,3);

    AETPolygon(vers);
}

void MainWindow::NBezierCurve(QVector<Point> NCtrlPs,int M,QVector<Point> &curvePts){
    int n = NCtrlPs.count() - 1;
    float Ba[n + 1];

    Ba[0] = 1;
    for(int j = 1;j <= n;j++){
        Ba[j] = float(n - j + 1)/j * Ba[j - 1];
    }

    float x,y,t;
    curvePts.push_back(NCtrlPs[0]);
    for(int i = 0;i <= M;i++){
        x = 0;y = 0;
        t = float(i)/M;
        for(int j = 0;j <= n;j++){
            x = x + NCtrlPs[j].x_ * Ba[j]* pow(t,j) * pow(1-t,n-j);
            y = y + NCtrlPs[j].y_ * Ba[j]* pow(t,j) * pow(1-t,n-j);
        }
        curvePts.push_back(Point(int(x),int(y)));
    }
}

void MainWindow::BezierCurve(QVector<Point> CtrPs){
    QVector<Point> Ps = CtrPs;
    int PsNum = Ps.count();
    if(PsNum > BezierN_ +1){
        QVector<Point>::iterator itr = Ps.begin();
        itr++;
        int idx = 1;
        for(;itr != Ps.end();){
            if(PsNum - idx <= BezierN_){
                break;
            }
            if(idx %(BezierN_ - 1) == 0){
                int x1 = itr->x_;
                int y1 = itr->y_;
                itr++;
                int x2 = itr->x_;
                int y2 = itr->y_;
                Point midP = Point((x1+x2)/2,(y1+y2)/2);
                itr = Ps.insert(itr,midP);
            }
            itr++;
            idx++;
        }
    }
    PsNum = Ps.count();
    int K = (PsNum - 1)/BezierN_;
    for(int k = 0;k < K;k++){
        QVector<Point> curvePts;
        int idx0 = k*BezierN_;
        QVector<Point> NCtrlPs;
        for(int i = 0;i <= BezierN_;i++)
            NCtrlPs.push_back(Ps[idx0+i]);

        NBezierCurve(NCtrlPs,BezierM_,curvePts);

        for(int i = 0;i < curvePts.count()-1;i++)
            DDALine(curvePts[i],curvePts[i+1]);
    }

}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    int x = event->x();
    int y = event->y();
    if(GType_ == GDDALine || GType_ == GMidPointLine || GType_ == GBresenhamLine
        || GType_ == GMidPointCircle || GType_ == GBresenhamCircle || GType_ == GCohen_Sutherland
        || GType_ == GLiang_Barsky){
        drawing_ = true;
        Pstart_ = Point(x,y);
        pixTmp = pix;
    }
    if(GType_ == GAETPolygon || GType_ == GSutherLand_Hodgeman || GType_ == GBezierCurve){
        if(event->button() == Qt::LeftButton){
            if(Vertices_.count() == 0)
                pixTmp = pix;
            Vertices_ << Point(x,y);

            int vnum = Vertices_.count();
            if(vnum >= 2)
                rubberBand(Vertices_[vnum - 2], Vertices_[vnum - 1]);
            rubberPoint(Point(x,y));
            update();
        }
        else if(event->button() == Qt::RightButton){
            if(GType_ == GBezierCurve){
                int x = 0;
                if(Vertices_.count() < BezierN_+1)
                    x = BezierN_ + 1 - Vertices_.count();
                else if(Vertices_.count() > BezierN_+1 && Vertices_.count() < 2*BezierN_)
                    x = 2*BezierN_ - Vertices_.count();
                else if(Vertices_.count() > 2*BezierN_){
                    int k = (Vertices_.count() - 2*BezierN_)%(BezierN_-1);
                    if(k > 0)
                        x = BezierN_ - 1 - k;
                }

                if(x > 0){
                    QString printstr = tr("Please input %1 more point").arg(x);
                    QMessageBox::warning(NULL,"warning",printstr,QMessageBox::Yes,QMessageBox::Yes);
                    return;
                }
                else{
                    pix = pixTmp;
                    BezierCurve(Vertices_);
                    Vertices_.clear();
                    update();
                    return;
                }
            }

            pix = pixTmp;
            if(GType_ == GAETPolygon){
                AETPolygon(Vertices_);
            }
            else if(GType_ == GSutherLand_Hodgeman){
                if(showClipWindow_){
                    pix = pixTmp2;
                }
                SutherLand_HodgemanClip(Vertices_);
                if(showClipWindow_){
                    pixTmp2 = pix;
                    rubberBand(Point(XLeft_,YBottom_),Point(XRight_,YBottom_));
                    rubberBand(Point(XRight_,YBottom_),Point(XRight_,YTop_));
                    rubberBand(Point(XRight_,YTop_),Point(XLeft_,YTop_));
                    rubberBand(Point(XLeft_,YTop_),Point(XLeft_,YBottom_));
                }
            }

            Vertices_.clear();
            update();
        }
    }
    if(GType_ == GFloodFill4 || GType_ == GScanLineFill4){
        if(event->button() == Qt::LeftButton){
            QImage* pImage = new QImage;
            *pImage = pix.toImage();

            if(!pImage->isNull()){
                if(pImage->valid(x,y)){
                    QColor oldColor = pImage->pixel(x,y);
                    if(oldColor == penColor_){
                        QMessageBox::critical(NULL,"","当前背景色与填充色相同! ",QMessageBox::Yes,QMessageBox::Yes);
                    }
                    else{
                        if(GType_ == GFloodFill4)
                            FloodFill4(pImage,Point(x,y),oldColor);
                        if(GType_ == GScanLineFill4)
                            ScanLineFill4(pImage,Point(x,y),oldColor);
                        pix = QPixmap::fromImage(*pImage);
                        update();
                    }
                }
            }
            delete pImage;
        }
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(drawing_)
    {
        int x = event->x();
        int y = event->y();
        pix = pixTmp;
        if(GType_ == GDDALine || GType_ == GMidPointLine || GType_ == GBresenhamLine
            || GType_ == GMidPointCircle || GType_ == GBresenhamCircle || GType_ == GCohen_Sutherland
            || GType_ == GLiang_Barsky){
            rubberBand(Pstart_,Point(x,y));
        }
        update();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if(drawing_){
        int x = event->x();
        int y = event->y();
            pix = pixTmp;
            if(GType_ == GDDALine)
                DDALine(Pstart_,Point(x,y));
            if(GType_ == GMidPointLine)
                MidPointLine(Pstart_,Point(x,y));
            if(GType_ == GBresenhamLine)
                BresenhamLine(Pstart_,Point(x,y));
            if(GType_ == GMidPointCircle)
                MidPointCircle(Pstart_,Point(x,y));
            if(GType_ == GBresenhamCircle)
                BresenhamCircle(Pstart_,Point(x,y));
            if(GType_ == GCohen_Sutherland || GType_ == GLiang_Barsky){
                if(showClipWindow_){
                    pix = pixTmp2;
                }
                if(GType_ == GCohen_Sutherland)
                    Cohen_SutherlandClip(Pstart_,Point(x,y));
                if(GType_ == GLiang_Barsky)
                    Liang_BarskyClip(Pstart_,Point(x,y));

                if(showClipWindow_){
                    pixTmp2 = pix;
                    rubberBand(Point(XLeft_,YBottom_),Point(XRight_,YBottom_));
                    rubberBand(Point(XRight_,YBottom_),Point(XRight_,YTop_));
                    rubberBand(Point(XRight_,YTop_),Point(XLeft_,YTop_));
                    rubberBand(Point(XLeft_,YTop_),Point(XLeft_,YBottom_));
                }
            }
            update();
            drawing_ = false;
    }
}

void MainWindow::drawPoint(Point p)
{
    QPen pen;
    pen.setWidth(pensize_);
    pen.setColor(penColor_);
    QPainter painter(&pix);
    painter.setPen(pen);
    painter.drawPoint(p.x_,p.y_);
    pixTmp = pix;
}

void MainWindow::on_actionDDALine_triggered()
{
    GType_ = GDDALine;
}


void MainWindow::on_actionMidPointLine_triggered()
{
    GType_ = GMidPointLine;
}


void MainWindow::on_actionBresenhamLine_triggered()
{
    GType_ = GBresenhamLine;
}


void MainWindow::on_actionMidPointCircle_triggered()
{
    GType_ = GMidPointCircle;
}


void MainWindow::on_actionBresenhamCircle_triggered()
{
    GType_ = GBresenhamCircle;
}


void MainWindow::on_actionPenSetting_triggered()
{
    PenSettingDialog dialog;
    if(dialog.exec() == QDialog::Accepted){
        pensize_ = dialog.size_;
        penColor_ = dialog.color_;
    }
}


void MainWindow::on_actionGAETPolygon_triggered()
{
    GType_ = GAETPolygon;
}


void MainWindow::on_actionFloodFill4_triggered()
{
    GType_ = GFloodFill4;
}


void MainWindow::on_actionScanLineFill4_triggered()
{
    GType_ = GScanLineFill4;
}


void MainWindow::on_actionClipWindow_triggered()
{
    ClipWindowSettingDialog dialog;

    if(dialog.exec() == QDialog::Accepted){
        if(!showClipWindow_){
            pixTmp2 = pix;
        }
        XLeft_ = dialog.XLeft_;
        XRight_ = dialog.XRight_;
        YTop_ = dialog.YTop_;
        YBottom_ = dialog.YBottom_;
        showClipWindow_ = dialog.showClipWindow_;
        pix = pixTmp2;

        if(showClipWindow_){
            rubberBand(Point(XLeft_,YBottom_),Point(XRight_,YBottom_));
            rubberBand(Point(XRight_,YBottom_),Point(XRight_,YTop_));
            rubberBand(Point(XRight_,YTop_),Point(XLeft_,YTop_));
            rubberBand(Point(XLeft_,YTop_),Point(XLeft_,YBottom_));
        }
        update();
    }
}


void MainWindow::on_actionCohen_SutherLandClip_triggered()
{
    GType_ = GCohen_Sutherland;
}


void MainWindow::on_actionLiang_BarskyClip_triggered()
{
    GType_ = GLiang_Barsky;
}


void MainWindow::on_actionPolygon_Clip_triggered()
{
    GType_ = GSutherLand_Hodgeman;
}


void MainWindow::on_actionBezierCurve_triggered()
{
    BezierSettingDialog dlg;
    if(dlg.exec() == QDialog::Accepted){
        BezierN_ = dlg.n_;
        BezierM_ = dlg.m_;
        GType_ = GBezierCurve;
    }
}

