#ifndef MY_CONCEPTS_HPP
#define MY_CONCEPTS_HPP 1
/**
 * @file my_concepts.hpp
 * @brief 用于模板编写使用的自定义concept
 * @author northhalf
 */
#include <concepts>

/**
 * @namespace myconcept
 * @brief 存放自定义concept用于模板编写
 */
namespace myconcept {

/**
 * @brief 用于判断类型是否为算术类型的concept
 */
template <typename T>
concept Arithmetic = std::integral<T> || std::floating_point<T>;

}  // namespace myconcept
#endif