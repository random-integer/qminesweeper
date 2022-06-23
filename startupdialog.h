#ifndef STARTUPDIALOG_H
#define STARTUPDIALOG_H

#include <QDialog>
#include <QObject>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class StartupDialog; }
QT_END_NAMESPACE

class StartupDialog : public QDialog {
    Q_OBJECT
public:
    StartupDialog(QWidget *parent = nullptr);
    ~StartupDialog();

private:
    Ui::StartupDialog *ui;
};

#endif // STARTUPDIALOG_H
