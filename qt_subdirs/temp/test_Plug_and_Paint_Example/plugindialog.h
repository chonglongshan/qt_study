#ifndef PLUGINDIALOG_H
#define PLUGINDIALOG_H

#include <QDialog>

class PluginDialog : public QDialog
{
public:
    PluginDialog(const QString &path, const QStringList &fileNames,
                 QWidget *parent = nullptr);
};

#endif // PLUGINDIALOG_H
