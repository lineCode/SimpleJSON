#ifndef JSS_BIDIRECTIONAL_H_INCLUDED
#define JSS_BIDIRECTIONAL_H_INCLUDED

#include "jss_core.hpp"
#include "container_traits.hpp"
#include "jss_object.hpp"
#include "jss_container.hpp"

namespace JSON
{
    template <typename T, template <typename, class = std::allocator <T> > class ContainerT,
              class = typename std::enable_if<Internal::can_stringify<typename ContainerT<T>::value_type>::value>::type >
    std::ostream& stringify (std::ostream& stream, std::string const& name, ContainerT <T> values, StringificationOptions const& options = DEFAULT_OPTIONS,
                             typename std::enable_if<has_bidirectional_iterator<T, ContainerT>::value>::type* = nullptr)
    {
        Internal::stringify_i(stream, name, values, options);
        return stream;
    }
}

#endif // JSS_BIDIRECTIONAL_H_INCLUDED
