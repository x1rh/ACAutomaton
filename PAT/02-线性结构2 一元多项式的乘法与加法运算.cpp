#include  <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node
{
	int x, y;
	node *next;
	node(){
		next = NULL;
	}
	node(int x, int y){
		this->x = x;
		this->y = y;
		next = NULL;
	}
};

struct List
{
	node *head, *rear;
	List(){
		head = NULL;
		rear = NULL;
	}
	void Insert(int x, int y){
		if(head==NULL)
			head = rear = new node();
		rear->next = new node(x, y);
		rear = rear->next;
	}
	void destroy(){
	    if(head==NULL) return;
        node *tmp = head->next, *d;
        while(tmp){
            d = tmp;
            tmp = tmp->next;
            delete d;
        }
        delete head;
        head = NULL;
	}
};

bool Find(List *L, int x, int y){
    if(L->head==NULL){
        return false;
    }
	node *cur = L->head->next;
	while(cur){
		if(cur->y==y){
			cur->x += x;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

void print(node *head){
    if(head==NULL) return;
    int flag = 0;
    node *tmp = head->next;
    while(tmp){
        if(tmp->x!=0){
            if(flag) printf(" ");
            printf("%d %d", tmp->x, tmp->y);
            flag++;
        }
        tmp = tmp->next;
    }
    printf("\n");
}

void add(List *L1, List *L2){
    if(L1->head==NULL){
        print(L2->head);
        return;
    }
    if(L2->head==NULL){
        print(L1->head);
        return;
    }
	List *L = new List;
	node *p = L1->head->next, *q = L2->head->next;
	while(p && q){
		if(p->y > q->y){
			if(!Find(L, p->x, p->y)){
				L->Insert(p->x, p->y);
			}
			p = p->next;
		}
		else if(p->y < q->y){
			if(!Find(L, q->x, q->y)){
				L->Insert(q->x, q->y);
			}
			q = q->next;
		}
		else{
			if(!Find(L, p->x+q->x, p->y)){
				L->Insert(p->x+q->x, p->y);
			}
			p = p->next;
			q = q->next;
		}
	}
	if(p){
		while(p){
			if(!Find(L, p->x, p->y)){
				L->Insert(p->x, p->y);
			}
			p = p->next;
		}
	}
	if(q){
		while(q){
			if(!Find(L, q->x, q->y)){
				L->Insert(q->x, q->y);
			}
			q = q->next;
		}
	}
	bool flag = true;
	node *tmp = L->head->next;
	while(tmp){
		if(tmp->x!=0){
			flag = false;
			break;
		}
		tmp=tmp->next;
	}
	if(flag)
		printf("0 0\n");
	else
		print(L->head);
	L->destroy();
}

void mult(List *L1, List *L2){
    if(L1->head==NULL){
        printf("0 0\n");
        return;
    }
    if(L2->head==NULL){
        printf("0 0\n");
        return ;
    }
	List *L = new List;
	node *p = L1->head->next;
	while(p!=NULL){
		node *q = L2->head->next;
		while(q!=NULL){
			int curx = p->x*q->x;
			int cury = p->y+q->y;
			if(!Find(L, curx, cury)){
				L->Insert(curx, cury);
			}
			q = q->next;
		}
		p = p->next;
	}
	p = L->head->next;
	while(p){
        node *q = p->next;
        while(q){
            if(p->y < q->y){
                int x = q->x;
                q->x = p->x;
                p->x = x;
                int y = q->y;
                q->y = p->y;
                p->y = y;
            }
            q = q->next;
        }
        p = p->next;
	}

	bool flag = false;
	p = L->head->next;
	while(p){
		if(p->x!=0)
		{
			flag = true;
			break;
		}
		p = p->next;
	}
	if(!flag)
		printf("0 0\n");
	else
        print(L->head);
	L->destroy();
	return;
}

int main(){
	int t1, t2, x, y;
	List *L1 = new List;
	List *L2 = new List;
	//while(~scanf("%d", &t1)){
	scanf("%d", &t1);
	for(int i=0; i<t1; i++){
		scanf("%d%d", &x, &y);
		L1->Insert(x, y);
	}
    scanf("%d", &t2);
	for(int i=0; i<t2; i++){
		scanf("%d%d", &x, &y);
		L2->Insert(x, y);
	}

	mult(L1, L2);
	add(L1, L2);

	L1->destroy();
	L2->destroy();
	//}
	return 0;
}
