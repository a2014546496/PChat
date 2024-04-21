#include "custtomlisttitem.h"
#include "ui_custtomlisttitem.h"
#include<QGridLayout >
#include<QLabel>
#include"circlelabel.h"

CusttomListtItem::CusttomListtItem(const QString &text,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CusttomListtItem)
{
    ui->setupUi(this);
    QGridLayout  *layout = new QGridLayout (this);
    CircleLabel *label = new CircleLabel(text);
    QLabel * namelabel = new QLabel("namelabelnamelabelnamelabelnamelabelnamelabel");
    QLabel * contentlabel = new QLabel("contentlabelcontentlabelcontentlabelcontentlabel");
    QLabel * timelabel = new QLabel("timelabel");
    label->setStyleSheet("color: black;"); // 自定义文本样式
    layout->addWidget(label,0,0,3,1);
    layout->addWidget(namelabel, 0,1,1,3);
    layout->addWidget(contentlabel,2,1,1,4);
    layout->addWidget(timelabel,0,5);
    layout->setColumnMinimumWidth(0, 40); // 第一列的最小宽度为100
    this->setLayout(layout);
}

CusttomListtItem::~CusttomListtItem()
{
    delete ui;
}
