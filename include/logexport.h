//
// Created by Administrator on 2026/7/13.
//

#ifndef IABPUI_LOGEXPORT_H
#define IABPUI_LOGEXPORT_H

#include <QWidget>
#include <QPushButton>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "QStandardItemModel"
#include <QStringListModel>
#include <QCompleter>
#include <QDebug>
#include <QPainter>
#include <QListView>
QT_BEGIN_NAMESPACE

namespace Ui {
    class LogExport;
}

QT_END_NAMESPACE

class LogExport : public QWidget {
    Q_OBJECT

public:
    explicit LogExport(QWidget *parent = nullptr);

    ~LogExport() override;
private slots:
    void tableButtonClicked();    // 左侧动态按钮点击事件
    void initTableViewStyle();   // 初始化表格外观与QSS皮肤
    void loadDataFromMySQL();    // 连接MySQL并加载数据
    void Time_Button(); // <-- 声明在这里
private:
    Ui::LogExport *ui;
    QStandardItemModel *tableModel; // 保存表格数据的模型指针
    QStringList patientList;
    QStringListModel *completerModel;
    QCompleter *patientCompleter;
    //动态创建按钮
    void createTableButtons();
    void refreshStyle(QWidget *w);
};


#endif //IABPUI_LOGEXPORT_H
