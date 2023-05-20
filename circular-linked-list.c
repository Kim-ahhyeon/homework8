#include<stdio.h>
#include <stdlib.h>


typedef struct Node{     //구조체 Node 선언
    int key;             //노드의 데이터를 저장할 정수형 변수 key 선언
    struct Node * llink; //구조체 Node * link 선언, 왼쪽 링크
    struct Node * rlink; //구조체 Node *rlink 선언, 오른쪽 링크
}listNode; //구조체 이름은 listNode

int initialize(listNode** h);  //int형을 반환하는 함수 initialize(listNode** h) 정의
int freeList(listNode* h);     //  freeList(listNode* h) 정의
int insertLast(listNode* h, int key);  //  insertLast(listNode* h, int key) 정의
int deleteLast(listNode* h);           //deleteLast(listNode* h) 정의
int insertFirst(listNode* h, int key); //insertFirst(listNode* h, int key) 정의
int deleteFirst(listNode* h);          //deleteFirst(listNode* h) 정의
int invertList(listNode* h);           //invertList(listNode* h) 정의

int insertNode(listNode* h, int key);  //insertNode(listNode* h, int key) 정의
int deleteNode(listNode* h, int key);  //deleteNode(listNode* h, int key) 정의

void printList(listNode* h);           //printList(listNode* h) 정의

int main(){

char command;  //char형 변수 command
	int key;   //정수형 변수 key
	listNode* headnode=NULL; //구조체 listNode의 headnode는 NULL로 초기화

	printf("[----- [Kim ah hyeon] [2022041010] -----]\n");
	
	do{
		printf("----------------------------------------------------------------\n"); //---------------------------------------------------------------- 출력
		printf("                  Doubly Circular Linked List                   \n"); //                  Doubly Circular Linked List                    출력
		printf("----------------------------------------------------------------\n"); //---------------------------------------------------------------- 출력
		printf(" Initialize    = z           Print         = p \n");                  // Initialize    = z           Print         = p  출력
		printf(" Insert Node   = i           Delete Node   = d \n");                  // Insert Node   = i           Delete Node   = d 출력
		printf(" Insert Last   = n           Delete Last   = e\n");                   // Insert Last   = n           Delete Last   = e 출력
		printf(" Insert First  = f           Delete First  = t\n");                   // Insert First  = f           Delete First  = t 출력
        printf(" Invert List   = r           Quit          = q\n");                   // Invert List   = r           Quit          = q 출력

		printf("----------------------------------------------------------------\n"); //---------------------------------------------------------------- 출력

		printf("Command = ");  //Command = 출력
		scanf(" %c", &command); //command를 scanf로 입력받음

		switch(command) { ///제어식이 command
		case 'z': case 'Z': //command가 'z'거나 'Z'일 경우
			initialize(&headnode); //initialize(&headnode) 함수 호출
			break;                 //break문
		case 'p': case 'P': //command가 'p'거나 'P'일 경우
			printList(headnode); //printList(headnode) 함수  호출
			break;                 //break문
		case 'i': case 'I': //command가 'i'거나 'I'일 경우
			printf("Your Key = "); //Your Key =  출력
			scanf("%d", &key); //key 값을 scanf로 입력받음
			insertNode(headnode, key); //insertNode(headnode, key) 함수 호출
			break;                 //break문
		case 'd': case 'D': //command가 'd'거나 'D'일 경우
			printf("Your Key = "); //Your Key =  출력
			scanf("%d", &key); //key 값을 scanf로 입력받음
			deleteNode(headnode, key); //deleteNode(headnode, key) 함수 호출
			break;                 //break문
		case 'n': case 'N': //command가 'n'거나 'N'일 경우
			printf("Your Key = "); //Your Key =  출력
			scanf("%d", &key); //key 값을 scanf로 입력받음
			insertLast(headnode, key); //insertLast(headnode, key) 함수 호출
			break;                 //break문
		case 'e': case 'E': //command가 'e'거나 'E'일 경우
			deleteLast(headnode); //deleteLast(headnode) 함수 호출
			break;                 //break문
		case 'f': case 'F': //command가 'f'거나 'F'일 경우
			printf("Your Key = "); //Your Key =  출력
			scanf("%d", &key); //key 값을 scanf로 입력받음
			insertFirst(headnode, key); //insertFirst(headnode, key) 함수 호출
			break;                 //break문
		case 't': case 'T': //command가 't'거나 'T'일 경우
			deleteFirst(headnode); //deleteFirst(headnode) 함수 호출
			break;                 //break문
		case 'r': case 'R': //command가 'r'거나 'R'일 경우
			invertList(headnode); //invertList(headnode) 함수 호출
			break;                 //break문
		case 'q': case 'Q': //command가 'q'거나 'Q'일 경우
			freeList(headnode); //freeList(headnode) 함수 호출
			break;                 //break문
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); //       >>>>>   Concentration!!   <<<<<      출력
			break;                 //break문
		}

	}while(command != 'q' && command != 'Q');  //command가 'q'가 아니거나 'Q'가 아니면 실행

	return 1;                                  //1 값 반환
}

