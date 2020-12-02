#ifndef MODELISTTABLEMODEL_H
#define MODELISTTABLEMODEL_H
#include <QAbstractTableModel>
#include <QStyledItemDelegate>
#include "kb.h"
#include <QMimeData>

class ModeListTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    ModeListTableModel(Kb* dev, QObject* parent = nullptr);
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    static const enum {
        COL_MODE_ICON,
        COL_MODE_NAME,
        COL_EVENT_ICON,
        COL_MODE_MAX,
    } ModeListColumns;
    Qt::ItemFlags flags(const QModelIndex& index) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role);
    void setHighlightedRow(int row);
    inline KbMode* modeForIndex(const QModelIndex& index) const {
        return device->currentProfile()->at(index.column());
    }
    int addNewMode();
    bool dropMimeData(const QMimeData* data, Qt::DropAction action, int dstrow, int column, const QModelIndex& parent);
    Qt::DropActions supportedDropActions() const;
private slots:
    void profileAboutToChange();
    void profileChanged();
private:
    Kb* device;
    QIcon modeIcon(const int i) const;
    static QIcon eventIcon(KbMode* mode);
    int highlightedRow;
};

#endif // MODELISTTABLEMODEL_H
