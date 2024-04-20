#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>

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
    QList<QToolButton*> m_buttons;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
