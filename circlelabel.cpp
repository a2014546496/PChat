#include "circlelabel.h"
#include<QPainter>
#include<QPixmap>
#include<QPainterPath>

CircleLabel::CircleLabel(const QString & text, QWidget *parent):
    QLabel(parent)
{
    setAlignment(Qt::AlignCenter);
    this->setText(text);
}

void CircleLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    // 获取控件尺寸，确保图片是圆形的
    int edge = qMin(width(), height());

    // 加载并调整图片尺寸
    QPixmap pixmap(this->text()); // 替换为图片的实际路径
    pixmap = pixmap.scaled(edge, edge, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    // 创建圆形路径
    QPainterPath path;
    path.addEllipse(0, 0, edge, edge);

    // 设置剪裁区域
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, edge, edge, pixmap);
}


