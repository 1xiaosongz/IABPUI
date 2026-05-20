//
// Created by Administrator on 2026/4/13.
//

#include "../include/readfile.h"
#include <QFile>
#include <QDebug>
#include <QThread>
#include <iostream>
#include <fstream>

ReadFile::ReadFile(QObject *parent)  : QObject(parent) {

}


ReadFile::~ReadFile()
{
    if (file && mappedData) {
        file->unmap(mappedData);
        mappedData = nullptr;
    }

    if (file) {
        file->close();
        delete file;
        file = nullptr;
    }
}
bool ReadFile::openFile(const QString &path)
{
    filePath = path;

    if (!file) {
        file = new QFile(filePath, this);
    }

    if (!file->open(QIODevice::ReadOnly)) {
        qDebug() << "文件打开失败:" << file->errorString();
        return false;
    }

    index = 0;
    return true;
}
uchar* ReadFile::fileMap(qint64 index)
{
    if (!file || !file->isOpen())
        return nullptr;

    qint64 fileSize = file->size();

    if (fileSize <= 0)
        return nullptr;

    qint64 totalFrames = fileSize / frameSize;
    if (totalFrames <= 0)
        return nullptr;

    if (index >= totalFrames)
        return nullptr;

    qint64 offset = index * frameSize;

    uchar *ptr = file->map(offset, frameSize);

    return ptr;
}
bool ReadFile::invokingFunction(uchar *buffer, uint32_t *len)
{
    if (!file || !file->isOpen()) {
        if (!openFile(filePath))
            return false;
    }

    uchar *data = fileMap(index);
    if (!data) {
        qDebug() << "mmap失败";
        return false;
    }

    std::memcpy(buffer, data, frameSize);
    *len = frameSize;

    file->unmap(data);

    mappedData = nullptr;

    // index递增 + 循环保护
    qint64 totalFrames = file->size() / frameSize;
    if (totalFrames > 0) {
        index = (index + 1) % totalFrames;
    } else {
        index = 0;
    }

    return true;
}
