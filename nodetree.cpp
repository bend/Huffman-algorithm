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


#include "nodetree.h"

NodeTree::NodeTree(char c,unsigned int weight){
    this->character = c;
    this->weight = weight;
}

NodeTree::NodeTree(){
    this->weight=0;
}

void NodeTree::setLeft(NodeTree *left){
    this->left = left;
}

void NodeTree::setRight(NodeTree *right){
    this->right = right;
}

void NodeTree::setParent(NodeTree *parent) {
    this->parent = parent;
}

void NodeTree::setType(unsigned short type){
    this->type = type;
}

void NodeTree::setWeight(unsigned int weight){
    this->weight = weight;
}

bool NodeTree::isRoot(){
    return type==Constants::ROOT ? true:false;
}

bool NodeTree::isLeftChild(){
    return type==Constants::LEFT ? true:false;
}

bool NodeTree::isRightChild(){
    return type==Constants::RIGHT ? true:false;
}
