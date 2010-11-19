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

#include "orderedlist.h"
#include <QDebug>

OrderedList::OrderedList()
{
    tabNodes = new QList<NodeTree*>;
}

void OrderedList::insert(NodeTree *node){
    if(tabNodes->size()==0){
        tabNodes->insert(0,node);
        return;
    }
    for(int i=0;i<tabNodes->size();i++){
        if(node->getweight()<tabNodes->value(i)->getweight()){
            tabNodes->insert(i,node);
            return;
        }
    }
    tabNodes->append(node);
}

void OrderedList::insertMap(QMap<char,int> *map){
    QMapIterator<char,int> it(*map);
    while(it.hasNext()){
        it.next();
        NodeTree *n = new NodeTree(it.key(),it.value());
        insert(n);
    }

}

