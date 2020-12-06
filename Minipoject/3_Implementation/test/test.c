#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include<Header.h>
#define PROJECT_NAME    "Playfaircipher"

void test_decplainedit(void);
void test_plainedit(void);
void test_matrixx(void);
void test_makedistinct(void);
void test_decrypt(void);
void test_playfair(void);

int main() {

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
  
  CU_add_test(suite, "decplainedit", test_dcplainedit);
  CU_add_test(suite, "plainedit", test_plainedit);
  CU_add_test(suite, "matrixx", test_matrixx);
  CU_add_test(suite, "makeditinct", test_mkedistinct);
  CU_add_test(suite, "decrypt", test_decrypt);
    CU_add_test(suite, "playfair", test_plyfair);
 

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}
void test_decplainedit(void){
 
 }

void test_plainedit(void){
  
}

void test_matrixx(void){
  
}

void test_makedistinct(void){
  
}

void test_decrypt(void){
  
}

void test_playfair(void){
  
}

