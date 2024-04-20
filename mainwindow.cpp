#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QPixmap>
#include<QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->UserPictureToolBtn->setIcon(QIcon(":/PNG/UserPicture.jpg"));
    ui->ChatsToolBtn->setIcon(QIcon(":/PNG/chats.png"));
    ui->FriendsToolBtn->setIcon(QIcon(":/PNG/friend.png"));
    m_buttons.append(ui->SettingToolBtn);
    m_buttons.append( ui->ChatsToolBtn);
    m_buttons.append(ui->FriendsToolBtn);
    connects();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connects()
{
    for(auto btn: m_buttons)
    {
        connect(btn, &QToolButton::clicked, this, &MainWindow::updateLeftToolBtnsCheckedButton);
    }
}

void MainWindow::updateLeftToolBtnsCheckedButton()
{
    static QToolButton * lastBtn = nullptr;
    QToolButton *senderButton = qobject_cast<QToolButton*>(sender());
    if (!senderButton)
        return;

    if(lastBtn == senderButton)
    {
        senderButton->setChecked(true);
        return;
    }

    lastBtn = senderButton;

    // 确保只有一个按钮被选中
    for (QToolButton *button : m_buttons) {
        if (button != senderButton)
            button->setChecked(false);
    }
}
