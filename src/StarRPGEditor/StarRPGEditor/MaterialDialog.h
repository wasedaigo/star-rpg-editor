#ifndef MATERIALDIALOG_H
#define MATERIALDIALOG_H

#include <QDialog>

namespace Ui {
class MaterialDialog;
}
class ResourceModel;

class MaterialDialog : public QDialog
{
    Q_OBJECT
public:
    explicit MaterialDialog(QWidget *parent, QSharedPointer<ResourceModel> resourceModel);
    ~MaterialDialog();

signals:
    
public slots:

private:
    QScopedPointer<Ui::MaterialDialog> mUI;
    QSharedPointer<ResourceModel> mResourceModel;
};

#endif // MATERIALDIALOG_H
