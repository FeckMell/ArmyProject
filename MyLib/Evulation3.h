#pragma once
#include "stdafx.h"

/*
struct Test_
{
void Op_() {}
};
struct Test_A
{
void Op_EQ() {}
};
struct Test_B
{
void Op_NEQ() {}
};
struct Test_C
{
void Op_Less() {}
};

template<class T> struct Test
{
typedef void(T::*P)(void);

typedef char None;
template<class U, P = &U::Op_EQ> struct EQ { char dummy[2]; };
template<class U, P = &U::Op_NEQ> struct NEQ { char dummy[3]; };
template<class U, P = &U::Op_Less> struct LESS { char dummy[4]; };
//other operations

static None detect(...);
template<class U> static EQ<U> detect(U*);
template<class U> static NEQ<U> detect(U*);
template<class U> static LESS<U> detect(U*);

static const int thatOperation = sizeof(detect(static_cast<T*>(0)));
};



template<class T, int b = Test<T>::thatOperation> struct Test_Foo;

template<class T> struct Test_Foo<T, 1>
{
static void foo(const T &t) { cout << "Not Set"; }
};
template<class T> struct Test_Foo<T, 2>
{
static void foo(const T &t) { cout << "Equal"; }
};
template<class T> struct Test_Foo<T, 3>
{
static void foo(const T &t) { cout << "Not equal"; }
};
template<class T> struct Test_Foo<T, 4>
{
static void foo(const T &t) { cout << "Less"; }
};


int main()
{
int exit;
Test_ t;
Test_A a;
Test_B b;
Test_C c;
cout << "\nNone_ - "; Test_Foo<Test_>::foo(t);
cout << "\nA - "; Test_Foo<Test_A>::foo(a);
cout << "\nB - "; Test_Foo<Test_B>::foo(b);
cout << "\nC - "; Test_Foo<Test_C>::foo(c);

cin >> exit;
return 0;
}
*/