int initialize(listNode **h){               //리스트를 초기화하는 함수
    
    if (*h == NULL) //*h가 NULL이면
        freeList(*h); //freeList(*h) 함수 호출

    *h = (listNode*)malloc(sizeof(listNode)); //*h를 동적할당
    (*h)->rlink = *h; //*h->rlink에 *h 대입
    (*h)->llink = *h; //*h->llink에 *h 대입
    (*h)->key = -9999; // //*h->key에 -9999 대입

    return 1; //1 값 반환

}

int freeList(listNode* h){
    
	if(h->rlink == h) //h->rlink가 h라면
	{
		free(h);      //h의 메모리 주소 해제
		return 1;     //1 값을 반환
	}

	listNode* p = h->rlink;   //listNode *p에 h->rlink 값 대입

	listNode* prev = NULL;    //listNode *prev를 NULL로 초기화
	while(p != NULL && p != h) {  //p가 NULL이 아니고 p가 h가 아니라면
		prev = p;                 //prev에 p 값 대입
		p = p->rlink;             //p에 p->rlink 값 대입
		free(prev);               //prev의 메모리 주소 해제
	}
	free(h);                      //h의 메모리 주소 해제

	return 0;                     //0 값을 반환
}

void printList(listNode* h) {
	int i = 0; //정수형 변수 i 선언, 0으로 초기화
	listNode* p; //listNode 포인터 변수 *p 선언

	printf("\n---PRINT\n"); //---PRINT 출력

	if(h == NULL) { //h가 NULL 이면
		printf("Nothing to print....\n"); //Nothing to print.... 출력
		return; //0으로 반환
	}

	p = h->rlink; //p에 h->rlink 대입

	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] ", i, p->key); //[ [%d]=%d ]  출력
		p = p->rlink;                      //p에 p->rlink 값 대입
		i++; //i에 증가 연산자
	}
	printf("  items = %d\n", i); //  items = %d 출력


	/* print addresses */
	printf("\n---checking addresses of links\n"); //---checking addresses of links 출력
	printf("-------------------------------\n"); //------------------------------- 출력
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink); //head node: [llink]=, [head]=, [rlink]= 출력

	i = 0; //i를 0으로 초기화
	p = h->rlink; //p에 h->rlink 값 대입
	while(p != NULL && p != h) { //p가 NULL이 아니고 p가 h가 아닐 경우
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink); //[ [%d]=%d ] [llink]=, [node]=, [rlink]= 출력
		p = p->rlink; //p에 p->rlink 값 대입
		i++; //i에 증가 연산자
	}

}

int insertLast(listNode* h, int key) {                   //
    
	if (h == NULL) return -1;                            //h가 NULL이면 -1 값 반환

	listNode* node = (listNode*)malloc(sizeof(listNode)); //listNode *node 동적할당
	node->key = key;                                    //node->key에 key 값 대입
	node->rlink = NULL;                                 //node->rlink를 NULL로 초기화
	node->llink = NULL;                                 //node->llink를 NULL로 초기화

	if (h->rlink == h)                                  //h->rlink가 h이면
	{
		h->rlink = node;                                //h->rlink에 node 값 대입
		h->llink = node;                                //h->llink에 node 값 대입
		node->rlink = h;                                //node->rlink에 h 값 대입
		node->llink = h;                                //node->llink에 h 값 대입
	} else {                                            //h->rlink가 h 값이 아니면
		h->llink->rlink = node;                         //h->llink->rlink에 node 값 대입
		node->llink = h->llink;                        //node->llink에 h->llink 값 대입
		h->llink = node;                               //h->llink에 node 값 대입
		node->rlink = h;                               //node->rlink에 h 값 대입
	}

	return 1;                                          //1 값 반환
}

int deleteLast(listNode* h) {
    
	if (h->llink == h || h == NULL)              //h->llink가 h이거나 h가 NULL이면
	{
		printf("nothing to delete.\n");          //nothing to delete. 출력
		return 1;                                // 1 값 반환
	}

	listNode* nodetoremove = h->llink;           //listNode *nodetoremove에 h->llink 값 대입

	
	nodetoremove->llink->rlink = h;              //nodetoremove->llink->rlink에 h 값 대입
	h->llink = nodetoremove->llink;              //h->llink에 nodetoremove->llink 값 대입

	free(nodetoremove);                          //nodetoremove의 메모리 주소 해제

	return 1;                                   //1 값 반환
}

int insertFirst(listNode* h, int key) {
    
	listNode* node = (listNode*)malloc(sizeof(listNode));  //linkNode *node 동적할당
	node->key = key;                                       //node->key에 key 값 대입
	node->rlink = NULL;                                    //node->rlink를 NULL로 초기화
	node->llink = NULL;                                    //node->llink를 NULL로 초기화


	node->rlink = h->rlink;                               //node->rlink에 h->rlink 값 대입
	h->rlink->llink = node;                               //h->rlink->llink에 node 값 대입
	node->llink = h;                                      //node->llink에 h 값 대입
	h->rlink = node;                                      //h->rlink에 node 값 대입
 
	return 1;                                             //1 값 반환
}

