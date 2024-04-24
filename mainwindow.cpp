#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QPixmap>
#include<QPainter>
#include"custtomlisttitem.h"
#include "QMessageBox"
#include  "chatformwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->UserPictureToolBtn->setIcon(QIcon(":/PNG/UserPicture.jpg"));
    ui->ChatsToolBtn->setIcon(QIcon(":/PNG/chats.png"));
    ui->FriendsToolBtn->setIcon(QIcon(":/PNG/friend.png"));
    ui->addToolBtn->setIcon(QIcon(":/PNG/addBtn.png"));
    this->newidget = nullptr;
    m_buttons.append(ui->SettingToolBtn);
    m_buttons.append( ui->ChatsToolBtn);
    m_buttons.append(ui->FriendsToolBtn);

    QVBoxLayout *layout = new QVBoxLayout(this->ui->Rightwidget); // 确保窗口已经创建并设置了布局
    this->ui->Rightwidget->setLayout(layout);
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

    connect(m_buttons[1], &QToolButton::clicked, this, [&]{
        this->chatsListWidget = new QListWidget(this);
        for(int i = 0; i < 10; i++)
        {
            QListWidgetItem *item = new QListWidgetItem();
            CusttomListtItem *customItem = new CusttomListtItem(":/PNG/UserPicture.jpg");
            this->chatsListWidget->addItem(item);
            this->chatsListWidget->setItemWidget(item, customItem);
        }
        ui->Midwidget->layout()->removeItem( ui->Midwidget->layout()->itemAt(1));
        ui->Midwidget->layout()->addWidget(this->chatsListWidget);
        connect(this->chatsListWidget, &QListWidget::itemClicked,[&](QListWidgetItem * item){

            if(this->ui->Rightwidget->layout()->count() > 0 && this->newidget != nullptr)
                this->ui->Rightwidget->layout()->removeWidget(this->newidget);

            this->newidget =  new ChatFormWidget();
            this->ui->Rightwidget->layout()->addWidget(newidget);
        });
    });

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

    if(m_buttons[1]->isChecked())
    {
        m_buttons[1]->setIcon(QIcon(":/PNG/chat_checked.png"));
    }
    else
    {
        m_buttons[1]->setIcon(QIcon(":/PNG/chats.png"));
    }

    if(m_buttons[2]->isChecked())
    {
        m_buttons[2]->setIcon(QIcon(":/PNG/friend_checked.png"));
    }
    else
    {
        m_buttons[2]->setIcon(QIcon(":/PNG/friend.png"));
    }
}
