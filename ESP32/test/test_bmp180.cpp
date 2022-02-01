#include <TemperatureBMP180.h>
#include <Arduino.h>
#include <unity.h>

TempBmp180 temp1 = TempBmp180("temp180_temperature","Temperature",{{21,"bmp180_sda"},{22,"bmp180_scl"}},60);

void test_setup_bmp180(void){
    bool res = temp1.setUp();
    TEST_ASSERT_EQUAL(true,res);
}
void test_range_bmp180(void){
    int res = (int) temp1.getSensorData();
    TEST_ASSERT_GREATER_OR_EQUAL(0,res);
    TEST_ASSERT_LESS_OR_EQUAL(50,res);

}
void test_variation_bmp180(void){
    float res = temp1.getSensorData();
    delay(1000);
    float res2 = temp1.getSensorData();
    float diff = res2 -res;
    TEST_ASSERT_FLOAT_WITHIN(0.001,0, diff);
}

void setup(){
    delay(2000);
    UNITY_BEGIN();

    RUN_TEST(test_setup_bmp180);
    RUN_TEST(test_range_bmp180);
    RUN_TEST(test_variation_bmp180);

    UNITY_END();
}
void loop(){
}