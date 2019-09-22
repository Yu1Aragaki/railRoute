/**
 *    A program which can calculate a longest path of a rail system.
 *    Copyright (C) 2019  J. HUANG
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 */

#ifndef EXLABEL_H
#define EXLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class ExLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ExLabel(QWidget *parent = nullptr);

signals:
    void clicked(QMouseEvent *ev);

protected:
    void mouseReleaseEvent(QMouseEvent *ev);
    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);

public slots:
};

#endif // EXLABEL_H
