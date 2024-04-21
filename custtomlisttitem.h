#ifndef CUSTTOMLISTTITEM_H
#define CUSTTOMLISTTITEM_H

#include <QWidget>

namespace Ui {
class CusttomListtItem;
}

class CusttomListtItem : public QWidget
{
    Q_OBJECT

public:
    explicit CusttomListtItem(const QString &text, QWidget *parent = nullptr);
    ~CusttomListtItem();

private:
    Ui::CusttomListtItem *ui;
};

#endif // CUSTTOMLISTTITEM_H
