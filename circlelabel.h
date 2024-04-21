#ifndef CIRCLELABEL_H
#define CIRCLELABEL_H

#include <QLabel>

class CircleLabel : public QLabel
{
public:
    explicit CircleLabel(const QString & text, QWidget * parent = nullptr);
protected:
    void paintEvent(QPaintEvent * event) override;
};

#endif // CIRCLELABEL_H
