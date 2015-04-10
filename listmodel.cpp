#include "listmodel.h"
#include <QList>
#include "roster.h"
ListModel::ListModel(QObject *parent) :
    QAbstractItemModel(parent)
{
}


QModelIndex ListModel::index(int row, int column, const QModelIndex &parent) const
{
    return this->createIndex(row,column);
}
QModelIndex ListModel::parent (const QModelIndex &child) const
{
    return QModelIndex();
}
int ListModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) {
        return list.count();
    }
    return 0;
}
int ListModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}
QVariant ListModel::data (const QModelIndex &index, int role) const
{

    if(index.isValid()) {
        if(Qt::DisplayRole == role){
            Roster *data;
            data = list.at(index.row());
            switch (index.column()) {
            case 0:
                return QString(data->getU());
            case 1:
                return QString(data->getN());
            case 2:
               return QString(data->getA());
            case 3:
                return QString("%1").arg(data->getT());
            }
        }
    }
    return QVariant();
}

void ListModel::listAdd(Roster *Data)
{
    int row = list.count();
    beginInsertRows(QModelIndex(),row,row);
    this->list.append(Data);
    endInsertRows();
}

void ListModel::listRemove(QModelIndex Index)
{
        int row = Index.row();
        beginRemoveRows(QModelIndex(),row,row);
        Roster *r = this->list.takeAt(row);
        delete(r);
        endRemoveRows();

}




