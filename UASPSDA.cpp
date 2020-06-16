//Harnanda Rafika Anjani 1910512021 Kelas A
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *pohon = NULL;

//fungsi untuk insert/tambah data
void tambah (Node **root, int databaru)
{
    if ((*root)==NULL)
       {
        Node *baru;
        baru = new Node;
        baru->data=databaru;
        baru->left=NULL;
        baru->right=NULL;
        (*root) = baru;
        (*root) -> left = NULL;
        (*root) -> right = NULL;
        printf("Data Berhasi diinput!");
       }
    else if (databaru<(*root)->data)
              tambah(&(*root)->left,databaru);
    else if (databaru>(*root)->data)
        tambah(&(*root)->right,databaru);
    else if (databaru==(*root)->data)
        printf("Data Sudah ada!");
}

//fungsi preOrder
void preOrder(Node *root)
{
    if(root!=NULL)
    {
        if(root->data!=NULL)
        {
            printf("%d ",root->data);
        }
        preOrder(root->left);
        preOrder(root->right);
    }
}

//fungsi inOrder
void inOrder(Node *root)
{
       if(root!=NULL)
       {
           inOrder(root->left);
           if(root->data!=NULL)
           {
               printf("%d ",root->data);
           }
           inOrder(root->right);
        }
}

//fungsi postOrder
void postOrder(Node *root)
{
       if(root!=NULL)
       {
         postOrder(root->left);
         postOrder(root->right);
         if(root->data!=NULL)
         {
            printf("%d ",root->data);
         }
       }
}

//fungsi search
void search(Node **root, int cari)
{
    if((*root) == NULL)
    {
        printf("Data tidak ditemukan!");
    }
    else if(cari < (*root)->data)
        search(&(*root)->left,cari);
    else if(cari > (*root)->data)
        search(&(*root)->right,cari);
    else if(cari == (*root)->data)
        printf("Data berhasil ditemukan!");
}


int count(Node *root)
{
       if(root==NULL)
              return 0;
       else
              return count(root->left)+ count(root->right)+1;
}

//FUNGSI UNTUK MENCARI DATA TERBESAR
int terbesar(){
	Node* val = pohon;
	while(val->right!=NULL){
		val=val->right;
	}
	return val->data;
}

//FUNGSI UNTUK MENCARI DATA TERKECIL
int terkecil(){
	Node* val = pohon;
	while(val->left!=NULL){
		val=val->left;
	}
	return val->data;
}

//Fungsi untuk mengetahui ketinggian/kedalaman
int tinggi(Node *root)
{
       if(root == NULL)
              return -1;
       else{
              int u = tinggi(root->left);
        int v = tinggi(root->right);
        if(u > v)
          return u + 1;
        else
          return v + 1;
       }
}


//fungsi yang digunakan untuk menghapus suatu node
void hapus(Node **root, int hps)
{
       Node *val;
       Node *parent;
       val = (*root);

       bool flag = false;
  
       while(val != NULL)
       {
              if(val->data == hps)
              {
                     flag = true;
                      break;
              }
              else
              {
                  parent = val;
                  if(hps>val->data)
                     val = val->right;
                  else
                     val = val->left;
              }
       }

    if(!flag)
    {
        cout<<"Tidak ada data yang bisa dihapus!"<<endl;
        return;
    }

       if(tinggi(pohon) == 0)
       {
              if( val->left== NULL && val->right == NULL)
              {
                     (*root) = NULL;
                    
                     return;
              }
       }
       else if(tinggi(pohon) > 0)
       {
              if( val->left== NULL && val->right == NULL)
              {
                     if(parent->left == val)
                     {
                           parent->left = NULL;
                           delete val;
                     }
                     else 
                     {
                           parent->right = NULL;
                           delete val;
                     }

                     return;
              }

              if((val->left == NULL && val->right != NULL)|| (val->left != NULL && val->right == NULL))
              {
                     if(val->left == NULL && val->right != NULL)
                     {
                           if(parent->left == val)
                           {
                              parent->left = val->right;
                              delete val;
                         }
                         else 
                         {
                              parent->right = val->right; 
                              delete val;
                         }
                     }
                  else 
                  {
                           if(parent->left == val)
                           {
                                  parent->left = val->left; 
                                  delete val;
                           }
                           else 
                           {
                               parent->right = val->left; 
                               delete val;
                            }
                   }
                   return;
              }
              if (val->left != NULL && val->right != NULL)
              {
                     Node* bantu;
                     bantu = val->right;
                     if((bantu->left == NULL) && (bantu->right == NULL))
                     {
                           val = bantu;
                           delete bantu;
                           val->right = NULL;
                     }
                     else 
                     {
                           if((val->right)->left != NULL)
                           {
                                  Node* bantu2;
                                  Node* bantu3; 
                                  bantu3 = val->right;        
                                  bantu2 = (val->right)->left;
                                  while(bantu2->left != NULL)
                                  {
                                         bantu3 = bantu2;
                                         bantu2 = bantu2->left;
                                  }
                                
                                  val->data = bantu2->data;
                                  delete bantu2;
                                  bantu3->left = NULL;
                        }
                        else 
                        {
                              Node* tmp;
                              tmp = val->right;
                            
                              val->data = tmp->data;
                              val->right = tmp->right;
                              delete tmp;
                        }

                     }
                     return;
              }
       }
}


