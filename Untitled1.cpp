#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>

typedef char typeinfo;
typedef struct node tree;
struct node {
    int info;
    tree *kanan;//cabang kiri
    tree *kiri;//cabang kanan
};

tree *p,*q,*baru, *root,*baca;
int x,n=0;

float total=0.0f,jum=0.0f;
float rata=0.0f;


void alokasi(){
    printf("masukan DATA: ");
//    fflush(stdin);
    char temp[10];
    std::cin.getline(temp, 10);

    char *strend;
    x = strtol(temp, &strend, 10);

    baru=(tree *)malloc(sizeof(tree));
    if(baru==NULL){
        puts("Alokasi memori gagal");
    }
    else{
        baru->info=x;
        baru->kanan=NULL;
        baru->kiri=NULL;
    }
}

void bentuk(){
    alokasi();
    n++;//banyak data

    if(root==NULL){
        root=baru;
    }
    else{
        p=root;
        q=root;
        while((q!=NULL)&&(baru->info!=p->info)){
            p=q;
            if(baru->info){
                q=p->kiri;
            }
            else{
                q=p->kanan;
            }
        }
        if(baru->info==p->info){
            puts("data duplikasi");
        }
        else{
            if(baru->info){
                p->kiri=baru;
            }
            else{
                p->kanan=baru;
            }
        }
    }
}

void preorder(tree *root){

    if(root!=NULL){
        jum=root->info;
        printf("%d ",root->info);
        total=total+jum;
        preorder(root->kiri);
        preorder(root->kanan);
    }
    //return;
}

void inorder(tree *root){
    if(root!=NULL){
        inorder(root->kiri);
        printf("%d ",root->info);
        inorder(root->kanan);
    }
    //return;
}
void postorder(tree *root){
    if(root!=NULL){
        postorder(root->kiri);
        postorder(root->kanan);
        printf("%d ",root->info);
    }
    //return;
}
int main(){

    char jawab;
    do{
        bentuk();
        printf("ada data lagi: ");
        fflush(stdin);
        char temp[10];
        std::cin.getline(temp, 10);
        jawab = temp[0];
//        jawab=getchar();
    }while(jawab=='y'||jawab=='Y');
    printf("hasil pre order : ");
    preorder(root);
    printf("\nhasil in order : ");
    inorder(root);
    printf("\n hasil post order : ");
    postorder(root);
    printf("\ntotal data=%f",total);
    printf("\nbanyak data=%d ",n);
    printf("\n\nrata-rata= %g\n",rata=total/n);
}
