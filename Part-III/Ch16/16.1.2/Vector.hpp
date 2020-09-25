#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <utility>
#include <algorithm>
#include <iterator>

template <typename T, typename Allocator = std::allocator<T>>
class Vector
{
public:
    using value_type             = T;
    using allocator_type         = Allocator;
    using size_type              = std::size_t;
    using difference_type        = std::ptrdiff_t;
    using reference              = T&;
    using const_reference        = const T&;
    using pointer                = typename std::allocator_traits<Allocator>::pointer;
    using const_pointer          = typename std::allocator_traits<Allocator>::const_pointer;
    using iterator               = T*;
    using const_iterator         = const T*;
    using reverse_iterator       = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

public:
    // Default constructor. Constructs an empty container with a default-constructed allocator.
    constexpr Vector() noexcept(noexcept(Allocator()));
    // Constructs an empty container with the given allocator alloc.
    constexpr explicit Vector( const Allocator &alloc ) noexcept;
    // Constructs the container with count copies of elements with value value.
    constexpr Vector( size_type count,
                      const T &value,
                      const Allocator &alloc = Allocator() );
    // Constructs the container with count default-inserted instances of T. No copies are made.
    constexpr explicit Vector( size_type count,
                               const Allocator &alloc = Allocator() );
    // Constructs the container with the contents of the range [first, last).
    template <typename InputIt>
    constexpr Vector( InputIt first, InputIt last,
                      const Allocator &alloc = Allocator() );
    // Copy constructor. Construts the container with the copy of the contents of other, the allocator is obtained as if
    // by calling `std::allocator_traits<allocator_type>::select_on_container_copy_construction(other.get_allocator())`
    constexpr Vector( const Vector &other );
    // Constructs the container with the copy of the contents of other, using alloc as the allocator.
    constexpr Vector( const vector &other, const Allocator &alloc );
    // Move constructor. Construtts the container with the contents of other using move semantics. Allocator is
    // obtained by move-construction from the allocator belonging to other. After the move, other is guaranteed to
    // be empty().
    constexpr Vector( Vector &&other ) noexcept;
    constexpr ~Vector();

private:
    T *elements;
    T *first_free;
    T *capacity;
};

#endif