#ifndef WINDOWINFO_H
#define WINDOWINFO_H
#include <QString>
#include <QSettings>
#include "ckbsettings.h"

class KbMode;
class KbWindowInfo : public QObject
{
    Q_OBJECT
public:
    KbWindowInfo(KbMode* parent);
    KbWindowInfo(KbMode* parent, const KbWindowInfo& other);

    // Match data
    QString windowTitle;
    // Should the window title be matched case insensitive?
    bool windowTitleCaseInsensitive;
    // Should the window title be a substring of the actual window?
    bool windowTitleSubstr;
    // Binary name
    QString program;
    // Linux specific
    QString wm_instance_name;
    QString wm_class_name;
    inline bool needsSave() const { return _needsSave; }
    void load(CkbSettingsBase& settings);
    void save(CkbSettingsBase& settings);
    inline bool isEmpty() { return windowTitle.isEmpty() && program.isEmpty() && wm_instance_name.isEmpty() && wm_class_name.isEmpty(); }
    inline void setEnabled(const bool e) {
        if(enabled == e)
            return;
        _needsSave = true;
        enabled = e;
        emit enableStateChanged();
    }
    inline bool isEnabled() const {
        return enabled;
    }
signals:
    void enableStateChanged();
private:
    bool _needsSave;
    bool enabled;
};

#endif // WINDOWINFO_H
