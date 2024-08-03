#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<vector>
#include<algorithm>
void bubble_sort(int* arr, int l, int r);
void mormal_heap(int* arr, int n);
void linear_heap(int* arr, int n);
void unguarded_insert_sort(int* arr, int l, int r);
void insert_sort(int* arr, int l, int r);
void merge_sort(int* arr, int l, int r);
void quick_sort_v4(int* arr, int l, int r);
void radix_sort(int* arr, int l, int r);
void selection_sort(int* arr, int l, int r);
void shell_sort(int* arr, int l, int r);