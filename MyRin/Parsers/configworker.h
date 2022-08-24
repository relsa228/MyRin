#ifndef CONFIGWORKER_H
#define CONFIGWORKER_H

#include <QMap>
#include <QFile>
#include <QFileInfo>
#include <QJsonObject>
#include <QString>

class ConfigWorker
{
public:
    QMap<QString, int> config;

public:
    ConfigWorker();   
    void configRead();
    void configSave();

private:
    void checkForExisting();
};

#endif // CONFIGWORKER_H
