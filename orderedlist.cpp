/*
*   Copyright © Benoit Daccache
*   ben.daccache@gmail.com
*
*   This file is part of Huffman.
*
*   Huffman is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   Huffman is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with Huffman.  If not, see <http://www.gnu.org/licenses/>.
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

NodeTree* OrderedList::get(unsigned int i){
    return tabNodes->at(i);
}

NodeTree* OrderedList::getFirst(){
    NodeTree *t = tabNodes->first();
    tabNodes->removeFirst();
    return t;
}

NodeTree* OrderedList::getLast(){
    NodeTree *t = tabNodes->last();
    tabNodes->removeLast();
    return t;
}

unsigned int OrderedList::size(){
    return tabNodes->size();
}

QString OrderedList::toString(){
    QString r = "";
    for(int i =0;i<tabNodes->size();i++){
        r= r +tabNodes->at(i)->getCharacter()+" "+QString::number(tabNodes->at(i)->getweight())+"\n";
    }
    return r;
}
