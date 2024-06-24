#ifndef NEW_BUILD_H
#define NEW_BUILD_H

#include <QWidget>
#include "widget.h"

namespace Ui {
class new_build;
}

class new_build : public QWidget
{
    Q_OBJECT

public:
    explicit new_build(QWidget *parent = nullptr);
    ~new_build();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

    void on_backButton_clicked();

private:
    Ui::new_build *ui;
};

#endif // NEW_BUILD_H
