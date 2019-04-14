# Primordial Machine's One Zero Functors Library
C++ 17 library providing functors returning of the zero value and the one value.
Implementations are provided for most built-in types.
Furthermore, consumers of this library can easily add specializations of these functors for built-in and user-defined types.

The library is made available publicly on [GitHub](https://github.com/primordialmachine/one-zero-functors) under the [MIT License](https://github.com/primordialmachine/one-zero-functors/blob/master/LICENSE).

## Usage example
To obtain the zero and the one value of the builtin type `float`:
```
using primordialmachine;
zero<float>();
one<float>();
```
To obtain the zero value and the one value of the builtin type `uint64_t`:
```
using primordialmachine;
zero<uint64_t>();
one<uint64_t>();
```

Consumers can implement these functors for their own types by adding (partial) specializations of `zero_expr` and `one_expr`. The following example implements the zero functor for a user-defined type `template<typename U> V` (we assume for this example that the default constructor `V<U>()` is the zero value of `V<U>()`).
```
namespace primordialmachine {
template<typename U>
struct zero_expr<V<U>, void>
{
  using result_type = V<U>;
  operator result_type() const noexcept(noexcept(result_type()))
  { return result_type(); };
}; // struct zero_expr
} // namespace primordialmachine
```
If `V<U>()` is constexpr, one may add the `constexpr` keyword.
```
namespace primordialmachine {
template<typename U>
struct zero_expr<V<U>, void>
{
  using result_type = V<U>;
  constexpr result_type() const noexcept(noexcept(result_type()))
  { return result_type(); };
}; // struct zero_expr
} // namespace primordialmachine
```

Furthermore, `zero_expr` and `one_expr` support SFINAE. The following example implements the same functor only if some side condition `C` evaluates to `true`.
```
namespace primordialmachine {
template<typename U>
struct zero_expr<V<U>, std::enable_if_t<C()>>
{
  using result_type = V<U>;
  constexpr auto operator()() const noexcept(noexcept(result_type()))
  { return result_type(); };
}; // struct zero_expr
} // namespace primordialmachine
```

## Restrictions
*The library officially only supports Visual Studio 2017 and Windows 10.*

## Releases
Relases of this library are made available via [GitHub releases](https://github.com/primordialmachine/one-zero-functors/releases/). A Github Release contains the *source code*, *prebuilt documentation*, and *prebuilt binaries for Visual Studio 2017*. The latest release is [version 1.6](https://github.com/primordialmachine/one-zero-functors/releases/latest).
