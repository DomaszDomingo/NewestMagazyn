#ifndef WAREHOUSEMANAGER_H
#define WAREHOUSEMANAGER_H

#include <QObject>
#include <QList>
#include "part.h"

class WarehouseManager : public QObject
{
    Q_OBJECT
public:
    explicit WarehouseManager(QObject *parent = nullptr);
    WarehouseManager(const QList<Part> &parts);

    void addPart (const Part &part);

    const QList<Part> &parts() const;

    int partCount() const;

signals:

    void modelChanged();

private:
    QList<Part> m_parts;
};

#endif // WAREHOUSEMANAGER_H
