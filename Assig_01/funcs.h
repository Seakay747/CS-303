#pragma once

void add_val(int*& arr, int val, unsigned int index);

void expand_arr(int*& arr, int& size);

void print_menu();

void arr_find(int*& arr, int val, int size);

void arr_mod(int*& arr, unsigned int index, int val);

void del_val(int*& arr, int size, int cur_index, unsigned int del_index);
