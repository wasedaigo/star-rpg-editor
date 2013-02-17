#ifndef MATERIALDIALOG_H
#define MATERIALDIALOG_H

#include <QDialog>
#include "ResourceModel.h"

namespace Ui {
class DatabaseDialog;
}

class DatabaseDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DatabaseDialog(QWidget *parent, ResourceModel *resourceModel);
    ~DatabaseDialog();

signals:
    
public slots:

private:
    QScopedPointer<Ui::DatabaseDialog> mUI;
    ResourceModel *mResourceModel;
};

#endif // MATERIALDIALOG_H
