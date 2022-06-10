typedef struct Product{
    char name[50];
    char info[50];
    char weight[20];
    int price;
    int shipping;
} product;

int selectProduct();                                // 원하는 기능을 고르게 하는 함수
int selectDataNo (product *s, int count);           // 특정 제품의 데이터 위치를 알아내기 위한 함수

int createProduct(product *s);                      // 제품 생성 함수
void readProduct(product s);                        // 삭제된 제품을 제외한 다른 제품들 출력
void listProduct(product *s, int count);            // 현재있는 제품 알려주는 함수(삭제된 값은 스킵함)
int deleteProduct(product *s);                      // 특정 제품 삭제 함수


int updateProduct(product* s);                      // 특정 제품 수정 함수

void saveData(product *s, int count);               // 제품 데이터 값 파일 저장 함수
int loadData(product *s, int count);                           // 제품 데이터 걊 파일 불러오기 함수


void searchProductName(product *s, int count);      // 제품 검색 기능 함수 (제품 이름)
void searchProductShipping(product *s, int count);  // 제품 검색 기능 함수 (제품 배송 방법)
void searchProductPrice(product *s, int count);     // 제품 검색 기능 함수 (제품 가격)