int main()
{

    char pil;
    int hps,cari;
    while (true)
    {
        system("cls"); 
        char data;
        printf("\tUAS PRAKTIKUM HARNANDA BST");
        printf("\nMENU\n");
        printf("1. Tambah Data\n");
        printf("2. Tampilkan PREORDER, INORDER, POSTORDER\n");
        printf("3. Search\n");
        printf("4. Cari data terbesar \n");
        printf("5. Cari data terkecil\n");
        printf("6. Hapus data\n");
        printf("7. Reset Data\n");
        printf("8. Keluar\n");
        printf("Pilihan Anda : ");
        scanf("%c",&pil);
        fflush(stdin); 
        switch(pil)
        {
            case '1':
                     printf("\nMasukkan data: ");
                     scanf("%d", &data);
                     tambah(&pohon,data);
                     _getch();
                      break;

             
              case '2':
                     printf("\nOUTPUT");
                     if(pohon!=NULL)
                     {
                          
                           printf("\nPRE ORDER  : ");
                           preOrder(pohon); 
                           printf("\nIN ORDER   : ");
                           inOrder(pohon); 
                           printf("\nPOST ORDER : ");
                           postOrder(pohon); 
                       
                     }
                     else
                           printf("\nData kosong!");

                     _getch();
                     break;

             
              case '3':
              	if(pohon!=NULL)
                     {
                      printf("\n\nPENCARIAN DATA");
                           
                           printf("\nMasukkan data yang ingin dicari : ");
                           scanf("%d", &cari);
                           search(&pohon, cari);
                       }
                       else
                       printf ("Data Kosong!");
                        _getch();
                     break;
                
              case '4':
              	cout<<"\nData Terbesar : " <<terbesar();
              		_getch();
              		break;
              		
              case '5':
              		cout<<"\nData Terkecil : "<<terkecil(); 
					_getch(); 
					break;   
                  
              
              case '6':
                     if(pohon!=NULL)
                     {
                           printf("\nSEBELUM DATA DIHAPUS : ");
                           printf("\nPRE ORDER  : ");
                           preOrder(pohon); 
                           printf("\nIN ORDER   : ");
                           inOrder(pohon); 
                           printf("\nPOST ORDER : ");
                           postOrder(pohon); 
                           printf("\nMasukkan data yang ingin dihapus: ");
                           scanf("%d", &hps);
                        
                          
                           hapus(&pohon, hps);
                           printf("\n\nSETELAH DATA DIHAPUS : ");
                           printf("\nPRE ORDER  : ");
                           preOrder(pohon);
                           printf("\nIN ORDER   : ");
                           inOrder(pohon); 
                           printf("\nPOST ORDER : ");
                           postOrder(pohon); 
                     }
                     else
                           printf("\nData kosong!");

                     _getch();
                     break;
                     

              case '7':
                     pohon=NULL;
                     printf("\nDATA KOSONG!!");
                      
                     _getch();
                     break;

              case '8':
              	printf("\nTERIMA KASIH...");
                exit(0);                     
                break;
              }
       }
}
