#ifndef MEDSYSTEMSETTINGSWIDGET_H
#define MEDSYSTEMSETTINGSWIDGET_H

#include <QWidget>
#include "medSettingsWidget.h"

class medSystemSettingsWidgetPrivate;

class medSystemSettingsWidget : public medSettingsWidget
{
    Q_OBJECT
public:
    medSystemSettingsWidget(QWidget *parent = 0);

signals:

public slots:

protected:
	/**
	 * @brief Performs the validation of each control inside the widget.
	 *
	 * @param void
	 * @return true is the validation is successful, false otherwise.
	*/
    bool validate(void);

private:
  medSystemSettingsWidgetPrivate *d;

  /**
   * @brief Validates a line of text containing paths.
   * For the text to be valid, it has to match any of the
   * following three regular expressions: <path>[:<path>]*
   * or [<path>:]+ or just <path>, where <path> are valid paths in the system.
   * Note that colons shall be used to separate paths, which is the Unix standard,
   * not like semicolons, a Windows standard.
   *
   * @param The string containing the paths
   * @return true is the paths are valid, false otherwise
  */
  bool validatePaths(QString paths);
};

medSettingsWidget* createSystemSettingsWidget(QWidget *parent);
#endif // MEDSYSTEMSETTINGSWIDGET_H
