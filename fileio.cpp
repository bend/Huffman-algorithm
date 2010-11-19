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

#include "fileio.h"
#include <iostream>
#include <QDebug>
#include <QMapIterator>
using namespace std;
FileIO::FileIO(QString str)
{
    this->filename = str;
    map = new QMap<char,int>;
}

void FileIO::buildCharTable(){
    QString s = "anticonstitutionnellement";
    for(unsigned int i=0;i<s.length();i++){
        char c = s.at(i).toAscii();
        if(map->contains(c))
            map->insert(c,map->value(c)+1);
        else map->insert(c,1);
    }
}

void FileIO::browseHashTable(){
    QMapIterator<char, int> i(*map);
    while (i.hasNext()) {
        i.next();
        qDebug() << i.key() << ": " << i.value();
    }

}
