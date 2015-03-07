# include<cstdio>

struct node{
    int x;
    int prof;
    node* esq;
    node* dir;
    node(int x): x(x), prof(0), esq(NULL), dir(NULL){}
};

void insert(int value, node* no){
    if(value > no->x) {
        if(no->dir == NULL){
            no->dir = new node(value);
        }else
            insert(value, no->dir);
    } else {
        if(no->esq == NULL){
            no->esq = new node(value);;
        }else
            insert(value, no->esq);
    }
}

void prefixa(node* no){
    if(no == NULL)return;
    printf("%d\n", no->x);
    prefixa(no->esq);
    prefixa(no->dir);
}

void infixa(node* no){
    if(no == NULL)return;
    infixa(no->esq);
    printf("%d\n", no->x);
    infixa(no->dir);
}

void posfixa(node* no){
    if(no == NULL)return;
    posfixa(no->esq);
    posfixa(no->dir);
    printf("%d\n", no->x);
}

int main(){
    int qtd_nodes, value, type;
    while(scanf("%d", &qtd_nodes) && qtd_nodes){
        scanf("%d", &value);
        node* raiz = new node(value);

        for (int i = 1; i < qtd_nodes; ++i){
            scanf("%d", &value);
            insert(value, raiz);
        }

        // 1 - prefixa, 2 - infixa, 3 - posfixa
        scanf("%d", &type);
        if(type == 1){
            prefixa(raiz);
        }else if(type == 2){
            infixa(raiz);
        }else {
            posfixa(raiz);
        }
    }
}