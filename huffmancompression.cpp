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


#include "huffmancompression.h"
#include <QDebug>

HuffmanCompression::HuffmanCompression()
{
}

void HuffmanCompression::compress(){
    FileIO f("");
    f.buildCharTable();
    //f.browseHashTable();
    list = new OrderedList;
    list->insertMap(f.getMap());
    copyExternalNodes();
    unify(list->getFirst(),list->getFirst());
    getCarEncode();
    browseHashTable();
}

void HuffmanCompression::unify(NodeTree *nodeL,NodeTree *nodeR){
    unsigned int weight = nodeL->getweight()+nodeR->getweight();
    NodeTree *tree = new NodeTree();
    nodeL->setType(Constants::LEFT);
    nodeR->setType(Constants::RIGHT);
    nodeR->setParent(tree);
    nodeL->setParent(tree);
    tree->setLeft(nodeL);
    tree->setRight(nodeR);
    tree->setType(Constants::ROOT);
    tree->setWeight(weight);
    list->insert(tree);
    if(list->size()==1)
        return;
    unify(list->getFirst(),list->getFirst());
}

void HuffmanCompression::copyExternalNodes(){
    externalNodesList = new QList<NodeTree*>;
    for(int i=0;i<list->size();i++)
        externalNodesList->append(list->get(i));
}

void HuffmanCompression::getCarEncode(){
    codeTable = new QMap<char,QString>;
    QListIterator<NodeTree*> it(*externalNodesList);
    while(it.hasNext()){
        NodeTree *n = it.next();
        QString str = goThroughBranch(n);
        codeTable->insert(n->getCharacter(),str);
    }
}

QString HuffmanCompression::goThroughBranch(NodeTree *node){
    QString code = "";
    while(!node->isRoot()){
        if(node->isLeftChild())
            code+="0";
        else if(node->isRightChild())
                code+="1";
        node = node->getParent();
    }
    return code;
}

void HuffmanCompression::browseHashTable(){
    QMapIterator<char, QString> i(*codeTable);
    while (i.hasNext()) {
        i.next();
        qDebug() << i.key() << ": " << i.value();
    }

}
