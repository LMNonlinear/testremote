#include "medSystemSettingsWidget.h"

#include <QWidget>
#include <QtGui>
#include <QDir>
#include <QtCore>

#include <dtkScript/dtkScriptManager.h>

#include <medCore/medPluginManager.h>
#include <medCore/medSettingsManager.h>

class medSystemSettingsWidgetPrivate {

public:
  QWidget* parent;
  QLineEdit* pluginsPathField;
  QLineEdit* modulesPathField;
  QLineEdit* scriptsPathField;

  medSystemSettingsWidgetPrivate();
  ~medSystemSettingsWidgetPrivate();
};

medSystemSettingsWidgetPrivate::medSystemSettingsWidgetPrivate()
{
}

medSystemSettingsWidgetPrivate::~medSystemSettingsWidgetPrivate()
{
}


medSystemSettingsWidget::medSystemSettingsWidget(QWidget *parent) :
        medSettingsWidget(parent),
        d(new medSystemSettingsWidgetPrivate())
{
    setTabName("System");
    d->pluginsPathField = new QLineEdit(this);
    d->modulesPathField = new QLineEdit(this);
    d->scriptsPathField = new QLineEdit(this);
    QFormLayout* layout = new QFormLayout;
    layout->addRow(tr("Plugins Path"),d->pluginsPathField);
    layout->addRow(tr("Modules Path"),d->modulesPathField);
    layout->addRow(tr("Scripts Path"),d->scriptsPathField);
    this->setLayout(layout);
}


medSettingsWidget* createSystemSettingsWidget(QWidget *parent){
    return new medSystemSettingsWidget(parent);
}

bool medSystemSettingsWidget::validate()
{
    if (!validatePaths(d->pluginsPathField->text()))
        return false;

    if (!validatePaths(d->modulesPathField->text()))
        return false;

    if (!validatePaths(d->scriptsPathField->text()))
        return false;

    return true;
}

bool medSystemSettingsWidget::validatePaths(QString paths)
{
    //empty paths are allowed, the user hasn't configured them yet
    if (paths.isEmpty())
        return true;

    // splitting on a colon only obviously can not be considered safe on windows! skipping for the moment
    /*
    QStringList splitted = paths.split(":");

    foreach (QString path, splitted) {
        // two consecutive colons won't be allowed
        if (path.isEmpty())
            return false;

        // path is not empty, does it exist in the system?
        if (!QDir(path).exists())
            return false;
    }
    */

    return true;
}

void medSystemSettingsWidget::read()
{
    qDebug()<<"reading QSettings";
    medSettingsManager * mnger = medSettingsManager::instance();
    d->pluginsPathField->setText(mnger->value("plugins","path").toString());
    d->modulesPathField->setText(mnger->value("scripts","modules_path").toString());
    d->scriptsPathField->setText(mnger->value("scripts","script_path").toString());
}

bool medSystemSettingsWidget::write()
{
    medSettingsManager * mnger = medSettingsManager::instance();
    mnger->setValue("plugins","path",d->pluginsPathField->text());
    mnger->setValue("scripts","modules_path",d->modulesPathField->text());
    mnger->setValue("scripts","script_path",d->scriptsPathField->text());

    //medPluginManager::instance()->setPath(d->pluginsPathField->text());
    //dtkScriptManager::instance()->setScriptPath(d->scriptsPathField->text());
    //dtkScriptManager::instance()->setModulePath(d->modulePathField->text());

    return true;
}

QString medSystemSettingsWidget::description() const
{
    return "System";
}


