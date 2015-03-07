#include<cstdio>

struct node{
    int x;
    node* esq;
    node* dir;
    node(int x): x(x), esq(NULL), dir(NULL){}
};

void insert(int x, node* no){    
    if(x < no->x){
        if(no->esq == NULL){
            node* novo = new node(x);
            no->esq = novo;
        }else
            insert(x, no->esq);
    }
    if(x > no->x){
        if(no->dir == NULL){
            node* novo = new node(x);
            no->dir = novo;
        }else
            insert(x, no->dir);
    }
}

void prefixa(node* raiz){
    if(raiz == NULL)return;
    printf("%d ", raiz->x);
    prefixa(raiz->esq);
    prefixa(raiz->dir);
}

void infixa(node* raiz){
    if(raiz == NULL)return;
    infixa(raiz->esq);
    printf("%d ", raiz->x);
    infixa(raiz->dir);
}

void posfixa(node* raiz){
    if(raiz == NULL)return;
    posfixa(raiz->esq);
    posfixa(raiz->dir);
    printf("%d ", raiz->x);
}

int main(){
    int qtd_nos, no;
    
    while(scanf("%d", &qtd_nos) && qtd_nos){
        scanf("%d", &no);
        node* raiz = new node(no);

        for (int i = 1; i < qtd_nos; ++i){
            scanf("%d", &no);
            insert(no, raiz);
        }

        // 1 - Prefixa, 2 - Infixa, 3 - Posfixa
        int entrada;
        scanf("%d", &entrada);
        if(entrada == 1)
            prefixa(raiz);
        else if(entrada == 2)
            infixa(raiz);
        else if(entrada == 3)
            posfixa(raiz);

    }
    return 0;
}