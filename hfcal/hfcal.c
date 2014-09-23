#include <stdio.h>
#include <hfcal.h>
void display_calories(float weight, float distance, float coeff) {
  printf ("体重:%3.2fポンド\n", weight);
  printf ("距離:%3.2fマイル\n", distance);
  printf ("消費カロリー:%4.2fカロリー\n", coeff * weight * distance);
}
