//Alguns exemplos de uso de ponteiros, ->, etc
class Data {
public:
    Int x;
    Int * y;
    …..
    void f() {
	this->x = 10; //equivalente ao dptr->x = 10 (o “this” no objeto “d” aponta para o mesmo endereco que dptr na main abaixo aponta… ele é como se fosse um ponteiro que aponta para o proprio objeto).
 	*(this->y) = 1;  
	*y = 1; //equivalente ao código anterior… o this-> e’ desnecessario em geral, pois estamos dentro da propria classe
    }
};

Int main() {
	Data d;
	Data *dptr = &d;
	Data **dptr2 = &dptr;
	*(d.y) = 10; //y é um ponteiro para inteiro
	*(dptr->y) = 1; 
	(*dptr).x = 10;  //dptr e’ um ponteiro que aponta para o endereco de d… logo (*dptr) e’ o objeto “d”
	dptr->x = 10; //equivalente ao anterior
	(**dptr2).x = 1; //dptr2 e’ um ponteiro que aponta para dptr… Logo, *dptr2 e’ dptr e **dptr2 e’ o objeto d…
	(*dptr2)->x = 1; //equivalente ao anterior...
	
}
