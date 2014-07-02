
/*

Binary tree implementation
@author; Dev B. Poudel
*/

#include<iostream>
#include<stdlib.h>
#include<time.h>


//templated node
template <class T> struct node
{

T key_value;
node<T> *left;
node<T> *right;
};


//Binary tree class
template <class T> class Btree
{
public:
   node<T> *root;
   Btree();
  ~Btree();
   
void insert(T key);
node<T> * search(T key);
//void destroy_tree();

void traverse(node<T> *leaf);
int finddepth(node<T> *leaf);

private:
//void destroy_tree(node *leaf);
void insert(T key, node<T> *leaf);
node<T>*search(T key, node<T> *leaf);


};


//constructor

template<class T> Btree<T>::Btree()
{
root=NULL;
}

//destructor
template<class T>
Btree<T>::~Btree()
{
delete root;
}


// traverse the node
template<class T>
void Btree<T>::traverse(node<T> *leaf)
{
if(leaf!=NULL)
  {
  traverse(leaf->left);
  std::cout<<leaf->key_value<<" ";
  traverse(leaf->right);
  }
}


//insert the value  to the node
template<class T>
void Btree<T>::insert(T key, node<T> *leaf)
{

if(key<leaf->key_value)
{  if(leaf->left!=NULL) 
	insert(key,leaf->left);
      else
        {
	 leaf->left=new node<T>;
	 leaf->left->key_value=key;
         leaf->left->right=NULL;
         leaf->left->left=NULL;
         }


}


else if(key>=leaf->key_value)
{
    if(leaf->right!=NULL) 
       insert(key,leaf->right);
       else
          { leaf->right=new node<T>;
            leaf->right->key_value=key;
            leaf->right->left=NULL;
            leaf->right->right=NULL;

           }

}



}


template<class T>
void Btree<T>::insert(T key)
{
if(root!=NULL)
   insert(key,root);
else
{
root=new node<T>;
root->key_value=key;
root->left=NULL;
root->right=NULL;

}

}


template<class T>
node<T> *Btree<T>::search(T key, node<T> *leaf)
{
if(leaf!=NULL)
      { if(key==leaf->key_value)
             return leaf;
         if(key<leaf->key_value)
             return search(key, leaf->left);
             else
             return search(key,leaf->right);
      
      }
 else 
    return NULL;

}



//search for a key value
template<class T>
node<T> *Btree<T>::search(T key)
{
return search(key,root);
}


template<class T> 
int Btree<T>::finddepth(node<T> *leaf)
{
if(leaf==NULL)
return(0);

int lh=finddepth(leaf->left);
int rh=finddepth(leaf->right);
if(lh>rh)
return lh+1;
else
return rh+1;
  
}



int main()
{
int num;
Btree<int> tree1;
srand(time(NULL));


for(int i=0;i<20;i++)
{
num=rand()%200;
tree1.insert(num);
}


tree1.traverse(tree1.root);

int height;
height=tree1.finddepth(tree1.root);
std::cout<<"height or depth of the tree="<<height<<std::endl;

node<int> *result;
result=tree1.search(6);
if(result!=NULL)
 std::cout<<"searched item found";
else
  std::cout<<"searched item not found";
return 0;
}