int deleteFirst(listNode* h) {
    
	if (h == NULL || h->rlink == h)                       //h가 NULL이거나 h->rlink가 h라면
	{
		printf("nothing to delete.\n");                   //nothing to delete.\n") 출력
		return 0;                                         //0 값 반환
	}

	listNode* nodetoremove = h->rlink;                   //listNode *nodetoremove에 h->rlink 값 대입

	
	nodetoremove->rlink->llink = h;                      //nodetoremove->rlink->llink에 h 값 대입
	h->rlink = nodetoremove->rlink;                      //h->rlink에 nodetoremove->rlink 값 대입

	free(nodetoremove);                                  //nodetoremove의 메모리 주소 해제

	return 1;                                            //1 값 반환

}

int invertList(listNode* h) {
    

	if(h->rlink == h || h == NULL) {                     //h->rlink가 h이거나 h가 NULL이라면
		printf("nothing to invert...\n");                //nothing to invert... 출력
		return 0;                                        //0 값 반환
	}
	listNode *n = h->rlink;                              //listNode *n에 h->rlink 값 대입
	listNode *trail = h;                                 //listNode *trail에 h 값 대입
	listNode *middle = h;                                //listNode *middle에 h 값 대입

	
	h->llink = h->rlink;                                 //h->llink에 h->rlink 값 대입

	while(n != NULL && n != h){                          //n이 NULL이 아니고 h가 아니면
		trail = middle;                                  //trail에 middle 값 대입
		middle = n;                                      //middle에 n 값 대입
		n = n->rlink;                                    //n에 n->rlink 값 대입
		middle->rlink = trail;                           //middle->rlink에 trail 값 대입
		middle->llink = n;                               //middle->llink에 n 값 대입
	}

	h->rlink = middle;                                   //h->rlink에 middle 값 대입



	return 0;                                            //0 값 반환
}

int insertNode(listNode* h, int key) {


	if(h == NULL) return -1;                                //h가 NULL이면 -1 값 반환

	listNode* node = (listNode*)malloc(sizeof(listNode));  //listNode *node 동적할당
	node->key = key;                                       //node->key에 key 값 대입
	node->llink = node->rlink = NULL;                      //node->llink에 node->rlink값 대입, NULL로 초기화

	if (h->rlink == h)                                     //h->rlink가 h라면
	{
		insertFirst(h, key);                               //insertFirst(h, key) 함수 호출
		return 1;                                          //1 값 반환
	}

	listNode* n = h->rlink;                                //listNode *n에 h->rlink값 대입

	
	while(n != NULL && n != h) {                           //n이 NULL이 아니고 h가 아니면
		if(n->key >= key) {                                //n->key가 key보다 같거나 크다면
			
			if(n == h->rlink) {                            //n이 h->rlink라면
				insertFirst(h, key);                       //insertFirt(h, key) 함수 호출
			} else {                                       //n이 h->rlink가 아니라면
				node->rlink = n;                           //node->rlink에 n 값 대입
				node->llink = n->llink;                    //node->llink에 n->llink 값 대입
                n->llink->rlink = node;                    //n->llink->rlink에 node 값 대입
				n->llink = node;                           //n->llink에 node 값 대입
			}
			return 0;                                      //0 값 반환
		}

		n = n->rlink;                                      //n에 n->rlink 값 대입
	}

	
	insertLast(h, key);                                    //insertLast(h, key) 함수 호출
	return 0;                                              //0 값 반환
}

int deleteNode(listNode* h, int key) {
    
	if (h->rlink == h || h == NULL)                        //h->rlink가 h이거나 h가 NULL이면
	{
		printf("nothing to delete.\n");                    //nothing to delete. 출력
		return 0;                                          //0 값 반환
	}

	listNode* n = h->rlink;                                //listNode *n에 h->rlink 값 대입

	while(n != NULL && n != h) {                           //n이 NULL이 아니고 h가 아니면
		if(n->key == key) {                                //n->key가 key이면
			if(n == h->rlink) {                            //n이 h->rlink이면
				deleteFirst(h);                            //deleteFirst(h) 함수 호출
			} else if (n->rlink == h){                     //n->rlink가 h이면
				deleteLast(h);                             //deleteLast(h) 함수 호출
			} else {                                       //두 가지 경우 모두 아니라면
				n->llink->rlink = n->rlink;                //n->llink->rlink에 n->rlink 값 대입
				n->rlink->llink = n->llink;                //n->rlink->llink에 n->llink 값 대입
				free(n);                                   //n의 메모리 주소 해제
			}
			return 0;                                      //0 값 반환
		}

		n = n->rlink;                                      //n에 n->rlink 값 대입
	}

	
	printf("cannot find the node for key = %d\n", key);   //cannot find the node for key =  출력

	return 0;                                             //0 값 반환
}
