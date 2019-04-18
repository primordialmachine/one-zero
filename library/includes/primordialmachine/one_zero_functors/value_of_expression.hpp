#pragma once

// Used to obtain the value of an expression at
// execution time. The following line obtains
// the floating-point value at execution time
// of an expression E.
// float x = value_of_expression<float, E>()();

namespace primordialmachine {

template<typename VALUE_TYPE, typename EXPRESSION_TYPE, typename ENABLED = void>
struct value_of_expression;
  
} // namespace primordialmachine
