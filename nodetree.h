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


#ifndef NODETREE_H
#define NODETREE_H
#include "Constants.h"

class NodeTree
{
public:
    NodeTree(unsigned short type , NodeTree *root,NodeTree *left, NodeTree *right);
    NodeTree(char c,unsigned int weight);
    NodeTree();
    void setLeft(NodeTree *left);
    void setRight(NodeTree *right);
    void setParent(NodeTree *parent);
    void setType(unsigned short type);
    inline unsigned int  getweight(){return weight;}
    inline char getCharacter(){return character;}
    inline NodeTree* getParent(){return parent;}
    void setWeight(unsigned int weight);
    bool isRoot();
    bool isLeftChild();
    bool isRightChild();
private:
    NodeTree *left;
    NodeTree *right;
    NodeTree *parent;
    unsigned short type;
    unsigned int weight;
    char character;
};

#endif // NODETREE_H
