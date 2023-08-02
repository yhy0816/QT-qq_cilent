#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    cilent = new Cilent(this);
    connect(cilent, &Cilent::getMsgSignal, this, &Widget::showMsg);
    connect(cilent, &Cilent::getListSignal, this, &Widget::showList);
    ui->textEdit->installEventFilter(this);
}

Widget::~Widget()
{
    delete cilent;
    delete ui;
}


void Widget::on_colorBtn_clicked()
{
    color = QColorDialog::getColor(color, this);
    if(color.isValid()){
        ui->textEdit->setTextColor(color);
        ui->textEdit->setFocus();
    }
}

void Widget::on_exitBtn_clicked()
{
    this->close();
}

void Widget::on_boldBtn_clicked(bool checked)
{
    if(checked)
    {
        ui->textEdit->setFontWeight(QFont::Bold);
    }
    else
    {
        ui->textEdit->setFontWeight(QFont::Normal);

    }
    ui->textEdit->setFocus();
}

void Widget::on_italicBtn_clicked(bool checked)
{

    ui->textEdit->setFontItalic(checked);

    ui->textEdit->setFocus();
}

void Widget::on_underlineBtn_clicked(bool checked)
{
    ui->textEdit->setFontUnderline(checked);
    ui->textEdit->setFocus();

}



void Widget::on_comboBox_currentIndexChanged(const QFont &font)
{
    ui->textEdit->setCurrentFont(font);
    ui->textEdit->setFocus();

}



void Widget::on_sendBtn_clicked()
{
    cilent->sendMsg(ui->textEdit->document()->toHtml());
    ui->textEdit->clear();

}


void Widget::showMsg(QString msg){
    allMsg += msg + "\r\n";
    //qDebug() << QString("msg");
    ui->messageTextEdit->setHtml(allMsg);
}




bool Widget::eventFilter(QObject *target, QEvent *event)
{
    if(target == ui->textEdit)		//可替换
        {
            if(event->type() == QEvent::KeyPress)//回车键
            {
                 QKeyEvent *k = static_cast<QKeyEvent *>(event);

                 if(k->key() == Qt::Key_Return)
                 {
                     on_sendBtn_clicked();		//替换为需要响应的函数事件，以这里的按钮为例
                     return true;
                 }
            }
        }
        return QWidget::eventFilter(target,event);
}



void Widget::on_clearBtn_clicked()
{
    ui->messageTextEdit->clear();
    allMsg.clear();
}

void Widget::showList(QStringList list){
    ui->userTableView->setModel(new QStringListModel(list));
    ui->userNumLabel->setText("在线用户人数：" + QString::number(list.size()) +"人");
}

