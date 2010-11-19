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

#ifndef NODETREE_H
#define NODETREE_H

class NodeTree
{
public:
    NodeTree(unsigned short type , NodeTree *root,NodeTree *left, NodeTree *right);
    NodeTree(unsigned short type);
    inline void setLeft(NodeTree *left){this->left = left;}
    inline void setRight(NodeTree *right){this->right = right;}
    inline void setRoot(NodeTree *root) {this->root = root;}
    inline void setType(unsigned short type){this->type = type;}
private:
    NodeTree *left;
    NodeTree *right;
    NodeTree *root;
    unsigned short type;
};

#endif // NODETREE_H
