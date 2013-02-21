#ifndef MATERIALDIALOG_H
#define MATERIALDIALOG_H

#include <QDialog>

namespace Ui {
class DatabaseDialog;
}

class GameDataModel;
class DatabaseDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DatabaseDialog(QWidget *parent, GameDataModel *gameDataModel);
    ~DatabaseDialog();

signals:
    
public slots:

private:
    QScopedPointer<Ui::DatabaseDialog> mUI;
};

#endif // MATERIALDIALOG_H
