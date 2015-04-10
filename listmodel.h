#ifndef LISTVIEW_H
#define LISTVIEW_H
#include <QObject>
#include <QAbstractItemModel>
#include <QList>
#include "roster.h"

class ListModel : public QAbstractItemModel
{
    Q_OBJECT
private:
    QList <Roster*> list;

public:
    explicit ListModel(QObject *parent = 0);
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent (const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data (const QModelIndex &index, int role) const;
signals:

public slots:
    void listAdd(Roster*);
    void listRemove(QModelIndex);

};

#endif // LISTVIEW_H
