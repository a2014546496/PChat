#include "chatformwidget.h"
#include "ui_chatformwidget.h"

ChatFormWidget::ChatFormWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatFormWidget)
{
    ui->setupUi(this);
}

ChatFormWidget::~ChatFormWidget()
{
    delete ui;
}
