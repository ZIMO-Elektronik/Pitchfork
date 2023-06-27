# Style guide
- Use clang-format.

- Use PascalCase for types.

- Use camelCase for methods.

- Use snake_case for functions.

- Use snake_case for variables.

- Do not declare more than one variable per declaration.
  ```cpp
  // src is a pointer but c isn't
  char* src{}, c{};

  // Splitting the declarations makes this evident
  char* src;
  char c;
  ```

- Use explicit for constructors with single argument. This prevents unwanted implicit conversions.
  ```cpp
  struct S {
    explicit S(int i) {}
  };
  ```

- Do not use unsigned types for math. Things get specially nasty when mixing types of different size. The following two lines are a perfect example for C/C++ weird promotion rules. In the first example two equal sized signed and unsigned types are compared. Prior to the comparison the signed value is promoted to unsigned which makes the less than comparison false. In the second example the type on the right-hand side is smaller. Integer promotion kicks in and promotes the `uint16_t` to `int32_t`. As a result the comparison yields true.
  ```cpp
  static_assert((int32_t)-1 < (uint32_t)1 == false);
  static_assert((int32_t)-1 < (uint16_t)1 == true);
  ```

- Do not use C-style casts unless it really helps readability.

- Using storage variables with fixed width (e.g. `uint8_t`, `int16_t`) will trigger a lot (yeah, srsly, a huge fucking pile) of -Wconversion warnings when doing pretty much ANYTHING. Using `static_cast` silents those warnings but make sure to use it as locally as possible.

- Use unsigned fixed with types for registers and bitmasks.

- In succession direct memory pointers are solely `uint8_t*`, `uint16_t*` and `uint32_t*`. There is no such thing as a `size_t*`. Treat it as if you wouldn't know what size `size_t` actually is.

- Use `size_t` for indexing, counting and "memory-related" quantities. This also applies if referring to one of multiple arbitrary unitless things e.g. an ADC channel or external interrupt line. An ADC offset on the other hand is a value and rather `uint32_t` than `size_t`.

- Use the "goto" operator if you need a decrementing loop till zero.
  ```cpp
  array<char const*, 42u> str_array;
  for (auto i{size(str_array)}; i-- > 0uz;)
    cout << i << "\n";
  ```

- Prefer an integer suffix over a `static_cast` (e.g. `42u` or `42ul`). C++23 also has a `size_t` suffix (zu).

- Do not prefix getters and setters for no compelling reason. Rather use an overload which differs by arguments.

- Use a leading underscore for member variables for non-[PODs](https://en.cppreference.com/w/cpp/named_req/PODType).

- Do not use the assignment operator for initialization, use braced initialization instead.

- Prefer anonymous namespaces over static in source files.

- When using them though make sure that names wouldn't clash when doing a unity build.

- Care about const-corectness. When passing by pointer or reference, pass immutable objects with const qualifier. Declare local variables as const if possible. An exception from this rule is passing objects by value. Do not pass by const value as this prevents moving things. Also pretty much nobody does this... so don't be weird.

- Prefer the portable C++11 `[[attr]]` attribute syntax over `__attribute___`.

- Declarations should also have named parameters.
  ```cpp
  void foo(int value);
  ```

- Prefer concepts and requires clauses over `static_assert`.

- Prefer `static_assert` if the error otherwise produces would be that of an incomplete type. An example of this can often be found in type traits. Consider the following snippet which gets the index of a type in a type list. Using a requires clause and not meeting requirements produces the error `invalid use of incomplete type`.
  ```cpp
  template<typename...>
  struct index_type_impl;

  template<size_t... Is, typename T, typename... Ts>
  requires(count_type_v<T, Ts...> ==
           1u) struct index_type_impl<std::index_sequence<Is...>, T, Ts...>
    : detail::count_type_impl<(std::same_as<T, Ts> ? Is : 0uz)...> {
  };
  ```

  Using a `static_assert` on the other hand points us to the error.
  ```cpp
  template<size_t... Is, typename T, typename... Ts>
  struct index_type_impl<std::index_sequence<Is...>, T, Ts...>
    : detail::count_type_impl<(std::same_as<T, Ts> ? Is : 0uz)...> {
    static_assert(count_type_v<T, Ts...> == 1u);
  };
  ```  

- Prefer constrained template parameters over requires clauses whenever possible.
  ```cpp
  // Constrained template parameter
  template<std::integral T>
  struct S{};

  // Requires clauses
  template<typename T>
  requires std::integral<T>
  struct X {};
  ```

- Prefer requires clauses after function declarations over requires clauses after template parameter lists. This makes their use consistent between free template functions and methods inside template classes.
  ```cpp
  // Requires clauses after function declarations (free template function)
  template <typename T>
  void foo(T t) requires std::integral<T> || std::floating_point<T> {}

  // Requires clauses after function declarations (method of templateds class)
  template <typename T>
  struct T {
    void foo(T t) requires std::integral<T> || std::floating_point<T> {}
  };

  // Requires clauses after template parameter lists
  template <typename T>
  requires std::integral<T> || std::floating_point<T>
  void foo(T t) {}
  ```

- Use constexpr variables whenever possible.

- constexpr variables with function scope should be static. Otherwise they are put on the stack. In case of constexpr functions put the variables outside of the function scope (e.g. as inline constexpr in a surrounding "detail" namespace).

- Use consteval functions whenever possible. This ensures that the function is solely used at compile time.