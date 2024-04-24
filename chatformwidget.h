#ifndef CHATFORMWIDGET_H
#define CHATFORMWIDGET_H

#include <QWidget>

namespace Ui {
class ChatFormWidget;
}

class ChatFormWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatFormWidget(QWidget *parent = nullptr);
    ~ChatFormWidget();

private:
    Ui::ChatFormWidget *ui;
};

#endif // CHATFORMWIDGET_H
