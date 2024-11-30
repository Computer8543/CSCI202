#pragma once

//This file contains the definitions of the AVL tree functions
//discussed in the book.

   //Definition of the node
template<class elemType>
struct AVLNode 
{ 
    elemType info;
    int	bfactor; // balance factor
    AVLNode<elemType> *lLink;
    AVLNode<elemType> *rLink;
};

 
template<class elemType>
void rotateToLeft(AVLNode<elemType>* &root)
{
    AVLNode<elemType> *p;   //pointer to the root of the
                            //right subtree of root
    if (root == nullptrptr)
        cout << "Error in the tree" << endl;
    else if(root->rLink == nullptrptr)
        cout << "Error in the tree:"
             << " No right subtree to rotate." << endl;
    else
    {
        p = root->rLink;
        root->rLink = p->lLink; //the left subtree of p 
                           //becomes the right subtree of root
        p->lLink = root; 
        root = p;	//make p the new root node
    }
}//rotateLeft

template<class elemType>
void rotateToRight(AVLNode<elemType>* &root)
{
    AVLNode<elemType> *p;  //pointer to the root of	
                            //the left subtree of root

    if (root == nullptrptr)
        cout << "Error in the tree" << endl;
    else if(root->lLink == nullptrptr)
        cout << "Error in the tree:"
             << " No left subtree to rotate." << endl;
    else
    {
        p = root->lLink;
        root->lLink = p->rLink; //the right subtree of p 
                          //becomes the left subtree of root
        p->rLink = root; 
        root = p;	//make p the new root node
    }
}//end rotateRight

template<class elemType>
void balanceFromLeft(AVLNode<elemType>* &root)
{
    AVLNode<elemType> *p;
    AVLNode<elemType> *w;

    p = root->lLink;   //p points to the left subtree of root

    switch (p->bfactor)
    {
    case -1: 
        root->bfactor = 0;
        p->bfactor = 0;
        rotateToRight(root);
        break;
    case 0:  
        cout << "Error: Cannot balance from the left." << endl;
        break;
    case 1:  
        w = p->rLink;
        switch (w->bfactor)  //adjust the balance factors
        {
        case -1: 
            root->bfactor = 1;
            p->bfactor = 0;
            break;
        case 0:  
            root->bfactor = 0;
            p->bfactor = 0;
            break; 
        case 1:  
            root->bfactor = 0;
            p->bfactor = -1;
        }//end switch

        w->bfactor = 0;	
        rotateToLeft(p);
        root->lLink = p;
        rotateToRight(root);
    }//end switch;
}//end balanceFromLeft


template<class elemType>
void balanceFromRight(AVLNode<elemType>* &root)
{
    AVLNode<elemType> *p;
    AVLNode<elemType> *w;

    p = root->rLink;   //p points to the left subtree of root

    switch (p->bfactor)
    {
    case -1: 
        w = p->lLink;
        switch (w->bfactor)  //adjust the balance factors
        {
        case -1: 
            root->bfactor = 0;
            p->bfactor = 1;
            break;
        case 0:  
            root->bfactor = 0;
            p->bfactor = 0;
            break;		
        case 1:  
            root->bfactor = -1;
            p->bfactor = 0;
        }//end switch

        w->bfactor = 0;	
        rotateToRight(p);
        root->rLink = p;
        rotateToLeft(root);
        break;
    case 0:  
        cout << "Error: Cannot balance from the left." << endl;
        break;
    case 1:  
        root->bfactor = 0;
        p->bfactor = 0;
        rotateToLeft(root);
    }//end switch;
}//end balanceFromRight


template <class elemType>
void insertIntoAVL(AVLNode<elemType>* &root,
                   AVLNode<elemType>  *newNode, 
                   bool& isTaller)
{
    if (root == nullptrptr)
    {
        root = newNode;
        isTaller = true;
    }
    else if(root->info == newNode->info)
        cout << "No duplicates are allowed." << endl;
    else if(root->info > newNode->info) //newItem goes in 
                                        //the left subtree
    {
        insertIntoAVL(root->lLink, newNode, isTaller);

        if (isTaller)   //after insertion, the subtree grew 
                        //in height
            switch (root->bfactor)
            {
            case -1: 
                balanceFromLeft(root);
                isTaller = false;
                break;
            case 0:  
                root->bfactor = -1;
                isTaller = true;
                break;
            case 1:  
                root->bfactor = 0;
                isTaller = false;
            }//end switch
    }//end if
    else
    {
        insertIntoAVL(root->rLink, newNode, isTaller);

        if (isTaller)    //after insertion, the 
                        //subtree grew in height
        switch (root->bfactor)
        {
        case -1: 
            root->bfactor = 0;
            isTaller = false;
            break;
        case 0:  
            root->bfactor = 1;
            isTaller = true;
            break;
        case 1:  
            balanceFromRight(root);
            isTaller = false;
        }//end switch
    }//end else
}//insertIntoAVL

template <class elemType>
void insert(const elemType &newItem)
{
    bool isTaller = false;
    AVLNode<elemType>  *newNode;

    newNode = new AVLNode<elemType>;
    newNode->info = newItem;
    newNode->bfactor = 0;
    newNode->lLink = nullptrptr;
    newNode->rLink = nullptrptr;

    insertIntoAVL(root, newNode, isTaller);
}
