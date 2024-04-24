#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QListWidget>
#include "chatformwidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void connects();
private slots:
    void updateLeftToolBtnsCheckedButton();
private:
    ChatFormWidget * newidget;
    QListWidget *chatsListWidget;
    QList<QToolButton*> m_buttons;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
