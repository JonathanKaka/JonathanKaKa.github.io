/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-12-04
Email:kevinlq0912@163.com
QQ:936563422
Description:智能家居--温度控制模块


这部分内容是关于QT C++编程方面的知识点
**************************************************/
#ifndef TEMPTURESETTING_H
#define TEMPTURESETTING_H

#include <QWidget>

class QToolButton;

namespace Ui {
class TemptureSetting;
}

#namespace ui(QT)知识点：https://blog.csdn.net/NanYunQingNiao/article/details/93416162
#C++命名空间知识点：https://www.runoob.com/cplusplus/cpp-namespaces.html
#C++中冒号:和双冒号::的作用：https://blog.csdn.net/yuzaipiaofei/article/details/6594404
#C++中*和&符号的作用：https://blog.csdn.net/chuodun0399/article/details/100765688

class TemptureSetting : public QWidget
{
    Q_OBJECT
    
public:
    explicit TemptureSetting(QWidget *parent = 0);
    ~TemptureSetting();

private slots:
    void on_tbn_temp_add_clicked();

    void on_tbn_temp_sub_clicked();

    void on_tbn_hum_add_clicked();

    void on_tbn_hum_sub_clicked();

private:

    void initForm();            //初始化界面样式
    void initConnect();         //初始化信号和槽的连接

    void refreshData();         //刷新数据
    //设置按钮样式
    void setToolButtonStyle(QToolButton*tbn, const QString &text,
                            const QString iconName);
    
private:
    Ui::TemptureSetting *ui;

    int m_tempture;                 //温度预设值
    int m_humidity;                  //湿度预设值
};

#endif // TEMPTURESETTING_H
