#pragma once

// Grind 75
// https://leetcode.com/problem-list/rab78cw1/

#include <concepts>
#include <iostream>
#include <map>
#include <ranges>
#include <vector>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <string>
#include <set>
#include <queue>
#include <chrono>
#include <deque>
#include <stack>

template<typename T>
void print(std::vector<T> const & v)
{
  for (auto& n : v)
  {
    std::cout << n << " ";
  }
  std::cout << std::endl;
}

template<typename T>
void print(std::vector<T> && v)
{
  for (auto& n : v)
  {
    std::cout << n << " ";
  }
  std::cout << std::endl;
}


void print2(const std::vector<std::vector<int>> & vv)
{
  for (auto &r : vv)
  {
    for (auto &c : r)
      std::cout << c << " ";
    std::cout << "\n";
  }
  std::cout << std::endl;
}

template<typename T>
requires std::ranges::range<T>
void print1(T const& v)
{
  for (auto& n : v)
  {
    std::cout << n << " ";
  }
  std::cout << std::endl;
}


template<typename F>
std::chrono::milliseconds duration(F&&f)
{
  auto start = std::chrono::high_resolution_clock::now();
  //std::invoke(std::forward<F>(f));
  f();
  auto end = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

template<typename F, typename... Args>
std::chrono::milliseconds duration(F&&f, Args... args)
{
  auto start = std::chrono::high_resolution_clock::now();
  std::invoke(std::forward<F>(f), std::forward<Args>(args));
  auto end = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}
/*
//void print(const auto std::ranges::range& v) { ... }
template<std::ranges::range T>
void print(T&& v)
{
  for (auto& n : v)
  {
    std::cout << n << " ";
  }
  std::cout << std::endl;
}
*/