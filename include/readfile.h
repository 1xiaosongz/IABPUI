//
// Created by Administrator on 2026/4/13.
//

#ifndef IABPUI_READFILE_H
#define IABPUI_READFILE_H
#include <QString>
#include <QWidget>
#include <QFile>
#include <QTimer>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#pragma pack(push, 1)
#include "definitions.h"
#pragma pack(pop)
#include <QObject>
class ReadFile : public QObject{
    Q_OBJECT
public:
       explicit ReadFile(QObject *parent = nullptr);
        ~ReadFile();
    bool openFile(const QString &filePath);
    bool invokingFunction(uchar *buffer, uint32_t *len);
private:
    uchar* fileMap(qint64 index);

private:
    QFile *file = nullptr;

    uchar *mappedData = nullptr;

    qint64 index = 0;              // 当前帧索引
    const uint32_t frameSize = 128 * 1024; // 128KB
    QString filePath = "D:\\Mark\\pythonProject\\20\\originalData\\5124.dat";
//         void setFilePath(const QString& path);
//
// public slots:
//     void startRead();
// signals:
//         //  发给 Statusbar
//     void sigStatus(uint32_t heartRate,
//                        uint32_t maxBP,
//                        uint32_t minBP,
//                        uint32_t avgBP,
//                        uint32_t typeTrig);
//
//     //  发给 WaveformSeparation（打包波形）
//     void sigWave(int fir_I_LA,
//                  int fir_II_LL,
//                  int fir_III_RA,
//                  int fir_V1,
//                  int fir_V2,
//                  int fir_Blood_P,
//                  int fir_Balloon_P);
//
// private:
//     QString m_path;

};


#endif //IABPUI_READFILE_H