//
// Created by Administrator on 2026/7/13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_LogExport.h" resolved

#include "logexport.h"
#include "ui_LogExport.h"
#include <QSortFilterProxyModel>
#include <QCompleter>
#include "datewidget.h"
#include <QDialog>
#include <QVBoxLayout>
LogExport::LogExport(QWidget *parent) : QWidget(parent), ui(new Ui::LogExport) {
    ui->setupUi(this);
    move(0, 0);
    setVisible(false);
    //创建数据库表按钮
    ui->TableScrollArea->setWidgetResizable(true);
    ui->TableScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->TableScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    createTableButtons();
    // ui->TableScrollArea->setObjectName("TableScrollArea");
    ui->TableScrollArea->setAttribute(Qt::WA_StyledBackground, true);
    ui->TableScrollArea->widget()->setAttribute(Qt::WA_StyledBackground, true);
    ui->label11->setProperty("mode", "Label11");
    refreshStyle(ui->label11);
    ui->label_13->setProperty("mode", "25px,colour255,255,255");
    ui->label_28->setProperty("mode", "25px,colour255,255,255");
    ui->label_30->setProperty("mode", "25px,colour255,255,255");
    ui->label_27->setProperty("mode", "25px,colour255,255,255");
    ui->Refresh_Page_Button->setProperty("mode", "RefreshButton");
    ui->Left_Button->setProperty("mode", "Left_Button");
    ui->Right_Button->setProperty("mode", "Right_Button");
    ui->pageLabel->setProperty("mode", "PageLabel");
    ui->Export_Cancel_Background->setProperty("mode", "Export_Cancel_Background");
    ui->Export_Cancel_Label->setText("导出");
    ui->Export_Cancel_Label->setProperty("mode", "25px,colour255,255,255");
    ui->Number_Pages->setProperty("mode", "25px,colour4,255,255");
    ui->Number_Total_Pages->setProperty("mode", "25px,colour4,255,255");
    ui->Patient_ID->setProperty("mode", "Patient_ID");
    ui->Starting_Time_Background->setProperty("mode", "Label_Time");
    ui->End_Time_Background->setProperty("mode", "Label_Time");
    ui->Start_Time_Number->setProperty("mode", "22px,colour4,255,255");
    ui->End_Time_Number->setProperty("mode", "22px,colour4,255,255");
    ui->label_2->setProperty("mode", "Label_dataPanel_background");
    ui->label->setProperty("mode", "Label_Top_Background");
    ui->Close_Button->setProperty("mode", "LogExport_Close_Button");
    ui->label_3->setProperty("mode", "25px,colour255,255,255");
    // 2. 调用美化表格函数与加载数据函数
    initTableViewStyle();
    loadDataFromMySQL();
    // ui->LineNumberComboBox->setObjectName("LineNumberComboBox");
    // 2. 开启 QListView 渲染
    QAbstractItemView *view = ui->LineNumberComboBox->view();
    // view->setFixedWidth(80);
    view->window()->setWindowFlags(
        Qt::Popup |
        Qt::FramelessWindowHint |
        Qt::NoDropShadowWindowHint
    );
    view->window()->setAttribute(
        Qt::WA_TranslucentBackground
    );
    // 3. 添加数据项
    ui->LineNumberComboBox->addItem("1");
    ui->LineNumberComboBox->addItem("2");
    ui->LineNumberComboBox->addItem("3");
    ui->LineNumberComboBox->addItem("4");
    ui->LineNumberComboBox->setCurrentIndex(0);
    // 4. 让文字绝对水平居中
    for (int i = 0; i < ui->LineNumberComboBox->count(); ++i) {
        ui->LineNumberComboBox->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
    ui->Start_Time_Button->setProperty("associatedLabel", QVariant::fromValue(ui->Start_Time_Number));
    ui->End_Time_Button->setProperty("associatedLabel", QVariant::fromValue(ui->End_Time_Number));
    connect(ui->Start_Time_Button, &QPushButton::clicked, this, &LogExport::Time_Button);
    connect(ui->End_Time_Button, &QPushButton::clicked, this, &LogExport::Time_Button);
  patientList << "赵一" << "赵二" << "赵三" << "赵四"
                << "张一" << "张二" << "张三" << "张四"
                << "李一" << "李二" << "王一" << "王二"
                << "钱一" << "钱二" << "孙一" << "孙二"
                << "周一" << "周二" << "吴一" << "吴二";
    QStandardItemModel *completerModel = new QStandardItemModel(this);
    for (const QString &name : patientList) {
        QStandardItem *item = new QStandardItem(name);
        // 关键步骤：设置文本居中对齐 (水平居中 + 垂直居中)
        item->setTextAlignment(Qt::AlignCenter);
        completerModel->appendRow(item);
    }
    patientCompleter = new QCompleter(completerModel, this);
    patientCompleter->setFilterMode(Qt::MatchContains);
    patientCompleter->setMaxVisibleItems(5);

    QAbstractItemView *popupView = patientCompleter->popup();
    popupView->setObjectName("PatientCompleterPopup");

    if (popupView->window()) {
        popupView->window()->setWindowFlags(Qt::Popup | Qt::NoDropShadowWindowHint | Qt::FramelessWindowHint);
        popupView->window()->setAttribute(Qt::WA_TranslucentBackground, false);
    }
    popupView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    popupView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    popupView->setFixedSize(228, 227);
    popupView->setAttribute(Qt::WA_StyledBackground, true);
    popupView->viewport()->setObjectName("PatientCompleterViewport");
    popupView->viewport()->setAttribute(Qt::WA_StyledBackground, true);
    ui->Patient_ID->setCompleter(patientCompleter);
}

LogExport::~LogExport() {
    delete ui;
}

void LogExport::createTableButtons()
{
    QWidget *container = new QWidget();
    // container->setObjectName("ScrollAreaWidgetContents"); // 保持你样式表里的名字
    container->setAttribute(Qt::WA_StyledBackground, true);
    QVBoxLayout *layout = new QVBoxLayout(container);
    layout->setSpacing(10);
    layout->setContentsMargins(6, 5, 6, 5);
    QStringList tableList;
    tableList << "abp分析"   << "患者会话" << "告警事件" << "设备状态" << "趋势看板"
              << "历史数据" << "报表导出" << "系统设置" << "用户管理" << "日志审计"
    << "abp分析"   << "患者会话" << "告警事件" << "设备状态" << "趋势看板"
              << "历史数据" << "报表导出" << "系统设置" << "用户管理" << "日志审计";
    bool isFirst = true;
    for(QString tableName : tableList) {
        // 注意：这里的 parent 设为新创建的 container
        QPushButton *button = new QPushButton(container);
        button->setText(tableName);
        button->setObjectName("BtnTable_" + tableName);
        button->setFixedHeight(50); // 固定高度
        button->setFixedWidth(140);
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        // --- 开启单选高亮模式 ---
        button->setCheckable(true);
        button->setAutoExclusive(true);
        // 添加到新布局中
        layout->addWidget(button);

        if (isFirst) {
            button->setChecked(true);
            isFirst = false;
        }
        connect(button, &QPushButton::clicked, this, &LogExport::tableButtonClicked);
    }
    // 3. 在最后添加一个弹簧，确保按钮不被拉伸，且能撑开高度
    layout->addStretch();
    // 4. 【最关键的一步】：把这个动态生成的、拥有正确高度的新画布，塞进滚动区域
    ui->TableScrollArea->setWidget(container);
}

//==============================
//按钮点击
//==============================
void LogExport::tableButtonClicked()
{
    QPushButton *btn =qobject_cast<QPushButton*>(sender());
    if(btn)
    {
        qDebug() << "选择数据库表:" << btn->text();
    }
}

// 1. 初始化表格外观与 QSS 科技感皮肤
void LogExport::initTableViewStyle() {
    // 基础交互安全配置
    ui->TableView->setSelectionBehavior(QAbstractItemView::SelectRows); // 整行选中
    ui->TableView->setSelectionMode(QAbstractItemView::SingleSelection); // 单选
    ui->TableView->setEditTriggers(QAbstractItemView::NoEditTriggers);   // 禁止双击修改
    ui->TableView->setShowGrid(false);                                   // 去掉原生白格子线
    ui->TableView->setAlternatingRowColors(true);                        // 开启斑马纹隔行变色
    ui->TableView->verticalHeader()->setVisible(false);                  // 隐藏最左侧行号
    ui->TableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 列宽自适应平分
    // 关键 1：让内部视口透明
    ui->TableView->viewport()->setStyleSheet("background-color: transparent;");
}

void LogExport::loadDataFromMySQL() {
    // 1. 创建标准数据模型
    tableModel = new QStandardItemModel(this);
    // 确保这里的表头字段数量，与下面 mockRows 每一行的元素数量完全一致（都是13个）
    QStringList headerLabels = {
        "id", "开始时间", "结束时间", "患者ID", "患者编号",
        "绑定时间", "解绑时间", "时间", "年龄", "性别",
        "主治医生", "诊断科室", "当前状态"
    };
    tableModel->setHorizontalHeaderLabels(headerLabels);
    ui->TableView->setModel(tableModel);
    // 2. 手动制造假数据（精准补齐到了 13 列）
    QList<QList<QVariant>> mockRows = {
        {"1001-00-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-01-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-02-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-03-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-04-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-05-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-06-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-07-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-08-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-09-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-10-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-11-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-12-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-13-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-14-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-15-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-16-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-17-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-18-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-19-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-20-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-21-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-22-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-23-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-24-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-25-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-26-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-27-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-28-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-29-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-30-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-31-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-32-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-33-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-01-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-01-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-01-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-01-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-01-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-01-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
{"1001-01-11-123456-888", "08:00:00-01-11-123456-888", "09:00:00-01-11-123456-888", "1-01-11-123456-888", "2-01-11-123456-888", "3-01-11-123456-888", 0, "2026-07-08-01-11-123456-888-01-11-123456-888", 28, "男", "张医生-01-11-123456-888", "内科-01-11-123456-888", "已就诊"},
    };
    // 3. 将假数据装填到表格中
    for (const QList<QVariant>& rowData : mockRows) {
        QList<QStandardItem*> rowItems;

        // 防御性安全检查：确保这行数据的列数足够
        if (rowData.size() < headerLabels.count()) {
            qWarning() << "发现数据列数不足，跳过此行！";
            continue;
        }
        for (int i = 0; i < headerLabels.count(); ++i) {
            QString colName = headerLabels.at(i);
            QStandardItem *item = new QStandardItem();

            if (colName == "id") {
                item->setText(rowData.at(i).toString());
                item->setForeground(QBrush(QColor("#00b4d8"))); // 青蓝色高亮
                item->setTextAlignment(Qt::AlignCenter);
            }
            else {
                // 普通列
                item->setText(rowData.at(i).toString());
                item->setTextAlignment(Qt::AlignCenter);
            }
            rowItems.append(item);
        }
        tableModel->appendRow(rowItems);
    }
    // 1. 获取当前 tableView 的固定总高度与总宽度
    int totalHeight = ui->TableView->height();
    int totalWidth = ui->TableView->width();
    // 2. 显式设定表头固定高度（与你的 QSS 14px 字体 + 10px padding 完美呼应）
    int headerHeight = 45;
    ui->TableView->horizontalHeader()->setFixedHeight(headerHeight);
    // 3. 计算 30 行单元格的精准平分行高
    // 提示：-2 像素是为了扣除系统上下边框线条占用的空间，防止精度四舍五入触发垂直滚动条
    int availableHeight = totalHeight - headerHeight - 2;
    int rowHeight = availableHeight / 26;
    // 应用行高
    ui->TableView->verticalHeader()->setDefaultSectionSize(rowHeight);
    ui->TableView->verticalHeader()->setVisible(false); // 确保左侧行号隐藏
    // 4. 宽度完美占满铺开
    int columnCount = tableModel->columnCount();
    if (columnCount > 0) {
        // 精准计算每列基础宽度
        int colWidth = (totalWidth - 2) / columnCount;
        ui->TableView->horizontalHeader()->setDefaultSectionSize(colWidth);
    }
    // 5. 模式安全切换：既保证初始完美铺满，又允许超长文字的列可以被手动拖大
    ui->TableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    // 如果某些单元格内容特别长，这一步可以帮你在初始状态下微调超长列，其余列保持均分
    // ui->tableView->resizeColumnsToContents(); // 如果需要严格的机械平分，可以注释掉这行
    // 6. 滚动条策略配置
    ui->TableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);   // 30行完美占满，关闭垂直滚动条
    ui->TableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded); // 超长文字列若被拖大，允许横向滚动
    // 4. 确保水平滚动条在需要时自动出现
    ui->TableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    // 5. 关键：不要让列去平分、压缩宽度，允许它们保持自适应或固定宽度，这样超出边界才会触发滚动条
    ui->TableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->TableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    // 让列宽根据内容自动伸展（防止字太多显示不全）
    ui->TableView->resizeColumnsToContents();
}

