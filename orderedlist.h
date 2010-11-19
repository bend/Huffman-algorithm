/*
*   Copyright © Benoit Daccache
*   ben.daccache@gmail.com
*
*   This file is part of VClient/VServer.
*
*   VClient/VServer is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   VClient/VServer is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with VClient/VServer.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H
#include <nodetree.h>
#include <QList>
#include <QMap>

class OrderedList
{
public:
    OrderedList();
    void insert(NodeTree *node);
    void insertMap(QMap<char,int> *map);
private:
    QList<NodeTree*> *tabNodes;
};

#endif // ORDEREDLIST_H
