#ifndef KBWIDGET_H
#define KBWIDGET_H

#include <QFile>
#include <QTableWidgetItem>
#include <QWidget>
#include "kb.h"
#include "xcb/xwindowdetector.h"

// Central widget for displaying/controlling a device

namespace Ui {
class KbWidget;
}

class KbWidget : public QWidget
{
    Q_OBJECT

public:
    explicit KbWidget(QWidget* parent, Kb* _device, XWindowDetector* windowDetector);
    ~KbWidget();

    // Device handle
    Kb* device;
    inline QString name() const { return device->usbModel; }

    // Has the "there is a firmware upgrade for this device..." screen already been shown?
    bool hasShownNewFW;
    // Update the "Check for updates" label with the current status
    void updateFwButton();
    void setTabBarEnabled(const bool e);

public slots:
    // Show a tab
    void showFirstTab();
    void showLastTab();

    // Display firmware update dialog
    inline void showFwUpdate()          { on_fwUpdButton_clicked(); }

private:
    Ui::KbWidget *ui;
    quint64 lastAutoSave;

    KbMode* currentMode;

    const static int GUID = Qt::UserRole;
    const static int NEW_FLAG = Qt::UserRole + 1;
    int getPollRateBoxIdx(QString poll);

    KbMode* prevmode;
    void openEventMgr(KbMode* mode);
private slots:
    void updateProfileList();
    void on_profileBox_activated(int index);

    void modeChanged();
    void currentSelectionChanged(const QModelIndex& current, const QModelIndex& previous);
    void on_modesList_customContextMenuRequested(const QPoint &pos);

    void devUpdate();
    void on_hwSaveButton_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_fwUpdButton_clicked();
    void on_layoutBox_activated(int index);
    void switchToProfile(QString profile);
    void switchToMode(QString mode);
    void on_pollRateBox_currentIndexChanged(const QString& arg1);
    void switchToModeByFocus(XWindowInfo win);
    void on_modesList_doubleClicked(const QModelIndex& index);
    void on_modesList_clicked(const QModelIndex& index);
};

#endif // KBWIDGET_H
