#include <fstream>
using namespace std;
ifstream f("in.txt");
ofstream g("out.txt");

class list{
public:
struct node{int nr;
            node *next;};
node *first, *p, *last;
int n;

list();
void insert(int);
void insert(int, int);
void remove(int);
void removeall();
void sortlist();
void print();
};

list::list()
{
	first = NULL;
	n = 0;
}

void list::insert(int x)
{if(first==NULL){first = new node;
				 first->nr = x;
                 first->next = NULL;
                 last = first;
				 ++n;
                }
 else{p = new node;
      p->nr = x;
      p->next = NULL;
      last->next = p;
      last = p;
	  ++n;
    }
}

void list::insert(int x, int k)
{int i;
 node *q;
 p = first;
 if(k==1){q = new node;
          q->nr = x;
          q->next = p;
          first = q;
		  ++n;
         }
 else if(k==n){for(i=2; i<k; i++) p = p->next;
			   q = new node;
			   q->nr = x;
			   last->next = q;
			   last = q;
			   ++n;
			  }
	  else{for(i=2; i<k; i++) p = p->next;
		   q = new node;
		   q->nr = x;
		   q->next = p->next;
		   p->next = q;
		   ++n;
		  }
}

void list::remove(int k)
{int i;
 node *q;
 p = first;
 if(k==1){q = first;
          first = first->next;
          delete(q);
		  --n;
         }
 else if(k==n){for(i=2; i<k; i++) p = p->next;
               q = last;
               last = p;
               last->next = NULL;
               delete(q);
			   --n;
             }
     else{for(i=2; i<k; i++) p = p->next;
          q = p->next;
          p->next = p->next->next;
          delete(q);
		  --n;
        }
}

void list::removeall()
{node *z;
 p = first;
 while(p){z = p;
		  p = p->next;
		  delete(z);
		 }
 first = NULL;
 last = NULL;
 n = 0;
}


// remember to implement qsort instead of this mess

void list::sortlist()
{node *c;
 int ord, aux;
     do
     {c = first;
      ord = 1;
      while(c->next)
             {if(c->nr > c->next->nr)
				{aux = c->nr;
				 c->nr = c->next->nr;
				 c->next->nr = aux;
				 ord = 0;
				}
              c = c->next;}
      }
    while(ord==0);
}

void list::print()
{p = first;
 while(p){g<<p->nr<<" ";
          p = p->next;
         }
}