void LogExport::refreshStyle(QWidget *w) {
    w->style()->unpolish(w);
    w->style()->polish(w);
    w->update();
}
void LogExport::Time_Button()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton) {
        return; // 如果不是 QPushButton 触发的，安全退出
    }
    QVariant prop = clickedButton->property("associatedLabel");
    QLabel *targetLabel = prop.value<QLabel*>();
    if (!targetLabel) {
        return; // 如果没有绑定对应的 Label，安全退出
    }
    QDialog *dialog = new QDialog(this);
    dialog->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    // 设置对话框无问号、只有关闭按钮，看起来更干净
    // dialog->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    dialog->setAttribute(Qt::WA_TranslucentBackground);
    // 2. 实例化你封装好的日历控件，并把 dialog 设置为它的父对象
    DateWidget *dateWidget = new DateWidget(dialog);
    // 3. 使用垂直布局管理器，把日历控件塞进对话框里
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(dateWidget);
    layout->setContentsMargins(0, 0, 0, 0); // 留一点点边距，你可以根据喜好调整为 0
    dialog->setLayout(layout);
    dialog->setMinimumSize(500, 500);
    // 4. 【核心连接】监听日历的日期选择信号
    connect(dateWidget, &DateWidget::dateChanged, this, [this,targetLabel, dialog](const QDate &date) {
        // --- 拿到日期后，在这里写你的业务逻辑 ---
        targetLabel->setText(date.toString("yyyy-MM-dd"));
        dialog->accept();
    });
    // 5. 弹出对话框（exec()会阻塞主界面，直到对话框被关闭）
    dialog->exec();
    // 6. 对话框关闭后，安全释放内存
    dialog->deleteLater();
}