#define SAVE_BEFORE_EXIT "SaveBeforeExit"
#define DELETE_PERSONE_APROVE "DeletePersoneAprove"
#define CLEAN_DATABASE_APROVE "CleanDatabaseAprove"

#include "configworker.h"

ConfigWorker::ConfigWorker()
{

}

void ConfigWorker::configRead()
{
    QDir dir;
    QMap<QString, int> config;
    QFile configFile(dir.absolutePath() + "/config.json");
    checkForExisting();

    configFile.open(QIODeviceBase::ReadOnly);
    QJsonDocument documentConfig = QJsonDocument().fromJson(configFile.readAll());
    QJsonObject serializeConfig = documentConfig.object();

    config.insert(SAVE_BEFORE_EXIT, serializeConfig.value(SAVE_BEFORE_EXIT).toInt());
    config.insert(DELETE_PERSONE_APROVE, serializeConfig.value(DELETE_PERSONE_APROVE).toInt());
    config.insert(CLEAN_DATABASE_APROVE, serializeConfig.value(CLEAN_DATABASE_APROVE).toInt());

    this->config = config;
}

void ConfigWorker::configSave()
{
    QDir dir;

    QJsonObject serializeConfig;
    serializeConfig.insert(SAVE_BEFORE_EXIT, config[SAVE_BEFORE_EXIT]);
    serializeConfig.insert(DELETE_PERSONE_APROVE, config[DELETE_PERSONE_APROVE]);
    serializeConfig.insert(CLEAN_DATABASE_APROVE, config[CLEAN_DATABASE_APROVE]);

    QJsonDocument documentConfig = QJsonDocument(serializeConfig);

    QFile configFile(dir.absolutePath() + "/config.json");
    if (configFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
      configFile.close();

    configFile.open(QIODeviceBase::WriteOnly);
    configFile.write(documentConfig.toJson());
    configFile.flush();
    configFile.close();
}

void ConfigWorker::checkForExisting()
{
    QDir dir;
    QFileInfo checkFile(dir.absolutePath() + "/config.json");

    if(!checkFile.exists())
    {
        QJsonObject serializeConfig;
        serializeConfig.insert(SAVE_BEFORE_EXIT, 1);
        serializeConfig.insert(DELETE_PERSONE_APROVE, 1);
        serializeConfig.insert(CLEAN_DATABASE_APROVE, 1);

        QJsonDocument documentConfig = QJsonDocument(serializeConfig);

        QFile configFile(dir.absolutePath() + "/config.json");
        configFile.open(QIODeviceBase::WriteOnly);
        configFile.write(documentConfig.toJson());
        configFile.flush();
        configFile.close();
    }
}
