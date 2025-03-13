#include "header.h"

void insertFirst(address *First, int value){
	address P = (address) malloc(sizeof(ElmtList));
    info(P) = value;
    next(P) = *First;
    *First = P;
}

void insertLast(address First, int value){
	address P = (address) malloc(sizeof(ElmtList));
	info(P) = value;
    next(P) = Nil;
    
    if(First == Nil){
    	First = P;
	}else{
		while(next(First) != Nil){
			First = next(First);
		}
		next(First) = P;
	}
}

void deleteFirst(address *First){
	address temp = next(*First);
	free(*First);
	*First = temp;
}

void deleteLast(address *First){
	address temp = *First;
	if(next(*First) == Nil){
		free(*First);
		*First = Nil;
	}else{
		while (next(next(temp)) != Nil) {
            temp = next(temp);
        }

        free(next(temp));
        next(temp) = Nil;
	}
}

void insertAfter(address *First, int value){
	int jumlahNode = 0;
	int i = 1;
	address P = (address) malloc(sizeof(ElmtList)), temp;
	info(P) = value;
    next(P) = Nil;
    
    if(*First == Nil){
    	*First = P;
	}else{
		temp = *First;
		while (temp != Nil) {
            temp = next(temp);
            jumlahNode++;
        }
        
        temp = *First;
        while(i < jumlahNode/2){
        	temp = next(temp);
        	i++;
		}
		next(P) = next(temp);
        next(temp) = P;
	}
}

void deleteByValue(address *First, int value)
{
	address temp,temp2,temp3;
	if(info(*First) == value){
		temp = next(*First);
		free(*First);
		*First = temp;
	}else{
		temp = *First;
		while(temp != Nil){
			if(info(temp) == value){
				break;
			}
			temp = next(temp);
		}
		temp2 = next(temp);
		temp3 = *First;
		while(next(temp3) != temp){
			temp3 = next(temp3);
		}
		free(temp);
		next(temp3) = temp2;
	}
}		

void printSemuaNode(address First){
    if (First == Nil) {
        printf("{}\n");
        return;
    }

    printf("{");
    address temp = First;
    printf("%d", info(temp));
    temp = next(temp);
    while (temp != Nil) {
        printf(", %d", info(temp));
        temp = next(temp);
    }
    printf("}\n");
}

