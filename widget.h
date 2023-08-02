#ifndef WIDGET_H
#define WIDGET_H

#include "cilent.h"
#include <QWidget>
#include <QColor>
#include <QColorDialog>
#include <QKeyEvent>
#include <QStringListModel>
#include <QString>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    bool eventFilter(QObject *obj, QEvent *e);
    ~Widget();

private slots:
    void on_colorBtn_clicked();

    void on_exitBtn_clicked();

    void on_boldBtn_clicked(bool checked);

    void on_italicBtn_clicked(bool checked);

    void on_underlineBtn_clicked(bool checked);



    void on_comboBox_currentIndexChanged(const QFont &font);



    void on_sendBtn_clicked();

    void showMsg(QString msg);

    void showList(QStringList list);
    void on_clearBtn_clicked();

private:
    QString allMsg;
    Ui::Widget *ui;
    Cilent* cilent;
    QColor color;
};
#endif // WIDGET_H
